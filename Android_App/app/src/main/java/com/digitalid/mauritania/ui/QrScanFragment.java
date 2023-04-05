package com.digitalid.mauritania.ui;

import android.os.Bundle;
import android.util.Log;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;

import androidx.annotation.NonNull;
import androidx.annotation.Nullable;
import androidx.fragment.app.Fragment;
import androidx.lifecycle.ViewModelProvider;
import androidx.navigation.Navigation;

import com.digitalid.mauritania.R;
import com.digitalid.mauritania.camera.CameraException;
import com.digitalid.mauritania.databinding.QrReaderFragmentBinding;
import com.digitalid.mauritania.viewmodel.QRCodeReaderViewModel;
import com.digitalid.mauritania.viewmodel.SharedViewModel;
import com.google.mlkit.vision.barcode.common.Barcode;

public class QrScanFragment extends Fragment {

    QrReaderFragmentBinding binding;

    QRCodeReaderViewModel qrCodeReaderViewModel;

    SharedViewModel sharedViewModel;

    @Nullable
    @Override
    public View onCreateView(@NonNull LayoutInflater inflater, @Nullable ViewGroup container, @Nullable Bundle savedInstanceState) {

        Log.d("TAG", "onCreateView");

        binding = QrReaderFragmentBinding.inflate(inflater, container, false);
        View view = binding.getRoot();


        qrCodeReaderViewModel = new ViewModelProvider(this).get(QRCodeReaderViewModel.class);

        sharedViewModel = new ViewModelProvider(requireActivity()).get(SharedViewModel.class);
        sharedViewModel.setQrcodeContent(null);

        qrCodeReaderViewModel.getBarcode().observe(getViewLifecycleOwner(), barcode -> {

            if (barcode != null) {


                int valueType = barcode.getValueType();

                if (barcode.getValueType() == Barcode.TYPE_TEXT) {

                    String rawValue = barcode.getRawValue();

                    Log.d("TAG", "barcode raw :" + rawValue + " type : " + valueType);


                    qrCodeReaderViewModel.stopCamera();

                    sharedViewModel.setQrcodeContent(barcode.getRawValue());


                    showThirdPartyLogin();

                }


            }

        });


        return view;

    }


    @Override
    public void onViewCreated(@NonNull View view, @Nullable Bundle savedInstanceState) {
        binding.previewView.post(() -> {

            Log.d("TAG", "previewView : " + binding.previewView);


            try {
                qrCodeReaderViewModel.startCapture(this, binding.previewView);
            } catch (CameraException e) {
                Log.d("TAG", "Unable to start camera : " + e.getLocalizedMessage());
            }


        });
    }

    @Override
    public void onResume() {
        super.onResume();

        Log.d("TAG", "onResume called");
    }

    @Override
    public void onPause() {
        super.onPause();
        Log.d("TAG", "onPause called");

        qrCodeReaderViewModel.stopCamera();
    }

    private void showThirdPartyLogin() {


        Navigation.findNavController(binding.getRoot()).navigate(R.id.action_navigation_scan_to_blankFragment);


    }
}
