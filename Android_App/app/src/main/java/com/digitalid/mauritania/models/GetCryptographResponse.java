package com.digitalid.mauritania.models;

import com.google.gson.annotations.SerializedName;

public class GetCryptographResponse {

    public void setImage(String image) {
        this.image = image;
    }

    public void setUuid(String uuid) {
        this.uuid = uuid;
    }


    @SerializedName("image")
    private String image;


    @SerializedName("uuid")
    private String uuid;

    public String getUuid() {
        return uuid;
    }

    public String getImage() {
        return image;
    }
}
