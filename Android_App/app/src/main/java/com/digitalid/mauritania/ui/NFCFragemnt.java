package com.digitalid.mauritania.ui;

import android.annotation.SuppressLint;
import android.graphics.Bitmap;
import android.os.Bundle;
import android.util.Log;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.Toast;

import androidx.annotation.NonNull;
import androidx.annotation.Nullable;
import androidx.fragment.app.Fragment;
import androidx.lifecycle.MutableLiveData;
import androidx.lifecycle.ViewModelProvider;
import androidx.navigation.Navigation;

import com.digitalid.mauritania.R;
import com.digitalid.mauritania.databinding.StartNfcScreenBinding;
import com.digitalid.mauritania.models.Demographics;
import com.digitalid.mauritania.utils.DocumentResultsUtil;
import com.digitalid.mauritania.utils.Utils;
import com.digitalid.mauritania.viewmodel.SharedViewModel;
import com.regula.documentreader.api.DocumentReader;
import com.regula.documentreader.api.completions.IDocumentReaderCompletion;
import com.regula.documentreader.api.enums.DocReaderAction;
import com.regula.documentreader.api.enums.eGraphicFieldType;
import com.regula.documentreader.api.enums.eRPRM_ResultType;
import com.regula.documentreader.api.enums.eVisualFieldType;
import com.regula.documentreader.api.results.DocumentReaderResults;


public class NFCFragemnt extends Fragment {

    private StartNfcScreenBinding binding;

    private final MutableLiveData<Bitmap> faceImgFromNfc = new MutableLiveData<>();
    private SharedViewModel sharedViewModel;

    @Nullable
    @Override
    public View onCreateView(@NonNull LayoutInflater inflater, @Nullable ViewGroup container, @Nullable Bundle savedInstanceState) {

        binding = StartNfcScreenBinding.inflate(inflater, container, false);
        View view = binding.getRoot();

        sharedViewModel = new ViewModelProvider(requireActivity()).get(SharedViewModel.class);

        binding.progressLayoutInclude.progressIndicator.setProgress(66);
        binding.progressLayoutInclude.progressIndicatorText.setText("2 of 3");
        binding.progressLayoutInclude.progressLayoutHeading.setText(getResources().getString(R.string.start_data_transfer));
        binding.progressLayoutInclude.progressLayoutDesc.setText(getResources().getString(R.string.label_next_face_match));

        binding.subHeading.setText(getResources().getString(R.string.start_data_transfer));
        binding.txtDesc.setText(getResources().getString(R.string.label_nfc_steps_to_follow));


        binding.btnNext.setOnClickListener(v -> startNFCReading());

        binding.btnBack.setOnClickListener(v -> Navigation.findNavController(binding.getRoot())
                .navigate(R.id.action_nfc_fragemnt_to_intro_fragment));


        faceImgFromNfc.observe(getViewLifecycleOwner(), bitmap -> {

            if (bitmap != null) {
                navigateToNfcSuccess();
            }

        });


        return view;
    }


    @SuppressLint("MissingPermission")
    private void startNFCReading() {

        DocumentReader.Instance().startRFIDReader(requireContext(), completion);
    }

    private void navigateToNfcSuccess() {

        Navigation.findNavController(binding.getRoot()).navigate(R.id.action_nfc_fragemnt_to_nfc_success_fragemnt);
        faceImgFromNfc.postValue(null);


    }


    @SuppressLint("MissingPermission")
    private IDocumentReaderCompletion completion = (action, documentReaderResults, error) -> {


        Log.d("TAG", "action " + action);

        if (action == DocReaderAction.COMPLETE || action == DocReaderAction.CANCEL) {

            Log.d("TAG", "scan complete isRFID available :" + DocumentReader.Instance().isRFIDAvailableForUse() + " chip Page : " + (documentReaderResults.chipPage != 0));

            processNFCResults(documentReaderResults);

        } else {
            //something happened before all results were ready
            if (action == DocReaderAction.CANCEL) {
                Toast.makeText(getActivity(), getResources().getString(R.string.nfc_cancelled), Toast.LENGTH_LONG).show();
            } else if (action == DocReaderAction.ERROR) {
                Toast.makeText(getActivity(), "NFC Error:" + error.getLocalizedMessage(), Toast.LENGTH_LONG).show();
            }
        }

    };


    private void processNFCResults(DocumentReaderResults documentReaderResults) {

        if (documentReaderResults == null) {
            Toast.makeText(requireContext(), getResources().getString(R.string.nfc_failed), Toast.LENGTH_LONG).show();
            return;
        }


        updateDemographics(documentReaderResults);


        Bitmap faceImage = documentReaderResults.getGraphicFieldImageByType(eGraphicFieldType.GF_PORTRAIT, eRPRM_ResultType.RFID_RESULT_TYPE_RFID_IMAGE_DATA);


        if (faceImage != null) {

            faceImgFromNfc.postValue(faceImage);
            sharedViewModel.setExtractedFaceImageFromNfc(faceImage);

        } else {
            Toast.makeText(requireContext(), getResources().getString(R.string.extaract_facenfc_failed), Toast.LENGTH_LONG).show();
        }

    }

    /*
  Override demographics from OCR with details extracted from NFC chip
 */
    private void updateDemographics(DocumentReaderResults documentReaderResults) {


        if (documentReaderResults == null) {
            return;
        }


        String firstName = DocumentResultsUtil.getFirstName(documentReaderResults);
        String lastName = DocumentResultsUtil.getLastName(documentReaderResults);

        String documentNumber = DocumentResultsUtil.getDocumentNumber(documentReaderResults);


        String dob = DocumentResultsUtil.getValueByFieldType(documentReaderResults, eVisualFieldType.FT_DATE_OF_BIRTH);
        String placeOfBirth = DocumentResultsUtil.getValueByFieldType(documentReaderResults, eVisualFieldType.FT_PLACE_OF_BIRTH);
        String expiryDate = DocumentResultsUtil.getValueByFieldType(documentReaderResults, eVisualFieldType.FT_DATE_OF_EXPIRY);
        String phone = DocumentResultsUtil.getValueByFieldType(documentReaderResults, eVisualFieldType.FT_PHONE);
        String nationality = DocumentResultsUtil.getValueByFieldType(documentReaderResults, eVisualFieldType.FT_NATIONALITY);
        String gender = DocumentResultsUtil.getValueByFieldType(documentReaderResults, eVisualFieldType.FT_SEX);


        String issueDate = DocumentResultsUtil.getIssueDate(documentReaderResults);


        if (dob.length() > 12) {
            dob = Utils.trimString(dob, 12);
        }


        Demographics demographics = sharedViewModel.getDemographics();

        if (documentNumber != null) {
            demographics.setDocumentNumber(documentNumber);
        }

        if (!firstName.equals("-")) {
            demographics.setFirstName(firstName);
        }

        if (lastName.equals("-")) {
            demographics.setLastName(lastName);
        }

        if (!dob.equals("-")) {
            demographics.setDob(dob);
        }

        if (!placeOfBirth.equals("-")) {
            demographics.setPob(placeOfBirth);
        }

        if (!expiryDate.equals("-")) {
            demographics.setDateOfExpiry(expiryDate);
        }

        if (!expiryDate.equals("-")) {
            demographics.setDateOfExpiry(expiryDate);
        }

        if (!phone.equals("-")) {
            demographics.setPhone(phone);
        }

        if (!nationality.equals("-")) {
            demographics.setNationality(nationality);
        }

        if (!gender.equals("-")) {
            demographics.setGender(gender);
        }


        if (!issueDate.equals("-")) {
            demographics.setIssueDate(issueDate);
        }


    }
}
