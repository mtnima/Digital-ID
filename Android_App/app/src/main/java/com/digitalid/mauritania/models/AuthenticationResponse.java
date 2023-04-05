package com.digitalid.mauritania.models;

import com.google.gson.annotations.SerializedName;

public class AuthenticationResponse {


    @SerializedName("tokenId")
    private String tokenId;

    @SerializedName("successUrl")
    private String successUrl;

    @SerializedName("realm")
    private String realm;

    public void setTokenId(String tokenId) {
        this.tokenId = tokenId;
    }

    public void setSuccessUrl(String successUrl) {
        this.successUrl = successUrl;
    }

    public void setRealm(String realm) {
        this.realm = realm;
    }



    public String getTokenId() {
        return tokenId;
    }

    public String getSuccessUrl() {
        return successUrl;
    }

    public String getRealm() {
        return realm;
    }


}
