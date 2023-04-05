package com.digitalid.mauritania.ui;

import android.os.Bundle;
import android.util.Base64;
import android.util.Log;
import android.view.LayoutInflater;
import android.view.MenuItem;
import android.view.View;
import android.view.ViewGroup;
import android.widget.Toast;

import androidx.activity.OnBackPressedCallback;
import androidx.annotation.NonNull;
import androidx.annotation.Nullable;
import androidx.fragment.app.Fragment;
import androidx.lifecycle.ViewModelProvider;
import androidx.navigation.Navigation;

import com.digitalid.mauritania.R;
import com.digitalid.mauritania.databinding.ThirdPartyLoginBinding;
import com.digitalid.mauritania.utils.LoginSharedPreferences;
import com.digitalid.mauritania.utils.UiText;
import com.digitalid.mauritania.viewmodel.CryptographViewModel;
import com.digitalid.mauritania.viewmodel.BioMetricMatchViewModel;
import com.digitalid.mauritania.viewmodel.OpenApmViewModel;
import com.digitalid.mauritania.viewmodel.SharedViewModel;

import java.io.IOException;
import java.security.GeneralSecurityException;

import Tech5.OmniMatch.Common;

public class ThirdPartyLoginUsingOpenAM extends Fragment {


    ThirdPartyLoginBinding binding;
    OpenApmViewModel openApmViewModel;
    private SharedViewModel sharedViewModel;
    CryptographViewModel cryptographViewModel;
    BioMetricMatchViewModel mainActivityViewModel;

    private String tokenId = null;

    private LoginSharedPreferences appSharedPreference;


    @Nullable
    @Override
    public View onCreateView(@NonNull LayoutInflater inflater, @Nullable ViewGroup container, @Nullable Bundle savedInstanceState) {
        binding = ThirdPartyLoginBinding.inflate(inflater, container, false);
        View view = binding.getRoot();

        binding.dataRecipientCard.setVisibility(View.GONE);

        binding.btnNext.setEnabled(false);


        try {
            appSharedPreference = new LoginSharedPreferences(requireContext());
        } catch (GeneralSecurityException | IOException e) {
            Log.d("TAG", "Unable to create sharedprefs");
        }


        sharedViewModel = new ViewModelProvider(requireActivity()).get(SharedViewModel.class);

        openApmViewModel = new ViewModelProvider(this).get(OpenApmViewModel.class);


        cryptographViewModel = new ViewModelProvider(this).get(CryptographViewModel.class);
        cryptographViewModel.init(sharedViewModel.getCryptographUtil());

        mainActivityViewModel = new ViewModelProvider(this).get(BioMetricMatchViewModel.class);
        mainActivityViewModel.init(sharedViewModel.getTemplateCreatorNNNative(), sharedViewModel.getTemplateCreatorNNFaceLightInstance(), sharedViewModel.getAuthMatcherNative(), sharedViewModel.getAuthMatcherInstance(), sharedViewModel.getCryptographUtil());


        binding.btnBack.setOnClickListener(v -> onBackPressed());

        binding.btnNext.setOnClickListener(v -> Navigation.findNavController(binding.getRoot()).navigate(R.id.action_third_party_to_result));

        binding.btnRetry.setOnClickListener(v -> {

            if (Boolean.TRUE.equals(sharedViewModel.isNetworkAvailable())) {

                binding.btnRetry.setVisibility(View.GONE);
                binding.txtStatusDesc.setText("");

                //authentication start
                openApmViewModel.authenticate(appSharedPreference.getNNI(), appSharedPreference.getPassword());
            } else {

                binding.btnRetry.setVisibility(View.VISIBLE);
                binding.txtStatusDesc.setText(getResources().getString(R.string.label_no_internet));

            }

        });

        requireActivity().getOnBackPressedDispatcher().addCallback(getViewLifecycleOwner(), callback);


        observerViewModels();


        cryptographViewModel.getTemplateFromStoredCryptograph();


        return view;
    }


    private void observerViewModels() {

        openApmViewModel.isProcessing().observe(getViewLifecycleOwner(), aBoolean -> binding.progressCircular.setVisibility(Boolean.TRUE.equals(aBoolean) ? View.VISIBLE : View.GONE));


        openApmViewModel.getStatusMessage().observe(getViewLifecycleOwner(), this::handleStatusMessage);

        cryptographViewModel.getStatusMessage().observe(getViewLifecycleOwner(), this::handleStatusMessage);
        mainActivityViewModel.getStatusMessage().observe(getViewLifecycleOwner(), this::handleStatusMessage);

        openApmViewModel.getQrAuthStatus().observe(getViewLifecycleOwner(), aBoolean -> {


            binding.btnNext.setEnabled(true);

            binding.progressLayout.setVisibility(View.GONE);
            binding.dataRecipientCard.setVisibility(View.VISIBLE);


        });


        mainActivityViewModel.getMatchResult().observe(getViewLifecycleOwner(), recordResult -> {

            if (recordResult == null) {
                return;
            }

            if (recordResult.getCandidate().getScores().getFace().getLogFAR() >= 4.0) {

                if (Boolean.TRUE.equals(sharedViewModel.isNetworkAvailable())) {

                    //authentication starts

                    openApmViewModel.authenticate(appSharedPreference.getNNI(), appSharedPreference.getPassword());
                } else {


                    binding.btnRetry.setVisibility(View.VISIBLE);
                    binding.txtStatusDesc.setText(getResources().getString(R.string.label_no_internet));

                }

            } else {

                Toast.makeText(requireContext(), getResources().getString(R.string.face_verification_failed), Toast.LENGTH_LONG).show();
            }


        });

        cryptographViewModel.getFaceTemplate().observe(getViewLifecycleOwner(), s -> {


            if (s != null) {

                byte[] template = Base64.decode(s, Base64.NO_WRAP);

                mainActivityViewModel.matchFaceImageAndTemplate(template, sharedViewModel.getLiveFaceImage(), Common.ImageFormat.JPEG);

            }

        });


        openApmViewModel.getAuthenticationResponse().observe(getViewLifecycleOwner(), authenticationResponse -> {
            tokenId = authenticationResponse.getTokenId();

            openApmViewModel.authorise(authenticationResponse.getTokenId());

        });

        openApmViewModel.getAuthoriseResponse().observe(getViewLifecycleOwner(), authoriseResponse ->
                openApmViewModel.qrAuth(tokenId, authoriseResponse, sharedViewModel.getQrcodeContent()));

    }


    private void handleStatusMessage(UiText s) {
        if (s == null) {
            binding.txtStatusDesc.setText("");
            return;
        }

        binding.txtStatusDesc.setText(s.asString(requireContext()));
    }


    OnBackPressedCallback callback = new OnBackPressedCallback(true /* enabled by default */) {

        @Override
        public void handleOnBackPressed() {

            onBackPressed();
        }
    };


    private void onBackPressed() {

        Navigation.findNavController(binding.getRoot()).navigate(R.id.action_thirdparty_to_loginGraph);

        NavGraphActivity navGraphActivity = (NavGraphActivity) getActivity();

        MenuItem item = navGraphActivity.getBottomNavigationView().getMenu().findItem(R.id.navigation_home);
        item.setChecked(true);
    }


    @Override
    public void onResume() {
        super.onResume();

        NavGraphActivity navGraphActivity = (NavGraphActivity) getActivity();

        navGraphActivity.getBottomNavigationView().setVisibility(View.GONE);
    }
}
