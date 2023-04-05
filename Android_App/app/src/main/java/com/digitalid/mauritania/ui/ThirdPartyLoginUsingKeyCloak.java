package com.digitalid.mauritania.ui;

import android.os.Bundle;
import android.util.Base64;
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
import com.digitalid.mauritania.utils.UiText;
import com.digitalid.mauritania.viewmodel.CryptographViewModel;
import com.digitalid.mauritania.viewmodel.BioMetricMatchViewModel;
import com.digitalid.mauritania.viewmodel.SharedViewModel;

import Tech5.OmniMatch.Common;

public class ThirdPartyLoginUsingKeyCloak extends Fragment {


    private ThirdPartyLoginBinding thirdPartyLoginBinding;

    private SharedViewModel sharedViewModel;
    private CryptographViewModel cryptographViewModel;
    private BioMetricMatchViewModel omniMatchViewModel;


    @Nullable
    @Override
    public View onCreateView(@NonNull LayoutInflater inflater, @Nullable ViewGroup container, @Nullable Bundle savedInstanceState) {
        thirdPartyLoginBinding = ThirdPartyLoginBinding.inflate(inflater, container, false);
        View view = thirdPartyLoginBinding.getRoot();

        thirdPartyLoginBinding.dataRecipientCard.setVisibility(View.GONE);

        thirdPartyLoginBinding.btnNext.setEnabled(false);


        sharedViewModel = new ViewModelProvider(requireActivity()).get(SharedViewModel.class);


        cryptographViewModel = new ViewModelProvider(this).get(CryptographViewModel.class);
        cryptographViewModel.init(sharedViewModel.getCryptographUtil());

        omniMatchViewModel = new ViewModelProvider(this).get(BioMetricMatchViewModel.class);
        omniMatchViewModel.init(sharedViewModel.getTemplateCreatorNNNative(), sharedViewModel.getTemplateCreatorNNFaceLightInstance(), sharedViewModel.getAuthMatcherNative(), sharedViewModel.getAuthMatcherInstance(), sharedViewModel.getCryptographUtil());


        thirdPartyLoginBinding.btnBack.setOnClickListener(v -> onBackPressed());

        thirdPartyLoginBinding.btnNext.setOnClickListener(v -> Navigation.findNavController(thirdPartyLoginBinding.getRoot()).navigate(R.id.action_third_party_keycloak_to_result));


        requireActivity().getOnBackPressedDispatcher().addCallback(getViewLifecycleOwner(), onBackPressedCallback);


        observerViewModels();


        cryptographViewModel.getTemplateFromStoredCryptograph();


        return view;
    }


    private void observerViewModels() {


        cryptographViewModel.getStatusMessage().observe(getViewLifecycleOwner(), this::handleStatusMessage);
        omniMatchViewModel.getStatusMessage().observe(getViewLifecycleOwner(), this::handleStatusMessage);


        omniMatchViewModel.getMatchResult().observe(getViewLifecycleOwner(), recordResult -> {

            if (recordResult == null) {
                return;
            }

            if (recordResult.getCandidate().getScores().getFace().getLogFAR() >= 4.0) {


                thirdPartyLoginBinding.btnNext.setEnabled(true);

                thirdPartyLoginBinding.progressLayout.setVisibility(View.GONE);
                thirdPartyLoginBinding.dataRecipientCard.setVisibility(View.VISIBLE);

            } else {

                Toast.makeText(requireContext(), getResources().getString(R.string.face_verification_failed), Toast.LENGTH_LONG).show();
            }


        });

        cryptographViewModel.getFaceTemplate().observe(getViewLifecycleOwner(), s -> {


            if (s != null) {

                byte[] template = Base64.decode(s, Base64.NO_WRAP);

                omniMatchViewModel.matchFaceImageAndTemplate(template, sharedViewModel.getLiveFaceImage(), Common.ImageFormat.JPEG);

            }

        });


    }


    private void handleStatusMessage(UiText s) {
        if (s == null) {
            thirdPartyLoginBinding.txtStatusDesc.setText("");
            return;
        }

        thirdPartyLoginBinding.txtStatusDesc.setText(s.asString(requireContext()));
    }


    OnBackPressedCallback onBackPressedCallback = new OnBackPressedCallback(true /* enabled by default */) {

        @Override
        public void handleOnBackPressed() {

            onBackPressed();
        }
    };


    private void onBackPressed() {

        Navigation.findNavController(thirdPartyLoginBinding.getRoot()).navigate(R.id.action_thirdparty_keycloak_to_loginGraph);

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
