package com.digitalid.mauritania.ui;


import android.Manifest;
import android.content.pm.PackageManager;
import android.os.Bundle;
import android.util.Log;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.Toast;

import androidx.activity.result.ActivityResultLauncher;
import androidx.activity.result.contract.ActivityResultContracts;
import androidx.annotation.NonNull;
import androidx.annotation.Nullable;
import androidx.core.content.ContextCompat;
import androidx.fragment.app.Fragment;
import androidx.lifecycle.ViewModelProvider;
import androidx.navigation.Navigation;

import com.digitalid.mauritania.R;
import com.digitalid.mauritania.databinding.SplashFragmentBinding;
import com.digitalid.mauritania.utils.LoginSharedPreferences;
import com.digitalid.mauritania.utils.MauritaniaSharedPreferences;
import com.digitalid.mauritania.viewmodel.SharedViewModel;

import java.io.IOException;
import java.security.GeneralSecurityException;


public class SplashFragment extends Fragment {


    private SharedViewModel sharedViewModel;
    private SplashFragmentBinding binding;


    LoginSharedPreferences appSharedPreference = null;

    MauritaniaSharedPreferences mauritaniaSharedPreferences = null;
    private ActivityResultLauncher<String> requestPermissionLauncher = registerForActivityResult(new ActivityResultContracts.RequestPermission(), isGranted -> {

        if (Boolean.TRUE.equals(isGranted)) {
            // Permission is granted. Continue the action or workflow in your
            // app.

            sharedViewModel.prepareDatabase();


        } else {
            // Explain to the user that the feature is unavailable because the
            // feature requires a permission that the user has denied. At the
            // same time, respect the user's decision. Don't link to system
            // settings in an effort to convince the user to change their
            // decision.
        }
    });


    @Nullable
    @Override
    public View onCreateView(@NonNull LayoutInflater inflater, @Nullable ViewGroup container, @Nullable Bundle savedInstanceState) {

        binding = SplashFragmentBinding.inflate(inflater, container, false);
        View view = binding.getRoot();


        try {
            appSharedPreference = new LoginSharedPreferences(requireContext());

            mauritaniaSharedPreferences = new MauritaniaSharedPreferences(requireContext());
        } catch (GeneralSecurityException | IOException e) {
            Log.d("TAG", "Unable to create sharedprefs");
        }

        if (appSharedPreference == null || mauritaniaSharedPreferences == null) {
            Toast.makeText(requireContext(), "Something wrong", Toast.LENGTH_LONG).show();
            return view;
        }


        sharedViewModel = new ViewModelProvider(requireActivity()).get(SharedViewModel.class);

        observeOcr();

        observeViewModelResults();

        checkPermission();

        return view;

    }


    private void observeOcr() {

        sharedViewModel.isOCRSDKInitialized().observe(getViewLifecycleOwner(), aBoolean -> {


            if (Boolean.TRUE.equals(aBoolean)) {
                sharedViewModel.initSDK(requireContext());

            }

        });


        sharedViewModel.isOCRDbDownloaded().observe(getViewLifecycleOwner(), aBoolean -> {

            if (Boolean.TRUE.equals(aBoolean)) {
                sharedViewModel.initRegulaSDK();
            }

        });
    }


    private void observeViewModelResults() {

        sharedViewModel.isSDKInitialized().observe(getViewLifecycleOwner(), aBoolean -> {


            if (Boolean.TRUE.equals(aBoolean)) {


                if (mauritaniaSharedPreferences.getRsaPublicKey() != null) {

                    nextPage();

                } else {

                    sharedViewModel.getRsaPublicKey();
                }


            } else {


                //  restart activity
                binding.txtStatus.setText(R.string.init_sdk_failed);


            }

        });


        sharedViewModel.isSDkLoading().observe(getViewLifecycleOwner(), aBoolean -> binding.progressCircular.setVisibility(Boolean.TRUE.equals(aBoolean) ? View.VISIBLE : View.GONE));


        sharedViewModel.rsaPublicKey().observe(getViewLifecycleOwner(), s -> {


            if (s == null) {
                return;
            }


            mauritaniaSharedPreferences.setRsaPublicKey(s);

            nextPage();

        });


        sharedViewModel.getStatus().observe(getViewLifecycleOwner(), s -> {

            if (s == null) {
                return;
            }


            binding.txtStatus.setText(s.asString(requireContext()));

        });
    }


    private void nextPage() {

        if (appSharedPreference.isVerifiedProfile()) {

            Navigation.findNavController(binding.getRoot()).navigate(R.id.action_splash_fragment_to_sendMoneyGraph);


        } else {

            Navigation.findNavController(binding.getRoot()).navigate(R.id.action_splash_fragment_to_intro_fragment);
        }


    }


    private void checkPermission() {

        if (ContextCompat.checkSelfPermission(
                requireContext(), Manifest.permission.CAMERA) ==
                PackageManager.PERMISSION_GRANTED) {
            // You can use the API that requires the permission.


            sharedViewModel.prepareDatabase();


        } else {
            // You can directly ask for the permission.
            // The registered ActivityResultCallback gets the result of this request.
            requestPermissionLauncher.launch(
                    Manifest.permission.CAMERA);
        }
    }

    @Override
    public void onDestroyView() {
        super.onDestroyView();
        binding = null;
    }


}
