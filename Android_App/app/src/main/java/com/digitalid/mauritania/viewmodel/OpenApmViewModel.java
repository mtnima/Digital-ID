package com.digitalid.mauritania.viewmodel;

import android.app.Application;

import androidx.annotation.NonNull;
import androidx.lifecycle.AndroidViewModel;
import androidx.lifecycle.LiveData;
import androidx.lifecycle.MutableLiveData;

import com.digitalid.mauritania.R;
import com.digitalid.mauritania.models.AuthenticationResponse;
import com.digitalid.mauritania.models.AuthoriseResponse;
import com.digitalid.mauritania.models.CallBackRequest;
import com.digitalid.mauritania.models.InputOutput;
import com.digitalid.mauritania.network.OpenApmApiClient;
import com.digitalid.mauritania.network.OpenApmService;
import com.digitalid.mauritania.utils.UiText;

import java.util.HashMap;
import java.util.List;

import retrofit2.Call;
import retrofit2.Callback;
import retrofit2.Response;

public class OpenApmViewModel extends AndroidViewModel {

    Application application;
    private final MutableLiveData<Boolean> isProcessing = new MutableLiveData<>();
    private final MutableLiveData<UiText> statusMessage = new MutableLiveData<>();

    private final MutableLiveData<Boolean> qrAuthStatus = new MutableLiveData<>();

    public LiveData<AuthenticationResponse> getAuthenticationResponse() {
        return authenticationResponse;
    }

    private final MutableLiveData<AuthenticationResponse> authenticationResponse = new MutableLiveData<>();

    public LiveData<AuthoriseResponse> getAuthoriseResponse() {
        return authoriseResponse;
    }

    private final MutableLiveData<AuthoriseResponse> authoriseResponse = new MutableLiveData<>();


    public LiveData<Boolean> isProcessing() {

        return isProcessing;
    }


    public LiveData<UiText> getStatusMessage() {
        return statusMessage;
    }

    public LiveData<Boolean> getQrAuthStatus() {
        return qrAuthStatus;
    }


    public OpenApmViewModel(@NonNull Application application) {
        super(application);
        this.application = application;
    }


    public void authenticate(String userName, String password) {
        isProcessing.postValue(true);
        statusMessage.postValue(UiText.stringResource(R.string.authentication_performing));

        OpenApmApiClient client = new OpenApmApiClient();

        OpenApmService service = client.getRetrofitClient().create(OpenApmService.class);

        Call<AuthenticationResponse> call = service.authenticate(userName, password);

        call.enqueue(new Callback<AuthenticationResponse>() {
            @Override
            public void onResponse(Call<AuthenticationResponse> call, Response<AuthenticationResponse> response) {

                isProcessing.postValue(false);

                if (response.isSuccessful()) {

                    authenticationResponse.postValue(response.body());

                } else {
                    statusMessage.postValue(UiText.stringResource(R.string.authentication_failure, response.code()));
                }


            }

            @Override
            public void onFailure(Call<AuthenticationResponse> call, Throwable t) {

                isProcessing.postValue(false);
                statusMessage.postValue(UiText.stringResource(R.string.authentication_failure,t.getLocalizedMessage()));

            }
        });

    }


    public void authorise(String tokenId) {


        isProcessing.postValue(true);
        statusMessage.postValue(UiText.stringResource(R.string.authentication_performing));

        OpenApmApiClient client = new OpenApmApiClient();
        OpenApmService service = client.getRetrofitClient().create(OpenApmService.class);

        HashMap<String, String> queryMap = new HashMap<>();
        queryMap.put("authIndexType", "service");
        queryMap.put("authIndexValue", "qr");
        queryMap.put("ForceAuth", "true");
        queryMap.put("sessionUpgradeSSOTokenId", tokenId);


        Call<AuthoriseResponse> call = service.authorise(queryMap);

        call.enqueue(new Callback<AuthoriseResponse>() {
            @Override
            public void onResponse(Call<AuthoriseResponse> call, Response<AuthoriseResponse> response) {

                isProcessing.postValue(false);

                if (response.isSuccessful()) {

                    authoriseResponse.postValue(response.body());

                } else {
                    statusMessage.postValue(UiText.stringResource(R.string.authorisation_success, response.code()));
                }

            }

            @Override
            public void onFailure(Call<AuthoriseResponse> call, Throwable t) {
                isProcessing.postValue(false);
                statusMessage.postValue(UiText.stringResource(R.string.authorisation_success , t.getLocalizedMessage()));
            }
        });


    }


    public void qrAuth(String tokenId, AuthoriseResponse authoriseResponse, String qrcodeData) {


        isProcessing.postValue(true);
        statusMessage.postValue(UiText.stringResource(R.string.authentication_performing));

        OpenApmApiClient client = new OpenApmApiClient();
        OpenApmService service = client.getRetrofitClient().create(OpenApmService.class);

        HashMap<String, String> queryMap = new HashMap<>();
        queryMap.put("authIndexType", "service");
        queryMap.put("authIndexValue", "qr");
        queryMap.put("ForceAuth", "true");
        queryMap.put("sessionUpgradeSSOTokenId", tokenId);


        authoriseResponse.setHeader(qrcodeData);

        List<CallBackRequest> callbacks = authoriseResponse.getCallbacks();

        for (CallBackRequest callBack : callbacks) {

            if (callBack.getType().equals("PasswordCallback")) {

                for (InputOutput input : callBack.getInput()) {

                    if (input.getName().contains("IDToken")) {

                        input.setValue(qrcodeData);

                    }

                }

            }

        }


        Call<AuthoriseResponse> call = service.authoriseQrCode(queryMap, authoriseResponse);

        call.enqueue(new Callback<AuthoriseResponse>() {
            @Override
            public void onResponse(Call<AuthoriseResponse> call, Response<AuthoriseResponse> response) {
                isProcessing.postValue(false);
                statusMessage.postValue(UiText.emptyString());


                qrAuthStatus.postValue(response.isSuccessful());

            }

            @Override
            public void onFailure(Call<AuthoriseResponse> call, Throwable t) {
                isProcessing.postValue(false);
                statusMessage.postValue(UiText.emptyString());
                qrAuthStatus.postValue(false);

            }
        });


    }
}
