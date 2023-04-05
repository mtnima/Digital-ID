package com.digitalid.mauritania.ui;

import android.os.Bundle;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;

import androidx.annotation.NonNull;
import androidx.annotation.Nullable;
import androidx.fragment.app.Fragment;
import androidx.navigation.Navigation;

import com.digitalid.mauritania.R;
import com.digitalid.mauritania.databinding.NfcSuccessScreenBinding;

public class NFCSuccessFragemnt extends Fragment {

    NfcSuccessScreenBinding binding;

    @Nullable
    @Override
    public View onCreateView(@NonNull LayoutInflater inflater, @Nullable ViewGroup container, @Nullable Bundle savedInstanceState) {

        binding = NfcSuccessScreenBinding.inflate(inflater, container, false);
        View view = binding.getRoot();

        binding.progressLayoutInclude.progressIndicator.setProgress(66);
        binding.progressLayoutInclude.progressIndicatorText.setText("2 of 3");
        binding.progressLayoutInclude.progressLayoutHeading.setText(getResources().getString(R.string.start_data_transfer));
        binding.progressLayoutInclude.progressLayoutDesc.setText(getResources().getString(R.string.label_next_face_match));


        binding.btnNext.setOnClickListener(v -> Navigation.findNavController(binding.getRoot()).navigate(R.id.action_nfc_success_fragemnt_to_faceCaptureFragment));


        return view;

    }
}
