package com.digitalid.mauritania.utils;


import android.content.Context;
import android.content.SharedPreferences;
import android.security.keystore.KeyGenParameterSpec;

import androidx.security.crypto.EncryptedSharedPreferences;
import androidx.security.crypto.MasterKeys;

import java.io.IOException;
import java.security.GeneralSecurityException;

public class LoginSharedPreferences {


    private SharedPreferences sharedPref;
    private static final String FIRST_NAME = "FIRST_NAME";
    private static final String LAST_NAME = "LAST_NAME";

    private static final String NNI = "NNI";
    private static final String DOB = "DOB";
    private static final String POB = "POB";

    private static final String NATIONALITY = "NATIONALITY";

    private static final String GENDER = "GENDER";

    private static final String PHONE = "PHONE";

    private static final String ISSUE_DATE = "ISSUE_DATE";


    private static final String EXPIRY_DATE = "EXPIRY_DATE";

    private static final String PASSWORD = "PASSWORD";
    private static final String FACE_IMAGE_PATH = "FACE_IMAGE_PATH";

    private static final String IS_VERIFIED_PROFILE = "IS_VERIFIED_PROFILE";


    public LoginSharedPreferences(Context context) throws GeneralSecurityException, IOException {


        KeyGenParameterSpec keyGenParameterSpec = MasterKeys.AES256_GCM_SPEC;
        String mainKeyAlias = MasterKeys.getOrCreate(keyGenParameterSpec);

        sharedPref = EncryptedSharedPreferences.create(
                Constants.LOGIN_PREF_FILE_NAME,
                mainKeyAlias,
                context,
                EncryptedSharedPreferences.PrefKeyEncryptionScheme.AES256_SIV,
                EncryptedSharedPreferences.PrefValueEncryptionScheme.AES256_GCM
        );


    }


    public void setFirstName(String firstName) {

        sharedPref.edit().putString(FIRST_NAME, firstName).apply();

    }

    public String getFirstName() {
        return (sharedPref.getString(FIRST_NAME, "-"));
    }


    public void setNNI(String firstName) {

        sharedPref.edit().putString(NNI, firstName).apply();

    }

    public String getNNI() {
        return (sharedPref.getString(NNI, "-"));
    }


    public void setLastName(String firstName) {

        sharedPref.edit().putString(LAST_NAME, firstName).apply();

    }


    public void setDob(String firstName) {

        sharedPref.edit().putString(DOB, firstName).apply();

    }

    public String getDOB() {
        return (sharedPref.getString(DOB, "-"));
    }


    public void setPob(String firstName) {

        sharedPref.edit().putString(POB, firstName).apply();

    }

    public String getPOB() {
        return (sharedPref.getString(POB, "-"));
    }


    public void setNationality(String nationality) {

        sharedPref.edit().putString(NATIONALITY, nationality).apply();

    }

    public String getNationality() {
        return (sharedPref.getString(NATIONALITY, "-"));
    }


    public void setPhone(String phone) {

        sharedPref.edit().putString(PHONE, phone).apply();

    }

    public String getPhone() {
        return (sharedPref.getString(PHONE, "-"));
    }


    public void setGender(String gender) {

        sharedPref.edit().putString(GENDER, gender).apply();

    }

    public String getGender() {
        return (sharedPref.getString(GENDER, "-"));
    }


    public void setIssueDate(String issueDate) {

        sharedPref.edit().putString(ISSUE_DATE, issueDate).apply();

    }

    public String getIssueDate() {
        return (sharedPref.getString(ISSUE_DATE, "-"));
    }


    public void setExpiryDate(String expiryDate) {

        sharedPref.edit().putString(EXPIRY_DATE, expiryDate).apply();

    }

    public String getExpiryDate() {
        return (sharedPref.getString(EXPIRY_DATE, "-"));
    }


    public void setPassword(String password) {

        sharedPref.edit().putString(PASSWORD, password).apply();

    }

    public String getPassword() {
        return (sharedPref.getString(PASSWORD, null));
    }


    public void setFaceImagePath(String faceImagePath) {

        sharedPref.edit().putString(FACE_IMAGE_PATH, faceImagePath).apply();

    }

    public String getFaceImagePath() {
        return (sharedPref.getString(FACE_IMAGE_PATH, null));
    }


    public boolean isVerifiedProfile() {
        return (sharedPref.getBoolean(IS_VERIFIED_PROFILE, false));
    }

    public void setIsVerifiedProfile(boolean isVerified) {
        sharedPref.edit().putBoolean(IS_VERIFIED_PROFILE, isVerified).apply();
    }


    public void clearPrefs() {

        sharedPref.edit().clear().commit();


    }

}
