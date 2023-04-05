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
import androidx.viewpager2.widget.ViewPager2;

import com.digitalid.mauritania.R;
import com.digitalid.mauritania.databinding.IntroViewPagerFragmentBinding;
import com.digitalid.mauritania.models.Demographics;
import com.digitalid.mauritania.utils.DocumentResultsUtil;
import com.digitalid.mauritania.utils.Utils;
import com.digitalid.mauritania.viewmodel.SharedViewModel;
import com.google.android.material.tabs.TabLayoutMediator;
import com.regula.documentreader.api.DocumentReader;
import com.regula.documentreader.api.completions.IDocumentReaderCompletion;
import com.regula.documentreader.api.enums.DocReaderAction;
import com.regula.documentreader.api.enums.eGraphicFieldType;
import com.regula.documentreader.api.enums.eVisualFieldType;
import com.regula.documentreader.api.results.DocumentReaderResults;

public class IntroViewPagerFragment extends Fragment {

    private static final int NUM_PAGES = 5;
    private IntroViewPagerFragmentBinding binding;
    private SharedViewModel sharedViewModel;

    private final MutableLiveData<Boolean> isDocumentReadingCompleted = new MutableLiveData<>();
    private final MutableLiveData<Boolean> hasNfcPage = new MutableLiveData<>();

    @Nullable
    @Override
    public View onCreateView(@NonNull LayoutInflater inflater, @Nullable ViewGroup container, @Nullable Bundle savedInstanceState) {

        binding = IntroViewPagerFragmentBinding.inflate(inflater, container, false);
        View view = binding.getRoot();


        initViews();


        sharedViewModel = new ViewModelProvider(requireActivity()).get(SharedViewModel.class);


        return view;
    }

    private void initViews() {

        IntroViewPagerAdapter adapter = new IntroViewPagerAdapter(this, NUM_PAGES);
        binding.introPager.setAdapter(adapter);

        TabLayoutMediator tabLayoutMediator = new TabLayoutMediator(binding.introTabLayout, binding.introPager, (tab, position) -> Log.d("TAG", "position : " + position));

        tabLayoutMediator.attach();


        binding.introPager.registerOnPageChangeCallback(new ViewPager2.OnPageChangeCallback() {


            @Override
            public void onPageSelected(int position) {
                super.onPageSelected(position);

                if (position == NUM_PAGES - 1) {
                    binding.btnSkip.setVisibility(View.GONE);
                    binding.btnContinue.setText(getResources().getString(R.string.lets_get_started));

                } else {
                    binding.btnSkip.setVisibility(View.VISIBLE);
                    binding.btnContinue.setText(getResources().getString(R.string.label_continue));

                }
            }


        });


        binding.btnContinue.setOnClickListener(v -> {

            int currentPage = binding.introPager.getCurrentItem();

            if (currentPage == NUM_PAGES - 1) {

                startDocumentReading();
            } else {
                binding.introPager.setCurrentItem(currentPage + 1);
            }

        });

        binding.btnSkip.setOnClickListener(v -> {

            int currentPage = binding.introPager.getCurrentItem();
            if (currentPage != NUM_PAGES - 1) {
                binding.introPager.setCurrentItem(NUM_PAGES - 1);
            }

        });


        isDocumentReadingCompleted.observe(getViewLifecycleOwner(), aBoolean -> {
            if (Boolean.TRUE == aBoolean) {


                Navigation.findNavController(binding.getRoot()).navigate(R.id.action_intro_fragment_to_demographics_verify_fragment);
                isDocumentReadingCompleted.postValue(false);
                hasNfcPage.postValue(false);
            }


        });
    }


    @SuppressLint("MissingPermission")
    private void startDocumentReading() {

        sharedViewModel.setDemographics(null);
        sharedViewModel.setExtractedFaceImageFromOcr(null);
        sharedViewModel.setExtractedFaceImageFromNfc(null);
        sharedViewModel.setHasNfcPage(false);

        DocumentReader.Instance().showScanner(requireContext(), completion);

    }


    private IDocumentReaderCompletion completion = (action, documentReaderResults, error) -> {


        Log.d("TAG", "action " + action);

        if (action == DocReaderAction.COMPLETE || action == DocReaderAction.TIMEOUT) {


            processDocumentScanningResults(documentReaderResults);


        } else {
            //something happened before all results were ready
            if (action == DocReaderAction.CANCEL) {
                Toast.makeText(getActivity(), getResources().getString(R.string.scanning_cancelled), Toast.LENGTH_LONG).show();
            } else if (action == DocReaderAction.ERROR) {
                Toast.makeText(getActivity(), "Error:" + error.getLocalizedMessage(), Toast.LENGTH_LONG).show();
            }
        }

    };


    private void processDocumentScanningResults(DocumentReaderResults documentScanResults) {


        if (documentScanResults == null) {
            return;
        }


        String firstName = DocumentResultsUtil.getFirstName(documentScanResults);
        String lastName = DocumentResultsUtil.getLastName(documentScanResults);

        String documentNumber = DocumentResultsUtil.getDocumentNumber(documentScanResults);


        String dob = DocumentResultsUtil.getValueByFieldType(documentScanResults, eVisualFieldType.FT_DATE_OF_BIRTH);
        String placeOfBirth = DocumentResultsUtil.getValueByFieldType(documentScanResults, eVisualFieldType.FT_PLACE_OF_BIRTH);
        String expiryDate = DocumentResultsUtil.getValueByFieldType(documentScanResults, eVisualFieldType.FT_DATE_OF_EXPIRY);
        String phone = DocumentResultsUtil.getValueByFieldType(documentScanResults, eVisualFieldType.FT_PHONE);
        String nationality = DocumentResultsUtil.getValueByFieldType(documentScanResults, eVisualFieldType.FT_NATIONALITY);
        String gender = DocumentResultsUtil.getValueByFieldType(documentScanResults, eVisualFieldType.FT_SEX);


        String issueDate = DocumentResultsUtil.getIssueDate(documentScanResults);


        if (dob.length() > 12) {
            dob = Utils.trimString(dob, 12);
        }


        Log.d("TAG", "documentNumber : " + documentNumber);
        Log.d("TAG", "firstName : " + firstName);
        Log.d("TAG", "lastName : " + lastName);
        Log.d("TAG", "dob : " + dob);

        if (Boolean.TRUE.equals(isDemographicsSuccessfullyRead(documentNumber, firstName, lastName, dob))) {

            String docNumber = Utils.makeStringOfLength(documentNumber, 10);

            Demographics demographics = new Demographics();
            demographics.setDocumentNumber(docNumber);
            demographics.setFirstName(firstName);
            demographics.setLastName(lastName);
            demographics.setDob(dob);
            demographics.setPob(placeOfBirth);
            demographics.setDateOfExpiry(expiryDate);
            demographics.setNationality(nationality);
            demographics.setGender(gender);
            demographics.setPhone(phone);
            demographics.setIssueDate(issueDate);


            sharedViewModel.setDemographics(demographics);


            boolean isNfcPagePresent = (DocumentReader.Instance().isRFIDAvailableForUse() && documentScanResults.chipPage != 0);

            hasNfcPage.postValue(isNfcPagePresent);

            if (isNfcPagePresent) {

                isDocumentReadingCompleted.postValue(true);
                sharedViewModel.setHasNfcPage(true);


            } else {

                Bitmap imageFromOCR = documentScanResults.getGraphicFieldImageByType(eGraphicFieldType.GF_PORTRAIT);


                if (imageFromOCR != null) {


                    sharedViewModel.setExtractedFaceImageFromOcr(imageFromOCR);
                    isDocumentReadingCompleted.postValue(true);
                    sharedViewModel.setHasNfcPage(false);

                } else {
                    Toast.makeText(getActivity(), getResources().getString(R.string.unable_to_extract_face), Toast.LENGTH_LONG).show();
                }
            }

        } else {
            Toast.makeText(getActivity(), getResources().getString(R.string.unable_to_extract_demographics), Toast.LENGTH_LONG).show();
        }


    }


    private boolean isDemographicsSuccessfullyRead(String documentNumber, String firstName, String lastName, String dob) {

        if (documentNumber == null) {
            return false;
        }

        return !firstName.equals("-") || !lastName.equals("-") || !dob.equals("-");
    }


}
