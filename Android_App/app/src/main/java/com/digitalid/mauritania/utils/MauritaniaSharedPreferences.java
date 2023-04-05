package com.digitalid.mauritania.utils;

import android.content.Context;
import android.content.SharedPreferences;
import android.security.keystore.KeyGenParameterSpec;

import androidx.security.crypto.EncryptedSharedPreferences;
import androidx.security.crypto.MasterKeys;

import java.io.IOException;
import java.security.GeneralSecurityException;

public class MauritaniaSharedPreferences {

    private static final String SELECTED_LANGUAGE = "Locale.Helper.Selected.Language";

    private static final String RSA_PUBLIC_KEY = "RSA_PUBLIC_KEY";

    private SharedPreferences sharedPref;


    public MauritaniaSharedPreferences(Context context) throws GeneralSecurityException, IOException {


        KeyGenParameterSpec keyGenParameterSpec = MasterKeys.AES256_GCM_SPEC;
        String mainKeyAlias = MasterKeys.getOrCreate(keyGenParameterSpec);

        sharedPref = EncryptedSharedPreferences.create(
                Constants.DEFAULT_PREF_FILE_NAME,
                mainKeyAlias,
                context,
                EncryptedSharedPreferences.PrefKeyEncryptionScheme.AES256_SIV,
                EncryptedSharedPreferences.PrefValueEncryptionScheme.AES256_GCM
        );


    }


    public void setLanguage(String language) {

        sharedPref.edit().putString(SELECTED_LANGUAGE, language).apply();

    }

    public String getLanguage(String defaultLanguage) {
        return (sharedPref.getString(SELECTED_LANGUAGE, defaultLanguage));
    }


    public void setRsaPublicKey(String rsaPublicKey) {

        sharedPref.edit().putString(RSA_PUBLIC_KEY, rsaPublicKey).apply();

    }

    public String getRsaPublicKey() {
        return sharedPref.getString(RSA_PUBLIC_KEY, null);
    }

}
