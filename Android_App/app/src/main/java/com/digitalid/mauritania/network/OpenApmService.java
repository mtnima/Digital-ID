package com.digitalid.mauritania.network;


import com.digitalid.mauritania.models.AuthenticationResponse;
import com.digitalid.mauritania.models.AuthoriseResponse;

import java.util.Map;

import retrofit2.Call;
import retrofit2.http.Body;
import retrofit2.http.Header;
import retrofit2.http.POST;
import retrofit2.http.QueryMap;

public interface OpenApmService {

    @POST("authenticate")
    Call<AuthenticationResponse> authenticate(@Header("X-OpenAM-Username") String userName, @Header("X-OpenAm-Password") String password);


    @POST("authenticate")
    Call<AuthoriseResponse> authorise(@QueryMap Map<String, String> options);




    @POST("authenticate")
    Call<AuthoriseResponse> authoriseQrCode(@QueryMap Map<String, String> options, @Body AuthoriseResponse request);


}