package com.digitalid.mauritania.models;

import com.google.gson.annotations.SerializedName;

public class QRLoginRequest {


    public QRLoginRequest(String username, String qrAuth) {
        this.username = username;
        this.qrAuth = qrAuth;
    }


    @SerializedName("username")
    private String username;


    @SerializedName("qrAuth")
    private String qrAuth;


    @SerializedName("createdAt")
    private String createdAt;

    public String getUsername() {
        return username;
    }

    public void setUsername(String username) {
        this.username = username;
    }

    public String getQrAuth() {
        return qrAuth;
    }

    public void setQrAuth(String qrAuth) {
        this.qrAuth = qrAuth;
    }

    public String getCreatedAt() {
        return createdAt;
    }

    public void setCreatedAt(String createdAt) {
        this.createdAt = createdAt;
    }
}
