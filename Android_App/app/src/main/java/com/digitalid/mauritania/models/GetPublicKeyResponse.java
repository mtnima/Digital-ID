package com.digitalid.mauritania.models;

import com.google.gson.annotations.SerializedName;

public class GetPublicKeyResponse {


    @SerializedName("publicKey")
    private String publicKey;


    @SerializedName("timestamp")
    private String timestamp;

    public String getPublicKey() {
        return publicKey;
    }


    public void setPublicKey(String publicKey) {
        this.publicKey = publicKey;
    }

    public String getTimestamp() {
        return timestamp;
    }

    public void setTimestamp(String timestamp) {
        this.timestamp = timestamp;
    }
}