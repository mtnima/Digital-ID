package com.digitalid.mauritania.viewmodel;

import static com.digitalid.mauritania.utils.Utils.writeFile;

import android.app.Application;
import android.util.Base64;
import android.util.Log;

import androidx.annotation.NonNull;
import androidx.lifecycle.AndroidViewModel;
import androidx.lifecycle.LiveData;
import androidx.lifecycle.MutableLiveData;

import com.digitalid.mauritania.R;
import com.digitalid.mauritania.models.GetCryptographRequest;
import com.digitalid.mauritania.models.GetCryptographResponse;
import com.digitalid.mauritania.models.RegistrationRequest;
import com.digitalid.mauritania.models.RegistrationResponse;
import com.digitalid.mauritania.network.MauritaniaApiService;
import com.digitalid.mauritania.network.ServiceGenerator;
import com.digitalid.mauritania.utils.Constants;
import com.digitalid.mauritania.utils.CryptographUtil;
import com.digitalid.mauritania.utils.LoginSharedPreferences;
import com.digitalid.mauritania.utils.UiText;
import com.google.gson.Gson;
import com.google.protobuf.ByteString;
import com.google.protobuf.InvalidProtocolBufferException;

import java.io.File;
import java.io.IOException;
import java.security.GeneralSecurityException;

import Tech5.OmniMatch.AuthMatcher;
import Tech5.OmniMatch.BioCommon;
import Tech5.OmniMatch.Common;
import Tech5.OmniMatch.JNI.Matchers.AuthMatcherInstance;
import Tech5.OmniMatch.JNI.Matchers.AuthMatcherNative;
import Tech5.OmniMatch.JNI.OmniMatchException;
import Tech5.OmniMatch.JNI.TemplateCreators.TemplateCreatorNNInstance;
import Tech5.OmniMatch.JNI.TemplateCreators.TemplateCreatorNNNative;
import Tech5.OmniMatch.MatcherCommon;
import Tech5.OmniMatch.TemplateCreatorCommon;
import retrofit2.Call;
import retrofit2.Callback;
import retrofit2.Response;

public class BioMetricMatchViewModel extends AndroidViewModel {


    private final MutableLiveData<Boolean> isProcessing = new MutableLiveData<>();
    private final MutableLiveData<MatcherCommon.RecordResult> matchResult = new MutableLiveData<>();


    private final MutableLiveData<RegistrationResponse> signupResponse = new MutableLiveData<>();
    private final MutableLiveData<UiText> errorMessage = new MutableLiveData<>();
    private final MutableLiveData<UiText> statusMessage = new MutableLiveData<>();

    private final MutableLiveData<Boolean> isCryptoCreated = new MutableLiveData<>();


    private byte[] templateToBeEnrolled;

    private byte[] faceImageTobeSaved;


    private TemplateCreatorNNNative templateCreatorNNNative = null;
    private TemplateCreatorNNInstance templateCreatorNNFaceLightInstance = null;
    private AuthMatcherInstance authMatcherInstance = null;
    private AuthMatcherNative authMatcherNative = null;

    private final Application application;

    private LoginSharedPreferences appSharedPreference = null;

    private CryptographUtil cryptographUtil;


    public BioMetricMatchViewModel(@NonNull Application application) throws OmniMatchException {

        super(application);

        this.application = application;

        try {
            appSharedPreference = new LoginSharedPreferences(application);
        } catch (GeneralSecurityException | IOException e) {
            Log.d("TAG", "Unable to create sharedprefs");
        }


    }

    public void init(TemplateCreatorNNNative templateCreatorNNNative, TemplateCreatorNNInstance templateCreatorNNFaceLightInstance,
                     AuthMatcherNative authMatcherNative, AuthMatcherInstance authMatcherInstance, CryptographUtil cryptographUtil) {

        this.templateCreatorNNNative = templateCreatorNNNative;
        this.templateCreatorNNFaceLightInstance = templateCreatorNNFaceLightInstance;
        this.authMatcherInstance = authMatcherInstance;
        this.authMatcherNative = authMatcherNative;
        this.cryptographUtil = cryptographUtil;


    }


    public LiveData<UiText> getErrorMessage() {
        return errorMessage;
    }

    public LiveData<UiText> getStatusMessage() {
        return statusMessage;
    }

    public LiveData<Boolean> getCryptoStatus() {
        return isCryptoCreated;
    }

    public LiveData<MatcherCommon.RecordResult> getMatchResult() {
        return matchResult;
    }

    public LiveData<RegistrationResponse> getRegistrationResponse() {
        return signupResponse;
    }

    public LiveData<Boolean> isProcessing() {

        return isProcessing;
    }

    public void matchFaceImages(byte[] extractedFaceImage, byte[] liveFaceImage, Common.ImageFormat imageFormat) {


        new Thread(() -> {

            statusMessage.postValue(UiText.stringResource(R.string.matching_faces));


            isProcessing.postValue(true);


            faceImageTobeSaved = extractedFaceImage;

            try {


                byte[] template1 = createTemplate(extractedFaceImage, imageFormat);

                byte[] template2 = createTemplate(liveFaceImage, imageFormat);

                if (template1 != null && template1.length > 0) {
                    templateToBeEnrolled = template1;
                }

                Log.d("TAG", "template 1 size : " + template1.length);
                Log.d("TAG", "template 2 size : " + template2.length);


                if (template1.length > 0 && template2.length > 0) {
                    MatcherCommon.RecordResult recordResult = matchFaceTemplates(template1, template2);


                    statusMessage.postValue(UiText.emptyString());
                    isProcessing.postValue(false);

                    matchResult.postValue(recordResult);

                } else {
                    errorMessage.postValue(UiText.stringResource(R.string.error_in_template_creation));
                    isProcessing.postValue(false);
                }

            } catch (OmniMatchException | IOException e) {
                errorMessage.postValue(UiText.stringResource(R.string.error_in_matching, e.getLocalizedMessage()));
                isProcessing.postValue(false);

            }


        }).start();


    }


    public void matchFaceImageAndTemplate(byte[] template, byte[] liveFaceImage, Common.ImageFormat imageFormat) {


        new Thread(() -> {

            statusMessage.postValue(UiText.stringResource(R.string.matching_faces));
            isProcessing.postValue(true);


            faceImageTobeSaved = liveFaceImage;

            try {


                byte[] template2 = createTemplate(liveFaceImage, imageFormat);


                Log.d("TAG", "template 2 size : " + template2.length);

                if (template != null && template2.length > 0) {
                    MatcherCommon.RecordResult recordResult = matchFaceTemplates(template, template2);


                    statusMessage.postValue(UiText.emptyString());
                    isProcessing.postValue(false);
                    matchResult.postValue(recordResult);

                } else {

                    statusMessage.postValue(UiText.stringResource(R.string.error_in_template_creation));
                    isProcessing.postValue(false);
                }

            } catch (OmniMatchException | IOException e) {
                statusMessage.postValue(UiText.stringResource(R.string.error_in_matching, e.getLocalizedMessage()));
                isProcessing.postValue(false);

            }


        }).start();


    }

    public void createCryptograph(String pin, String firstName, String lastName, String birthDate) {

        //create cryptograph
        //save cryptograph to internal storage
        //save face image to internal
        //save cryptograph creation status, face image path and crypto image path to shared prefs

        isProcessing.postValue(true);
        statusMessage.postValue(UiText.stringResource(R.string.creating_eid));


        MauritaniaApiService getDataService = ServiceGenerator.createService(MauritaniaApiService.class, Constants.KEY, Constants.VA_3_Z_YA_3_Q_4_RDR);


        GetCryptographRequest request = new GetCryptographRequest();
        request.setPin(pin);
        request.setBirthDate(birthDate);
        request.setFirstName(firstName);
        request.setLastName(lastName);

        byte[] base64EncodedTemplate = Base64.encode(templateToBeEnrolled, Base64.NO_WRAP);

        Log.d("TAG", "base64EncodedTemplate :" + new String(base64EncodedTemplate));
        request.setFaceTemplate(new String(base64EncodedTemplate));

        Log.d("TAG", "template size: " + templateToBeEnrolled.length);
        Log.d("TAG", "request: " + new Gson().toJson(request));


        Call<GetCryptographResponse> call = getDataService.createCryptograph(request);

        call.enqueue(new Callback<GetCryptographResponse>() {
            @Override
            public void onResponse(Call<GetCryptographResponse> call, Response<GetCryptographResponse> response) {

                statusMessage.postValue(UiText.emptyString());

                if (response.isSuccessful() && response.code() == 200) {

                    GetCryptographResponse cryptographResponse = response.body();

                    Log.d("TAG", "response : " + new Gson().toJson(cryptographResponse));


                    isProcessing.postValue(false);

                    saveCryptoImageToDisk(cryptographResponse.getImage());

                } else {
                    Log.d("TAG", "error " + response.code());

                    Log.d("TAG", "error " + response.errorBody());

                    saveCryptoImageToDisk(null);
                }

            }

            @Override
            public void onFailure(Call<GetCryptographResponse> call, Throwable t) {

                statusMessage.postValue(UiText.emptyString());



                errorMessage.postValue(UiText.stringResource(R.string.error_in_mauritania_creation , t.getLocalizedMessage()));

                isProcessing.postValue(false);

            }
        });


    }

    private byte[] encryptCryptoImage(String cryptoImage) {

        byte[] cryptoBytes;
        try {


            cryptoBytes = cryptographUtil.encrypt(Base64.decode(cryptoImage, Base64.NO_WRAP));


        } catch (Exception e) {

            cryptoBytes = Base64.decode(cryptoImage, Base64.NO_WRAP);

        }

        return cryptoBytes;
    }

    private void saveCryptoImageToDisk(String cryptoImage) {

        new Thread(() -> {

            isProcessing.postValue(true);
            statusMessage.postValue(UiText.stringResource(R.string.saving_images));

            try {


                String cryptoImagePath = null;


                if (cryptoImage != null) {

                    byte[] cryptoBytes = encryptCryptoImage(cryptoImage);

                    cryptoImagePath = application.getFilesDir() + File.separator + Constants.STORAGE_DIRECTORY + File.separator + Constants.CRYPTOGRAPH_IMAGE_NAME;
                    writeFile(cryptoBytes, cryptoImagePath);
                }


                String faceImagePath = application.getFilesDir() + File.separator + Constants.STORAGE_DIRECTORY + File.separator + Constants.FACE_IMAGE_NAME;
                writeFile(faceImageTobeSaved, faceImagePath);

                Log.d("TAG", "encrypted cryptograph saved to " + cryptoImagePath);
                Log.d("TAG", "face image saved to " + faceImagePath);

                isCryptoCreated.postValue(true);

                appSharedPreference.setFaceImagePath(faceImagePath);

            } catch (Exception e) {
                isCryptoCreated.postValue(false);
                errorMessage.postValue(UiText.stringResource(R.string.failed_to_save_eid));
            }


            isProcessing.postValue(false);

        }).start();


    }


    private byte[] createTemplate(byte[] face, Common.ImageFormat imageFormat) throws OmniMatchException, InvalidProtocolBufferException {


        if (templateCreatorNNFaceLightInstance == null) {
            return new byte[0];
        }


        Common.Image faceImage = Common.Image.newBuilder().setBytes(ByteString.copyFrom(face)).setFormat(imageFormat).build();

        TemplateCreatorCommon.CreateTemplateRequest createTemplateRequest = TemplateCreatorCommon.CreateTemplateRequest.newBuilder().addImages(faceImage).setDoSegmentation(false).build();
        TemplateCreatorCommon.CreateTemplateResponse createTemplateResponse = templateCreatorNNNative.CreateTemplate(templateCreatorNNFaceLightInstance, createTemplateRequest);

        if ((createTemplateResponse.getResultCode() == Common.ResultCode.Success) && (createTemplateResponse.getResultsCount() == 1)) {
            return createTemplateResponse.getResults(0).getTemplateResult().getTemplate().getData().toByteArray();
        }


        return new byte[0];
    }


    public MatcherCommon.RecordResult matchFaceTemplates(byte[] template1, byte[] template2) throws OmniMatchException, IOException {
        ByteString faceTemplate1 = ByteString.copyFrom(template1);
        ByteString faceTemplate2 = ByteString.copyFrom(template2);

        AuthMatcher.AuthVerifyRecordRequest authVerifyRecordRequest = AuthMatcher.AuthVerifyRecordRequest.newBuilder().setReferenceRecord(MatcherCommon.Record.newBuilder().setFace(BioCommon.MatcherTemplate.newBuilder().setTemplateData(BioCommon.Template.newBuilder().setData(faceTemplate1).setQuality(100).build()).build()).build()).setCapturedRecord(MatcherCommon.Record.newBuilder().setFace(BioCommon.MatcherTemplate.newBuilder().setTemplateData(BioCommon.Template.newBuilder().setData(faceTemplate2).setQuality(100).build()).build()).build()).setVerifyMode(MatcherCommon.VerifyMode.NN_ONLY).build();
        return authMatcherNative.VerifyRecord(authMatcherInstance, authVerifyRecordRequest);


    }


    public void registerUser(String pin, String firstName, String lastName, String birthDate) {

        isProcessing.postValue(true);
        statusMessage.postValue(UiText.stringResource(R.string.registering_user));

        RegistrationRequest registrationRequest = new RegistrationRequest();
        registrationRequest.setPin(pin);
        registrationRequest.setFirstName(firstName);
        registrationRequest.setLastName(lastName);
        registrationRequest.setBirthDate(birthDate);


        MauritaniaApiService getDataService = ServiceGenerator.createService(MauritaniaApiService.class, Constants.KEY, Constants.VA_3_Z_YA_3_Q_4_RDR);
        Call<RegistrationResponse> call = getDataService.registerUser(registrationRequest);


        call.enqueue(new Callback<RegistrationResponse>() {
            @Override
            public void onResponse(Call<RegistrationResponse> call, Response<RegistrationResponse> response) {

                statusMessage.postValue(UiText.emptyString());
                isProcessing.postValue(false);

                if (response.isSuccessful()) {

                    signupResponse.postValue(response.body());

                }

            }

            @Override
            public void onFailure(Call<RegistrationResponse> call, Throwable t) {


                Log.e("TAG", t.getLocalizedMessage());

                statusMessage.postValue(UiText.stringResource(R.string.registartion_failed));
                isProcessing.postValue(false);
                signupResponse.postValue(null);

            }
        });


    }
}
