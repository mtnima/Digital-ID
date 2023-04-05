package com.digitalid.mauritania.ui;

import android.app.Application;
import android.content.Context;

import com.digitalid.mauritania.utils.LocaleHelper;

public class MauritaniaEidApplication extends Application {

    @Override
    protected void attachBaseContext(Context base) {

        super.attachBaseContext(LocaleHelper.onAttach(base, "fr"));


    }




}
