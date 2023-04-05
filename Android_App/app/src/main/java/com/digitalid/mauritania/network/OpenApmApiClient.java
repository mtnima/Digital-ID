package com.digitalid.mauritania.network;


import com.digitalid.mauritania.utils.Constants;
import okhttp3.OkHttpClient;
import okhttp3.logging.HttpLoggingInterceptor;
import retrofit2.Retrofit;
import retrofit2.converter.gson.GsonConverterFactory;


public class OpenApmApiClient {

    private Retrofit retrofitRx = null;


    public Retrofit getRetrofitClient() {


        if (retrofitRx == null) {
            OkHttpClient.Builder client = new OkHttpClient.Builder();

            HttpLoggingInterceptor loggingInterceptor = new HttpLoggingInterceptor();
            loggingInterceptor.setLevel(HttpLoggingInterceptor.Level.BODY);
            client.addInterceptor(loggingInterceptor);

            retrofitRx = new Retrofit.Builder()
                    .baseUrl(Constants.OPENAM_BASE_URL)
                    .client(client.build())
                    .addConverterFactory(GsonConverterFactory.create())
                    .build();
        }
        return retrofitRx;
    }

}