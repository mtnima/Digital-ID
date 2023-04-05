package com.digitalid.mauritania.ui;

import android.content.Context;
import android.content.Intent;
import android.os.Bundle;
import android.util.Log;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.Toast;

import androidx.annotation.NonNull;
import androidx.annotation.Nullable;
import androidx.appcompat.app.AlertDialog;
import androidx.fragment.app.Fragment;
import androidx.navigation.Navigation;

import com.digitalid.mauritania.R;
import com.digitalid.mauritania.databinding.SettingsFragemntBinding;
import com.digitalid.mauritania.utils.Constants;
import com.digitalid.mauritania.utils.MauritaniaSharedPreferences;
import com.digitalid.mauritania.utils.LocaleHelper;
import com.digitalid.mauritania.utils.LoginSharedPreferences;
import com.digitalid.mauritania.utils.Utils;

import java.io.File;
import java.io.IOException;
import java.security.GeneralSecurityException;


public class SettingsFragment extends Fragment {

    SettingsFragemntBinding binding;

    LoginSharedPreferences appSharedPreference;

    @Nullable
    @Override
    public View onCreateView(@NonNull LayoutInflater inflater, @Nullable ViewGroup container, @Nullable Bundle savedInstanceState) {


        binding = SettingsFragemntBinding.inflate(inflater, container, false);
        View view = binding.getRoot();


        String lang = getPersistedLanguage(requireContext(), "en");


        if (lang.equals("fr")) {

            binding.txtLanguage.setText(R.string.language_french);

        } else {
            binding.txtLanguage.setText(R.string.language_english);
        }


        try {
            appSharedPreference = new LoginSharedPreferences(requireContext());
        } catch (GeneralSecurityException | IOException e) {
            Log.d("TAG", "Unable to create sharedprefs");
        }

        if (appSharedPreference == null) {
            Toast.makeText(requireContext(), "Something wrong", Toast.LENGTH_LONG).show();
            return view;
        }

        binding.languageLayout.setOnClickListener(v -> showAlertDialog());

        binding.txtLogout.setOnClickListener(v -> {


            try {
                String cryptographPath = requireContext().getFilesDir() + File.separator + Constants.STORAGE_DIRECTORY + File.separator + Constants.CRYPTOGRAPH_IMAGE_NAME;

                File cryptoFile = new File(cryptographPath);

                Utils.deleteFile(cryptoFile);

                String faceImagePath = appSharedPreference.getFaceImagePath();

                File faceFile = new File(faceImagePath);
                Utils.deleteFile(faceFile);


            } catch (Exception e) {

                Log.e("TAG", "Failed to delete images");


            }

            appSharedPreference.clearPrefs();



            Navigation.findNavController(binding.getRoot()).navigate(R.id.action_settings_to_intro_fragment);


        });


        return view;

    }


    private void showAlertDialog() {

        AlertDialog.Builder builder = new AlertDialog.Builder(requireContext());
        builder.setTitle(R.string.choose_language)
                .setItems(R.array.languages_list, (dialog, which) -> {

                    if (which == 0) {
                        LocaleHelper.setLocale(requireContext(), "en");
                    } else {
                        LocaleHelper.setLocale(requireContext(), "fr");
                    }

                    Intent intent = getActivity().getIntent();
                    getActivity().finish();
                    getActivity().startActivity(intent);

                });

        builder.setNegativeButton(getResources().getString(R.string.label_cancel), (dialog, which) -> dialog.cancel());
        AlertDialog alertDialog = builder.create();
        alertDialog.show();
    }

    @SuppressWarnings("java:S6291")
    private static String getPersistedLanguage(Context context, String defaultLanguage) {
        try {

            MauritaniaSharedPreferences languagePreferences = new MauritaniaSharedPreferences(context);
            return languagePreferences.getLanguage(defaultLanguage);

        } catch (Exception e) {
            return defaultLanguage;
        }
    }


}
