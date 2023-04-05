package com.digitalid.mauritania.models;

import com.google.gson.annotations.SerializedName;

public class RegistrationRequest {

    @SerializedName("pin")
    private String pin;
    @SerializedName("firstName")
    private String firstName;
    @SerializedName("lastName")
    private String lastName;

    @SerializedName("birthDate")
    private String birthDate;

    public String getPin() {
        return pin;
    }

    public void setPin(String pin) {
        this.pin = pin;
    }

    public String getFirstName() {
        return firstName;
    }

    public void setFirstName(String firstName) {
        this.firstName = firstName;
    }

    public String getLastName() {
        return lastName;
    }

    public void setLastName(String lastName) {
        this.lastName = lastName;
    }

    public String getBirthDate() {
        return birthDate;
    }

    public void setBirthDate(String birthDate) {
        this.birthDate = birthDate;
    }
}
