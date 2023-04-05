package com.digitalid.mauritania.viewmodel;

import android.app.Application;
import android.content.Context;
import android.content.ContextWrapper;
import android.graphics.Bitmap;
import android.net.ConnectivityManager;
import android.net.Network;
import android.net.NetworkCapabilities;
import android.util.Log;

import androidx.annotation.NonNull;
import androidx.annotation.Nullable;
import androidx.lifecycle.AndroidViewModel;
import androidx.lifecycle.LiveData;
import androidx.lifecycle.MutableLiveData;

import com.digitalid.mauritania.R;
import com.digitalid.mauritania.models.Demographics;
import com.digitalid.mauritania.models.GetPublicKeyResponse;
import com.digitalid.mauritania.network.MauritaniaApiService;
import com.digitalid.mauritania.network.ServiceGenerator;
import com.digitalid.mauritania.utils.Constants;
import com.digitalid.mauritania.utils.CryptographUtil;
import com.digitalid.mauritania.utils.UiText;
import com.regula.documentreader.api.DocumentReader;
import com.regula.documentreader.api.completions.IDocumentReaderPrepareCompletion;
import com.regula.documentreader.api.enums.Scenario;
import com.regula.documentreader.api.errors.DocumentReaderException;
import com.regula.documentreader.api.params.DocReaderConfig;

import java.io.BufferedInputStream;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.net.HttpURLConnection;
import java.net.URL;

import Tech5.OmniMatch.AuthMatcher;
import Tech5.OmniMatch.BioCommon;
import Tech5.OmniMatch.Common;
import Tech5.OmniMatch.FaceCommon;
import Tech5.OmniMatch.JNI.Android.AndroidNative;
import Tech5.OmniMatch.JNI.CoreNative;
import Tech5.OmniMatch.JNI.Matchers.AuthMatcherInstance;
import Tech5.OmniMatch.JNI.Matchers.AuthMatcherNative;
import Tech5.OmniMatch.JNI.OmniMatchException;
import Tech5.OmniMatch.JNI.TemplateCreators.TemplateCreatorNNInstance;
import Tech5.OmniMatch.JNI.TemplateCreators.TemplateCreatorNNNative;
import Tech5.OmniMatch.TemplateCreatorNn;
import retrofit2.Call;
import retrofit2.Callback;
import retrofit2.Response;

public class SharedViewModel extends AndroidViewModel {

    private static final String TAG = SharedViewModel.class.getSimpleName();


    private final Application application;
    private final MutableLiveData<Boolean> isSDKInitialized = new MutableLiveData<>();

    private final MutableLiveData<Boolean> isOCRDbDownloaded = new MutableLiveData<>();
    private final MutableLiveData<Boolean> isOCRSDKInitialized = new MutableLiveData<>();


    private final MutableLiveData<Boolean> isLoadingSDK = new MutableLiveData<>();



    private final MutableLiveData<UiText> status = new MutableLiveData<>();

    private final MutableLiveData<String> rsaPublicKey = new MutableLiveData<>();


    private TemplateCreatorNNNative templateCreatorNNNative = null;
    private TemplateCreatorNNInstance templateCreatorNNFaceLightInstance = null;
    private AuthMatcherInstance authMatcherInstance = null;
    private AuthMatcherNative authMatcherNative = null;


    private boolean hasNfcPage = false;
    private Demographics demographics;
    private Bitmap extractedFaceImageFromNfc = null;
    private Bitmap extractedFaceImageFromOcr = null;
    private byte[] liveFaceImage = null;

    private String qrcodeContent = null;

    public CryptographUtil getCryptographUtil() {
        return cryptographUtil;
    }

    private CryptographUtil cryptographUtil;


    public String getQrcodeContent() {
        return qrcodeContent;
    }

    public void setQrcodeContent(String qrcodeContent) {
        this.qrcodeContent = qrcodeContent;
    }

    public SharedViewModel(@NonNull Application application) {
        super(application);
        this.application = application;
        Log.d(TAG, "SharedViewModel constructor() " + this);

        try {
            cryptographUtil = new CryptographUtil(Constants.KEY_STORE_ALIAS);
        } catch (Exception e) {
            Log.d(TAG, "error " + e.getLocalizedMessage());
        }
    }


    public LiveData<Boolean> isSDKInitialized() {
        return isSDKInitialized;
    }

    public LiveData<Boolean> isSDkLoading() {

        return isLoadingSDK;
    }

    public LiveData<Boolean> isOCRSDKInitialized() {
        return isOCRSDKInitialized;
    }

    public LiveData<Boolean> isOCRDbDownloaded() {
        return isOCRDbDownloaded;
    }

    public LiveData<UiText> getStatus() {
        return status;
    }

    public LiveData<String> rsaPublicKey() {
        return rsaPublicKey;
    }


    public boolean hasNfcPage() {
        return hasNfcPage;
    }

    public void setHasNfcPage(boolean hasNfcPage) {
        this.hasNfcPage = hasNfcPage;
    }


    public void setDemographics(Demographics demographics) {
        this.demographics = demographics;
    }

    public Demographics getDemographics() {
        return demographics;
    }


    public Bitmap getExtractedFaceImageFromNfc() {
        return extractedFaceImageFromNfc;
    }

    public void setExtractedFaceImageFromNfc(Bitmap extractedFaceImage) {
        this.extractedFaceImageFromNfc = extractedFaceImage;
    }


    public Bitmap getExtractedFaceImageFromOCR() {
        return extractedFaceImageFromOcr;
    }

    public void setExtractedFaceImageFromOcr(Bitmap extractedFaceImage) {
        this.extractedFaceImageFromOcr = extractedFaceImage;
    }

    public byte[] getLiveFaceImage() {
        return liveFaceImage;
    }

    public void setLiveFaceImage(byte[] liveFaceImage) {
        this.liveFaceImage = liveFaceImage;
    }


    public void initSDK(Context context) {


        Log.d("TAG", "is instance of ContextWrapper : " + (context instanceof ContextWrapper));
        Log.d("TAG", "is instance of andoid.app.Context : " + (context instanceof Context));


        Log.d("TAG", "app is instance of ContextWrapper : " + (application.getApplicationContext() instanceof ContextWrapper));
        Log.d("TAG", "app is instance of andoid.app.Context : " + (application.getApplicationContext() instanceof Context));



        new Thread(() -> {


            isLoadingSDK.postValue(true);
            isSDKInitialized.postValue(false);
            status.postValue(UiText.stringResource(R.string.omnimatch_initializing));


            boolean isSDKInitilized = loadLicense(context);

            Log.d(TAG, "isSDKInitilized 1 :" + isSDKInitilized);

            if (isSDKInitilized) {

                isSDKInitilized = initOmniMatchInstances();

                Log.d(TAG, "isSDKInitilized 2 :" + isSDKInitilized);

            }


            isLoadingSDK.postValue(false);
            isSDKInitialized.postValue(isSDKInitilized);


        }).start();

    }


    public void prepareDatabase() {



        isLoadingSDK.postValue(true);

        status.postValue(UiText.emptyString());
        DocumentReader.Instance().runAutoUpdate(application, "Full", new IDocumentReaderPrepareCompletion() {
            @Override
            public void onPrepareProgressChanged(int progress) {
                // getting progress

                status.postValue(UiText.stringResource(R.string.downloading_ocr_database, progress));
            }

            @Override
            public void onPrepareCompleted(boolean b, @Nullable DocumentReaderException e) {

                isLoadingSDK.postValue(false);

                isOCRDbDownloaded.postValue(b);

                if (Boolean.TRUE.equals(b)) {
                    status.postValue(UiText.emptyString());
                } else {

                    String errorMessage = "";
                    if (e != null) {
                        errorMessage = e.getLocalizedMessage();
                    }

                    status.postValue(UiText.stringResource(R.string.download_ocr_db_failed, errorMessage));
                }

            }


        });

    }


    public void initRegulaSDK() {

        InputStream licInput = null;


        try {


            if (!DocumentReader.Instance().isReady()) {

                isLoadingSDK.postValue(true);

                status.postValue(UiText.stringResource(R.string.init_ocr));


                licInput = application.getApplicationContext().getResources().openRawResource(R.raw.regula);

                int available = licInput.available();
                final byte[] license = new byte[available];
                int readedBytes = licInput.read(license);

                Log.d("TAG", "readedBytes: " + readedBytes);


                DocReaderConfig config = new DocReaderConfig(license);
                config.setLicenseUpdate(true);


                Log.d("TAG", "isLicense update: " + config.isLicenseUpdate());

                //Initializing the reader
                DocumentReader.Instance().initializeReader(application.getApplicationContext(), config, (success, error) -> {


                    isLoadingSDK.postValue(false);


                    //initialization successful
                    if (success) {

                        Log.d("TAG","Regula Version : "+ DocumentReader.Instance().version);
                        Log.d("TAG","Regula status : "+ DocumentReader.Instance().getStatus());


                        onSuccessfulInit();


                        status.postValue(UiText.emptyString());

                        DocumentReader.Instance().processParams().scenario = Scenario.SCENARIO_FULL_PROCESS;

                        isOCRSDKInitialized.postValue(true);


                    }
                    //Initialization was not successful
                    else {

                        isOCRSDKInitialized.postValue(false);

                        String errorMessage = "";
                        if (error != null) {
                            errorMessage = error.getLocalizedMessage();
                        }

                        status.postValue(UiText.stringResource(R.string.init_ocr_failed, errorMessage));

                    }
                });


            } else {

                isOCRSDKInitialized.postValue(true);

                onSuccessfulInit();

            }

        } catch (Exception e) {

            status.postValue(UiText.stringResource(R.string.init_ocr_failed, e.getLocalizedMessage()));

        } finally {

            if (licInput != null) {
                try {
                    licInput.close();
                } catch (IOException e) {
                    Log.d("TAG", "error closing input stream : " + e.getLocalizedMessage());
                }
            }

        }
    }


    private void onSuccessfulInit() {

        DocumentReader.Instance().customization().edit().setShowHelpAnimation(false).apply();
        DocumentReader.Instance().rfidScenario().ePassportDataGroups().setDG14(false);

        DocumentReader.Instance().processParams().multipageProcessing = true;


    }


    private boolean initOmniMatchInstances() {

        try {


            templateCreatorNNNative = new TemplateCreatorNNNative();

            TemplateCreatorNn.TemplateCreatorNnConfiguration templateCreatorNnFaceLightConfiguration = TemplateCreatorNn.TemplateCreatorNnConfiguration.newBuilder().setAlgorithm(BioCommon.Algorithm.newBuilder().setFace(FaceCommon.FaceAlgorithm.DetFace_100Light)).setBase(Common.BaseConfiguration.newBuilder().setDebugMode(false).setThreadsNumber(1).build()).setBatch(Common.BatchConfiguration.newBuilder().setBatchSize(1).build()).setBioType(BioCommon.BioType.Face).build();
            templateCreatorNNFaceLightInstance = templateCreatorNNNative.CreateInstance(templateCreatorNnFaceLightConfiguration);


            authMatcherNative = new AuthMatcherNative();
            AuthMatcher.AuthMatcherConfiguration authMatcherConfiguration = AuthMatcher.AuthMatcherConfiguration.newBuilder().setAlgorithms(BioCommon.Algorithms.newBuilder().setFace(FaceCommon.FaceAlgorithm.DetFace_100Light).build()).setDebugMode(true).build();
            authMatcherInstance = authMatcherNative.CreateInstance(authMatcherConfiguration);

            return true;

        } catch (OmniMatchException ome) {


            Log.d(TAG, "templateCreatorNNNative : " + templateCreatorNNNative + " templateCreatorNNFaceLightInstance : " + templateCreatorNNFaceLightInstance);
            Log.d(TAG, "authMatcherNative : " + authMatcherNative + " authMatcherInstance : " + authMatcherInstance);


            Log.d("TAG", "unable to create templateCreatorNNFaceLightInstance " + ome.getResultCode());
        }

        return false;

    }


    private boolean loadLicense(Context context) {


        int resultCode;
        try {


            CoreNative coreNative = new CoreNative();


            Log.d("TAG", "version : " + coreNative.GetVersion().getValue());

            Log.d("TAG", "applicaton context : " + application.getApplicationContext());

            Log.d("TAG", " context : " + context);


            AndroidNative<Context> androidNative = new AndroidNative<>();


            resultCode = androidNative.SetLicense(context, "");
            Log.d("ATG", "set License result code " + resultCode);


            if (resultCode < 0) {


                String url = "https://pheonix-lic.tech5.tech/license/" + application.getApplicationContext().getPackageName() + "/" + Math.abs(resultCode);


                String token = sendHttpRequest(url);


                androidNative.SetLicense(context, token);
                resultCode = androidNative.SetLicense(context, token);

                Log.d("TAG", "token from server" + token);


                Log.d("ATG", "set License result code2 " + resultCode);

            }


        } catch (OmniMatchException | IOException ome) {

            resultCode = -1;

        }


        return (resultCode == 0);

    }


    private String sendHttpRequest(String urlString) throws IOException {

        HttpURLConnection urlConnection;
        StringBuilder result = new StringBuilder();

        URL url = new URL(urlString);
        urlConnection = (HttpURLConnection) url.openConnection();

        int code = urlConnection.getResponseCode();

        if (code == 200) {

            try (InputStream in = new BufferedInputStream(urlConnection.getInputStream());

                 BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(in))) {


                String line = "";

                while ((line = bufferedReader.readLine()) != null) result.append(line);

                return result.toString();
            } catch (IOException e) {
                Log.e(TAG, "error  " + e.getLocalizedMessage());

            }

        }


        return result.toString();

    }


    public void getRsaPublicKey() {

        isLoadingSDK.postValue(true);
        status.postValue(UiText.stringResource(R.string.retrieving_keys));


        MauritaniaApiService getDataService = ServiceGenerator.createService(MauritaniaApiService.class, Constants.KEY, Constants.VA_3_Z_YA_3_Q_4_RDR);
        Call<GetPublicKeyResponse> call = getDataService.getPublicKey();


        call.enqueue(new Callback<GetPublicKeyResponse>() {
            @Override
            public void onResponse(Call<GetPublicKeyResponse> call, Response<GetPublicKeyResponse> response) {


                isLoadingSDK.postValue(false);

                if (response.isSuccessful()) {
                    Log.d("TAG", "get rsa key  : " + response.isSuccessful());

                    Log.d("TAG", " rsa key  : " + response.body().toString());


                    rsaPublicKey.postValue(response.body().getPublicKey());
                } else {

                    Log.d("TAG", "error getting rsa key : " + response.code());
                }

            }

            @Override
            public void onFailure(Call<GetPublicKeyResponse> call, Throwable t) {


                Log.e("TAG", "error getting rsa key : " + t.getLocalizedMessage());

                status.postValue(UiText.stringResource(R.string.retrieving_keys_failed));
                isLoadingSDK.postValue(false);


            }
        });


    }


    public Boolean isNetworkAvailable() {
        ConnectivityManager connectivityManager = (ConnectivityManager) application.getSystemService(Context.CONNECTIVITY_SERVICE);


        Network nw = connectivityManager.getActiveNetwork();
        if (nw == null) return false;
        NetworkCapabilities actNw = connectivityManager.getNetworkCapabilities(nw);
        return actNw != null && (actNw.hasTransport(NetworkCapabilities.TRANSPORT_WIFI) || actNw.hasTransport(NetworkCapabilities.TRANSPORT_CELLULAR) || actNw.hasTransport(NetworkCapabilities.TRANSPORT_ETHERNET) || actNw.hasTransport(NetworkCapabilities.TRANSPORT_BLUETOOTH));

    }


    @Override
    protected void onCleared() {
        super.onCleared();

        Log.d(TAG, "sharedview model onCleared " + this);

        try {
            if (templateCreatorNNNative != null) {
                templateCreatorNNNative.DeleteInstance(templateCreatorNNFaceLightInstance);
            }

            if (authMatcherNative != null) {
                authMatcherNative.DeleteInstance(authMatcherInstance);
            }


        } catch (Exception e) {
            Log.d("TAG", "Unable to delete instances");
        }
    }


    public TemplateCreatorNNNative getTemplateCreatorNNNative() {
        return templateCreatorNNNative;
    }

    public TemplateCreatorNNInstance getTemplateCreatorNNFaceLightInstance() {
        return templateCreatorNNFaceLightInstance;
    }

    public AuthMatcherInstance getAuthMatcherInstance() {
        return authMatcherInstance;
    }

    public AuthMatcherNative getAuthMatcherNative() {
        return authMatcherNative;
    }


}
