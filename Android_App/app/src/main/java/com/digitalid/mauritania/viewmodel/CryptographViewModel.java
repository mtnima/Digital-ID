package com.digitalid.mauritania.viewmodel;

import static com.digitalid.mauritania.utils.Utils.readFileFromAssets;

import android.app.Application;
import android.util.Base64;
import android.util.Log;

import androidx.annotation.NonNull;
import androidx.lifecycle.AndroidViewModel;
import androidx.lifecycle.LiveData;
import androidx.lifecycle.MutableLiveData;

import com.digitalid.mauritania.R;
import com.digitalid.mauritania.tlvdecoder.ITLVRecord;
import com.digitalid.mauritania.tlvdecoder.TLVDecoderImplementation;
import com.digitalid.mauritania.utils.Constants;
import com.digitalid.mauritania.utils.CryptographUtil;
import com.digitalid.mauritania.utils.SignatureVerification;
import com.digitalid.mauritania.utils.UiText;
import com.digitalid.mauritania.utils.Utils;

import java.io.File;
import java.io.IOException;
import java.security.InvalidAlgorithmParameterException;
import java.security.InvalidKeyException;
import java.security.NoSuchAlgorithmException;
import java.security.SignatureException;
import java.security.spec.InvalidKeySpecException;
import java.util.Collections;
import java.util.List;

import javax.crypto.BadPaddingException;
import javax.crypto.IllegalBlockSizeException;
import javax.crypto.NoSuchPaddingException;

import ai.tech5.sdk.abis.cryptograph.T5CryptoClient;

public class CryptographViewModel extends AndroidViewModel {


    private final MutableLiveData<Boolean> isProcessing = new MutableLiveData<>();

    private final MutableLiveData<UiText> statusMessage = new MutableLiveData<>();

    private final MutableLiveData<Boolean> isSignatureVerified = new MutableLiveData<>();

    private final MutableLiveData<UiText> errorMessage = new MutableLiveData<>();


    private final MutableLiveData<String> faceTemplateLiveData = new MutableLiveData<>();

    private T5CryptoClient t5CryptoClient;

    TLVDecoderImplementation tlvDecoderImplementation = null;

    CryptographUtil cryptographUtil;
    private final Application application;

    private static final String UNIQUE_ID = null;


    public LiveData<UiText> getStatusMessage() {
        return statusMessage;
    }

    public LiveData<Boolean> isSignatureValidated() {
        return isSignatureVerified;
    }

    public LiveData<Boolean> isProcessing() {

        return isProcessing;
    }


    public LiveData<String> getFaceTemplate() {

        return faceTemplateLiveData;
    }

    public LiveData<UiText> getErrorMessage() {
        return errorMessage;
    }


    public CryptographViewModel(@NonNull Application application) {
        super(application);
        this.application = application;

    }


    public void init(CryptographUtil cryptographUtil) {

        this.cryptographUtil = cryptographUtil;
        tlvDecoderImplementation = new TLVDecoderImplementation();
    }


    public void validateCryptographSignature(String rsaPublicKey, String data) {

        isProcessing.postValue(true);
        statusMessage.postValue(UiText.stringResource(R.string.validating_eid));


        new Thread(() -> {

            try {
                // commented

                boolean isValidated = validateSignature(rsaPublicKey, data);
                isSignatureVerified.postValue(isValidated);

            } catch (Exception e) {

                isSignatureVerified.postValue(false);
                errorMessage.postValue(UiText.stringResource(R.string.signature_verification_failed));

                Log.e("TAG", "signature validation failed : " + e.getLocalizedMessage());

            }


        }).start();


    }

    private boolean validateSignature(String rsaPublicKey, String data) throws InvalidAlgorithmParameterException, NoSuchAlgorithmException, IOException,
            NoSuchPaddingException, IllegalBlockSizeException, BadPaddingException, InvalidKeyException, InvalidKeySpecException, SignatureException {

        boolean isSignatureValidated = false;


        String cryptographPath = application.getFilesDir() + File.separator + Constants.STORAGE_DIRECTORY + File.separator + Constants.CRYPTOGRAPH_IMAGE_NAME;

        File cryptoFile = new File(cryptographPath);
        if (cryptoFile.exists()) {

            byte[] encryptedCryptographBytes = Utils.readFileBytes(cryptographPath);


            byte[] cryptographBytes = cryptographUtil.decrypt(encryptedCryptographBytes);


            List<ITLVRecord> tlvRecords = decodeBarcodeImage(cryptographBytes);

            byte[] signature = getSignatureData(tlvRecords);

            if (signature != null && signature.length > 0) {

                SignatureVerification signatureVerification = new SignatureVerification();
                isSignatureValidated = signatureVerification.validateSignature(rsaPublicKey, signature, data);

            }


        }


        return isSignatureValidated;
    }

    private byte[] getSignatureData(List<ITLVRecord> tlvRecords) {

        if (tlvRecords == null || tlvRecords.isEmpty()) {
            return new byte[0];
        }

        byte[] signature = null;

        for (ITLVRecord itlvRecord : tlvRecords) {

            if (itlvRecord.getType() == ITLVRecord.IDEncodeFieldType.DIGITAL_CERTIFICATE) {

                Log.d("TAG", "signature length : " + itlvRecord.getData().length);

                signature = itlvRecord.getData();
                break;

            }

        }

        return signature;

    }


    private byte[] getFaceTemplate(List<ITLVRecord> tlvRecords) {

        if (tlvRecords == null || tlvRecords.isEmpty()) {
            return new byte[0];
        }

        byte[] faceTemplate = null;

        for (ITLVRecord itlvRecord : tlvRecords) {

            if (itlvRecord.getType() == ITLVRecord.IDEncodeFieldType.FACE_TEMPLATE) {

                faceTemplate = itlvRecord.getData();
                break;

            }

        }


        return faceTemplate;

    }


    public void getTemplateFromStoredCryptograph() {


        isProcessing.postValue(true);
        statusMessage.postValue(UiText.stringResource(R.string.retrieving_template));


        new Thread(() -> {


            byte[] faceTemplate = getTemplateFromCryptograph();

            if (faceTemplate.length > 0) {

                faceTemplateLiveData.postValue(Base64.encodeToString(faceTemplate, Base64.NO_WRAP));

                isProcessing.postValue(false);
                statusMessage.postValue(UiText.emptyString());
            } else {
                faceTemplateLiveData.postValue(null);

                isProcessing.postValue(false);
                statusMessage.postValue(UiText.stringResource(R.string.retrieve_face_template_failed));
            }


        }).start();


    }


    private byte[] getTemplateFromCryptograph() {


        try {

            String cryptographPath = application.getFilesDir() + File.separator + Constants.STORAGE_DIRECTORY + File.separator + Constants.CRYPTOGRAPH_IMAGE_NAME;

            File cryptoFile = new File(cryptographPath);
            if (cryptoFile.exists()) {

                byte[] encryptedCryptographBytes = Utils.readFileBytes(cryptographPath);


                byte[] cryptographBytes = cryptographUtil.decrypt(encryptedCryptographBytes);


                List<ITLVRecord> tlvRecords = decodeBarcodeImage(cryptographBytes);

                Log.d("TAG", "tlvRecords :" + tlvRecords);

                return getFaceTemplate(tlvRecords);


            }


        } catch (Exception e) {

            Log.d("TAG", "Error in get template from crypto: " + e.getLocalizedMessage());

        }

        return new byte[0];
    }


    @SuppressWarnings({"java:S2129", "java:S1874", "java:S5738"})
    private List<ITLVRecord> decodeBarcodeImage(byte[] imageBarcode) throws IOException {


        int errorCode = 0;

        if (t5CryptoClient == null) {
            byte[] keyData = readFileFromAssets(application.getAssets(), "encryptionKey.txt");
            t5CryptoClient = new T5CryptoClient(application.getApplicationContext());
            errorCode = t5CryptoClient.create(keyData);
            Log.d("TAg", "create  eeror code :" + errorCode);
            if (errorCode != 0) {

                return Collections.emptyList();
            }


            t5CryptoClient.getVersion();
        }


        Integer decodedDataSize = new Integer(0);
        Integer errorFailingToDecode = new Integer(0);
        errorCode = t5CryptoClient.decode(imageBarcode, UNIQUE_ID, null, decodedDataSize, errorFailingToDecode);
        Log.d("TAg", "decode 1 eror code :" + errorCode);

        if (errorCode == 0) {
            byte[] decodedData = new byte[decodedDataSize];
            errorCode = t5CryptoClient.decode(imageBarcode, UNIQUE_ID, decodedData, decodedDataSize, errorFailingToDecode);
            Log.d("TAg", "decode 2 eror code :" + errorCode);
            Log.d("TAg", "decoded data size  :" + decodedDataSize);
            if (errorCode == 0) {
                try {


                    return tlvDecoderImplementation.decode(decodedData);


                } catch (Exception e) {

                    return Collections.emptyList();

                }

            }


        }


        return Collections.emptyList();
    }


    @Override
    protected void onCleared() {
        super.onCleared();

        if (t5CryptoClient != null) {
            t5CryptoClient.cancel();
        }

    }
}
