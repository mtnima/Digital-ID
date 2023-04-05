package com.digitalid.mauritania.ui;


import android.content.Context;
import android.os.Bundle;
import android.view.View;

import androidx.annotation.Nullable;
import androidx.appcompat.app.AppCompatActivity;
import androidx.core.os.ConfigurationCompat;
import androidx.navigation.NavController;
import androidx.navigation.fragment.NavHostFragment;
import androidx.navigation.ui.NavigationUI;

import com.digitalid.mauritania.R;
import com.digitalid.mauritania.utils.MauritaniaSharedPreferences;
import com.digitalid.mauritania.utils.LocaleHelper;
import com.google.android.material.bottomnavigation.BottomNavigationView;

import java.util.Locale;


public class NavGraphActivity extends AppCompatActivity {


    public BottomNavigationView getBottomNavigationView() {
        return bottomNavigationView;
    }

    private BottomNavigationView bottomNavigationView;


    @Override
    protected void onCreate(@Nullable Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);

        Locale current = ConfigurationCompat.getLocales(getResources().getConfiguration()).get(0);


        String defaultLanguage = "en";

        if (current.getLanguage().equals("fr")) {
            defaultLanguage = "fr";
        }


        String language = getPersistedLanguage(this, defaultLanguage);
        LocaleHelper.setLocale(this, language);
        setContentView(R.layout.nav_graph_activity);

        bottomNavigationView = findViewById(R.id.nav_view);

        NavHostFragment navHostFragment = (NavHostFragment) getSupportFragmentManager().findFragmentById(R.id.nav_host_fragment);


        NavController navController1 = navHostFragment.getNavController();


        navController1.addOnDestinationChangedListener((navController, nd, bundle) -> {


            if (nd.getId() == R.id.navigation_home || nd.getId() == R.id.navigation_settings || nd.getId() == R.id.navigation_scan) {

                bottomNavigationView.setVisibility(View.VISIBLE);
            } else {

                bottomNavigationView.setVisibility(View.GONE);
            }

        });


        NavigationUI.setupWithNavController(bottomNavigationView, navController1);


    }

    private static String getPersistedLanguage(Context context, String defaultLanguage) {
        try {

            MauritaniaSharedPreferences languagePreferences = new MauritaniaSharedPreferences(context);
            return languagePreferences.getLanguage(defaultLanguage);

        } catch (Exception e) {
            return defaultLanguage;
        }
    }


    @Override
    protected void attachBaseContext(Context base) {
        super.attachBaseContext(LocaleHelper.onAttach(base));
    }


}

