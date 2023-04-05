package com.digitalid.mauritania.viewmodel;

import android.app.Application;
import android.util.Log;

import androidx.annotation.NonNull;
import androidx.lifecycle.AndroidViewModel;
import androidx.lifecycle.LiveData;
import androidx.lifecycle.MutableLiveData;

import com.digitalid.mauritania.R;
import com.digitalid.mauritania.models.QRLoginRequest;
import com.digitalid.mauritania.network.MauritaniaApiService;
import com.digitalid.mauritania.network.ServiceGenerator;
import com.digitalid.mauritania.utils.UiText;

import retrofit2.Call;
import retrofit2.Callback;
import retrofit2.Response;

public class QRLoginViewModel extends AndroidViewModel {

    Application application;
    private final MutableLiveData<Boolean> isProcessing = new MutableLiveData<>();
    private final MutableLiveData<UiText> statusMessage = new MutableLiveData<>();

    private final MutableLiveData<Boolean> qrLoginStatus = new MutableLiveData<>();


    public LiveData<Boolean> isProcessing() {

        return isProcessing;
    }


    public LiveData<UiText> getStatusMessage() {
        return statusMessage;
    }

    public LiveData<Boolean> getQrLoginStatus() {
        return qrLoginStatus;
    }


    public QRLoginViewModel(@NonNull Application application) {
        super(application);
        this.application = application;
    }


    public void qrLogin(String userName, String qrcodeData) {


        isProcessing.postValue(true);
        statusMessage.postValue(UiText.stringResource(R.string.qr_login));


        QRLoginRequest qrLoginRequest = new QRLoginRequest(userName, qrcodeData);


        MauritaniaApiService service = ServiceGenerator.createService(MauritaniaApiService.class);
        Call<QRLoginRequest> call = service.qrCodeLogin(qrLoginRequest);

        call.enqueue(new Callback<QRLoginRequest>() {
            @Override
            public void onResponse(Call<QRLoginRequest> call, Response<QRLoginRequest> response) {


                isProcessing.postValue(false);
                statusMessage.postValue(UiText.emptyString());


                qrLoginStatus.postValue(response.isSuccessful());
            }

            @Override
            public void onFailure(Call<QRLoginRequest> call, Throwable t) {

                Log.d("TAG", "onFailure : " + t.getMessage());
                isProcessing.postValue(false);
                statusMessage.postValue(UiText.emptyString());
                qrLoginStatus.postValue(false);
            }
        });


    }
}
