package com.digitalid.mauritania.ui;

import android.os.Bundle;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.TextView;

import androidx.annotation.NonNull;
import androidx.annotation.Nullable;
import androidx.fragment.app.Fragment;
import androidx.lifecycle.ViewModelProvider;
import androidx.navigation.Navigation;

import com.digitalid.mauritania.R;
import com.digitalid.mauritania.databinding.VerifyDemographicsScreenBinding;
import com.digitalid.mauritania.models.Demographics;
import com.digitalid.mauritania.viewmodel.SharedViewModel;

public class DemographicsVerifyFragment extends Fragment {


    VerifyDemographicsScreenBinding binding;

    private SharedViewModel sharedViewModel = null;

    @Nullable
    @Override
    public View onCreateView(@NonNull LayoutInflater inflater, @Nullable ViewGroup container, @Nullable Bundle savedInstanceState) {

        binding = VerifyDemographicsScreenBinding.inflate(inflater, container, false);
        View view = binding.getRoot();
        sharedViewModel = new ViewModelProvider(requireActivity()).get(SharedViewModel.class);


        initViews(view);

        binding.btnNext.setOnClickListener(v -> {
            //
            if (sharedViewModel.hasNfcPage()) {
                Navigation.findNavController(binding.getRoot()).navigate(R.id.action_demographics_verify_fragment_to_nfc_fragemnt);
            } else {
                Navigation.findNavController(binding.getRoot()).navigate(R.id.action_demographics_verify_fragment_to_faceCaptureFragment);
            }
        });


        binding.btnBack.setOnClickListener(v -> Navigation.findNavController(binding.getRoot())
                .navigate(R.id.action_demographics_verify_fragment_to_intro_fragment));


        return view;

    }

    private void initViews(View view) {

        TextView txtNNN = view.findViewById(R.id.txt_nnn);
        TextView txtFirstName = view.findViewById(R.id.txt_first_name);
        TextView txtLqstName = view.findViewById(R.id.txt_last_name);
        TextView txtDob = view.findViewById(R.id.txt_dob);
        TextView txtExpiry = view.findViewById(R.id.txt_expiry);

        String nnn = "-";
        String firstName = "-";
        String lastName = "-";
        String dob = "-";
        String expiry = "-";

        Demographics demographics = sharedViewModel.getDemographics();

        if (demographics == null) {
            return;
        }

        if (demographics.getDocumentNumber() != null && !demographics.getDocumentNumber().isEmpty()) {

            nnn = demographics.getDocumentNumber();

        }

        if (demographics.getFirstName() != null && !demographics.getFirstName().isEmpty()) {

            firstName = demographics.getFirstName();

        }

        if (demographics.getLastName() != null && !demographics.getLastName().isEmpty()) {

            lastName = demographics.getLastName();

        }

        if (demographics.getDob() != null && !demographics.getDob().isEmpty()) {

            dob = demographics.getDob();

        }

        if (demographics.getDateOfExpiry() != null && !demographics.getDateOfExpiry().isEmpty()) {

            expiry = demographics.getDateOfExpiry();

        }


        txtNNN.setText(nnn);
        txtFirstName.setText(firstName);
        txtLqstName.setText(lastName);
        txtDob.setText(dob);
        txtExpiry.setText(expiry);


    }
}
