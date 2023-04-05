package com.digitalid.mauritania.utils;

import android.content.Context;

import androidx.annotation.StringRes;

public class UiText {

    private static boolean isStringResource = true;

    private static int id;
    private static Object[] formatOrgs;

    private static String dynamicString;

    private UiText() {

    }


    public static UiText nonTranslatableString(String data) {

        isStringResource = false;
        dynamicString = data;


        return new UiText();

    }

    public static UiText emptyString() {

        isStringResource = false;

        dynamicString = "";

        return new UiText();

    }

    public static UiText stringResource(@StringRes int resId, Object... formatArgs) {
        isStringResource = true;
        id = resId;
        formatOrgs = formatArgs;
        return new UiText();
    }


    public String asString(Context context) {

        if (isStringResource) {

            return context.getResources().getString(id, formatOrgs);
        } else {
            return dynamicString;
        }

    }
}
