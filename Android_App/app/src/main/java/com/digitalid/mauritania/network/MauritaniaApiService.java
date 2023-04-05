package com.digitalid.mauritania.network;

import com.digitalid.mauritania.models.GetCryptographRequest;
import com.digitalid.mauritania.models.GetCryptographResponse;
import com.digitalid.mauritania.models.GetPublicKeyResponse;
import com.digitalid.mauritania.models.QRLoginRequest;
import com.digitalid.mauritania.models.RegistrationRequest;
import com.digitalid.mauritania.models.RegistrationResponse;

import retrofit2.Call;
import retrofit2.http.Body;
import retrofit2.http.GET;
import retrofit2.http.POST;

public interface MauritaniaApiService {


    @GET("getPublicKey")
    Call<GetPublicKeyResponse> getPublicKey();


    @POST("getCryptography")
    Call<GetCryptographResponse> createCryptograph(@Body GetCryptographRequest request);


    @POST("addUser")
    Call<RegistrationResponse> registerUser(@Body RegistrationRequest request);


    @POST("establishConnection")
    Call<QRLoginRequest> qrCodeLogin(@Body QRLoginRequest request);


}