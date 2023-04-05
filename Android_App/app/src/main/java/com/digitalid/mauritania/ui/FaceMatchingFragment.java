package com.digitalid.mauritania.ui;

import static com.digitalid.mauritania.utils.Utils.bitmapToBytes;

import android.os.Bundle;
import android.util.Log;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.Toast;

import androidx.annotation.NonNull;
import androidx.annotation.Nullable;
import androidx.fragment.app.Fragment;
import androidx.lifecycle.ViewModelProvider;
import androidx.navigation.Navigation;

import com.digitalid.mauritania.R;
import com.digitalid.mauritania.databinding.FaceMatchingFragmentBinding;
import com.digitalid.mauritania.models.Demographics;
import com.digitalid.mauritania.utils.LoginSharedPreferences;
import com.digitalid.mauritania.utils.MauritaniaSharedPreferences;
import com.digitalid.mauritania.utils.Utils;
import com.digitalid.mauritania.viewmodel.CryptographViewModel;
import com.digitalid.mauritania.viewmodel.BioMetricMatchViewModel;
import com.digitalid.mauritania.viewmodel.SharedViewModel;

import java.io.IOException;
import java.security.GeneralSecurityException;

import Tech5.OmniMatch.Common;


public class FaceMatchingFragment extends Fragment {

    private FaceMatchingFragmentBinding binding;
    private BioMetricMatchViewModel mainActivityViewModel = null;
    private SharedViewModel sharedViewModel;
    private CryptographViewModel cryptographViewModel;
    private LoginSharedPreferences appSharedPreference;
    private MauritaniaSharedPreferences mauritaniaSharedPreferences;

    @Nullable
    @Override
    public View onCreateView(@NonNull LayoutInflater inflater, @Nullable ViewGroup container, @Nullable Bundle savedInstanceState) {


        binding = FaceMatchingFragmentBinding.inflate(inflater, container, false);
        View view = binding.getRoot();

        binding.btnRecapture.setVisibility(View.GONE);
        binding.btnConnect.setVisibility(View.GONE);

        sharedViewModel = new ViewModelProvider(requireActivity()).get(SharedViewModel.class);

        mainActivityViewModel = new ViewModelProvider(this).get(BioMetricMatchViewModel.class);
        mainActivityViewModel.init(sharedViewModel.getTemplateCreatorNNNative(),
                sharedViewModel.getTemplateCreatorNNFaceLightInstance(),
                sharedViewModel.getAuthMatcherNative(),
                sharedViewModel.getAuthMatcherInstance(), sharedViewModel.getCryptographUtil());

        cryptographViewModel = new ViewModelProvider(this).get(CryptographViewModel.class);
        cryptographViewModel.init(sharedViewModel.getCryptographUtil());

        try {
            appSharedPreference = new LoginSharedPreferences(requireContext());

            mauritaniaSharedPreferences = new MauritaniaSharedPreferences(requireContext());

        } catch (GeneralSecurityException | IOException e) {
            Log.d("TAG", "Unable to create sharedprefs");
        }


        initViews();

        observerOmniMatchViewModelStatuses();
        observerOmniMatchViewModelResponses();
        observeCryptoViewModelChanges();


        matchFaces();


        return view;

    }


    private void observerOmniMatchViewModelStatuses() {

        mainActivityViewModel.isProcessing().observe(getViewLifecycleOwner(), aBoolean -> {

            if (aBoolean == null) {
                return;
            }

            binding.progressCircular.setVisibility(aBoolean ? View.VISIBLE : View.GONE);

        });

        mainActivityViewModel.getStatusMessage().observe(getViewLifecycleOwner(), s -> binding.txtStatusDesc.setText(s == null ? "" : s.asString(requireContext())));

        mainActivityViewModel.getErrorMessage().observe(getViewLifecycleOwner(), s -> binding.txtErrorMsg.setText(s == null ? "" : s.asString(requireContext())));

        mainActivityViewModel.getErrorMessage().observe(getViewLifecycleOwner(), s -> binding.txtErrorMsg.setText(s == null ? "" : s.asString(requireContext())));


    }


    private void observerOmniMatchViewModelResponses() {

        mainActivityViewModel.getCryptoStatus().observe(getViewLifecycleOwner(), aBoolean -> {

            Demographics demographics = sharedViewModel.getDemographics();

            if (Boolean.TRUE.equals(aBoolean)) {


                binding.txtStatus.setText(R.string.eid_created);


                String data = Utils.makeStringOfLength(demographics.getDocumentNumber(), 10) + "," + demographics.getFirstName() + "," + demographics.getLastName() + "," + demographics.getDob();

                cryptographViewModel.validateCryptographSignature(mauritaniaSharedPreferences.getRsaPublicKey(), data);


            }

        });


        mainActivityViewModel.getMatchResult().observe(getViewLifecycleOwner(), recordResult -> {

            if (recordResult == null) {
                return;
            }

            if (recordResult.getCandidate().getScores().getFace().getLogFAR() >= 4.0) {

                binding.imgMatchStatus.setImageResource(R.drawable.done);
                binding.imgMatchStatus.setVisibility(View.VISIBLE);

                binding.txtStatus.setText(getResources().getString(R.string.face_match_success));


                Demographics demographics = sharedViewModel.getDemographics();

                mainActivityViewModel.createCryptograph(Utils.makeStringOfLength(demographics.getDocumentNumber(), 10), demographics.getFirstName(), demographics.getLastName(), demographics.getDob());


            } else {

                binding.imgMatchStatus.setImageResource(R.drawable.error);
                binding.imgMatchStatus.setVisibility(View.VISIBLE);
                binding.txtStatus.setText(getResources().getString(R.string.face_verification_failed));

                binding.btnRecapture.setVisibility(View.VISIBLE);
            }


        });


        mainActivityViewModel.getRegistrationResponse().observe(getViewLifecycleOwner(), registrationResponse -> {

            if (registrationResponse != null && registrationResponse.getValue() != null) {

                String password = registrationResponse.getValue();

                appSharedPreference.setFirstName(sharedViewModel.getDemographics().getFirstName());
                appSharedPreference.setLastName(sharedViewModel.getDemographics().getLastName());
                appSharedPreference.setDob(sharedViewModel.getDemographics().getDob());
                appSharedPreference.setPob(sharedViewModel.getDemographics().getPob());
                appSharedPreference.setNNI(sharedViewModel.getDemographics().getDocumentNumber());
                appSharedPreference.setGender(sharedViewModel.getDemographics().getGender());
                appSharedPreference.setPhone(sharedViewModel.getDemographics().getPhone());
                appSharedPreference.setNationality(sharedViewModel.getDemographics().getNationality());
                appSharedPreference.setIssueDate(sharedViewModel.getDemographics().getIssueDate());
                appSharedPreference.setExpiryDate(sharedViewModel.getDemographics().getDateOfExpiry());


                appSharedPreference.setPassword(password);


                appSharedPreference.setIsVerifiedProfile(true);

                binding.txtStatus.setText(getResources().getString(R.string.face_match_success));
                binding.txtStatusDesc.setText(R.string.eid_ready_to_use);
                binding.btnConnect.setVisibility(View.VISIBLE);


            } else {

                Toast.makeText(requireContext(), getResources().getString(R.string.registartion_failed), Toast.LENGTH_LONG).show();

            }

        });
    }


    void observeCryptoViewModelChanges() {


        cryptographViewModel.isProcessing().observe(getViewLifecycleOwner(), aBoolean -> {

            if (aBoolean == null) {
                return;
            }

            binding.progressCircular.setVisibility(aBoolean ? View.VISIBLE : View.GONE);

        });


        cryptographViewModel.getStatusMessage().observe(getViewLifecycleOwner(), s -> {

            if (s == null) {
                binding.txtStatusDesc.setText("");
                return;
            }

            binding.txtStatusDesc.setText(s.asString(requireContext()));

        });


        cryptographViewModel.getErrorMessage().observe(getViewLifecycleOwner(), s -> {

            if (s == null) {
                binding.txtStatus.setText("");
                return;
            }


            binding.txtErrorMsg.setText(s.asString(requireContext()));

        });


        cryptographViewModel.isSignatureValidated().observe(getViewLifecycleOwner(), aBoolean -> {


            Log.d("TAG", "isSignatureValidated: " + aBoolean);

            if (Boolean.TRUE.equals(aBoolean)) {

                Demographics demographics = sharedViewModel.getDemographics();

               
                binding.txtStatus.setText(R.string.signature_validated);


                mainActivityViewModel.registerUser(Utils.makeStringOfLength(demographics.getDocumentNumber(), 10), demographics.getFirstName(), demographics.getLastName(), demographics.getDob());


            } else {
                Toast.makeText(requireContext(), getResources().getString(R.string.signature_verification_failed), Toast.LENGTH_LONG).show();
            }
        });


    }

    void initViews() {


        binding.progressLayoutInclude.progressIndicator.setProgress(100);
        binding.progressLayoutInclude.progressIndicatorText.setText("3 of 3");
        binding.progressLayoutInclude.progressLayoutHeading.setText(getResources().getString(R.string.label_face_match));
        binding.progressLayoutInclude.progressLayoutDesc.setText(getResources().getString(R.string.start_using_eid));


        binding.btnConnect.setOnClickListener(v -> {

            Navigation.findNavController(binding.getRoot()).navigate(R.id.action_faceMatchingFragment_to_sendMoneyGraph);

            //clear all values
            sharedViewModel.setDemographics(null);
            sharedViewModel.setExtractedFaceImageFromNfc(null);
            sharedViewModel.setLiveFaceImage(null);
            sharedViewModel.setHasNfcPage(false);
            sharedViewModel.setExtractedFaceImageFromOcr(null);

        });


        binding.btnRecapture.setOnClickListener(v -> Navigation.findNavController(binding.getRoot()).navigate(R.id.action_faceMatchingFragment_to_faceCaptureFragment));

    }


    private void matchFaces() {

        byte[] extractedFaceImage = bitmapToBytes(sharedViewModel.getExtractedFaceImageFromNfc());

        if (extractedFaceImage.length == 0) {

            extractedFaceImage = bitmapToBytes(sharedViewModel.getExtractedFaceImageFromOCR());
        }

        mainActivityViewModel.matchFaceImages(extractedFaceImage, sharedViewModel.getLiveFaceImage(), Common.ImageFormat.JPEG);
    }


}
