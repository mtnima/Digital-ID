package com.digitalid.mauritania.models;

import com.google.gson.annotations.SerializedName;

public class RegistrationResponse {

    @SerializedName("value")
    private String value;
    @SerializedName("timestamp")
    private String timestamp;

    public String getValue() {
        return value;
    }

    public void setValue(String value) {
        this.value = value;
    }

    public String getTimestamp() {
        return timestamp;
    }

    public void setTimestamp(String timestamp) {
        this.timestamp = timestamp;
    }
}
