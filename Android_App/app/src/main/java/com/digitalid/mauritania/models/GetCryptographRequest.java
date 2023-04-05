package com.digitalid.mauritania.models;

import com.google.gson.annotations.SerializedName;

public class GetCryptographRequest {


    @SerializedName("pin")
    private String pin;

    @SerializedName("firstName")
    private String firstName;


    @SerializedName("lastName")
    private String lastName;

    @SerializedName("birthDate")
    private String birthDate;


    @SerializedName("faceTemplate")
    private String faceTemplate;


    public String getPin() {
        return pin;
    }

    public String getFirstName() {
        return firstName;
    }

    public String getLastName() {
        return lastName;
    }

    public String getBirthDate() {
        return birthDate;
    }

    public String getFaceTemplate() {
        return faceTemplate;
    }


    public void setPin(String pin) {
        this.pin = pin;
    }

    public void setFirstName(String firstName) {
        this.firstName = firstName;
    }

    public void setLastName(String lastName) {
        this.lastName = lastName;
    }

    public void setBirthDate(String birthDate) {
        this.birthDate = birthDate;
    }

    public void setFaceTemplate(String faceTemplate) {
        this.faceTemplate = faceTemplate;
    }
}
