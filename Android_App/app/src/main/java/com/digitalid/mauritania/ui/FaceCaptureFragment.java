package com.digitalid.mauritania.ui;

import android.os.Bundle;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.Toast;

import androidx.fragment.app.Fragment;
import androidx.lifecycle.MutableLiveData;
import androidx.lifecycle.ViewModelProvider;
import androidx.navigation.Navigation;

import com.digitalid.mauritania.R;
import com.digitalid.mauritania.databinding.FaceCaptureFragmentBinding;
import com.digitalid.mauritania.viewmodel.SharedViewModel;
import com.phoenixcapture.camerakit.FaceBox;

import ai.tech5.pheonix.capture.controller.FaceCaptureController;
import ai.tech5.pheonix.capture.controller.FaceCaptureListener;


public class FaceCaptureFragment extends Fragment {

    FaceCaptureFragmentBinding binding;
    private SharedViewModel sharedViewModel;
    private MutableLiveData<byte[]> liveFaceImage = new MutableLiveData<>();

    private MutableLiveData<Integer> numTimesLivenessFailed = new MutableLiveData<>();


    private final FaceCaptureListener faceCaptureListener = new FaceCaptureListener() {
        @Override
        public void onFaceCaptured(byte[] bytes, FaceBox faceBox) {

            if (faceBox != null && faceBox.mLiveness >= 0.5) {

                liveFaceImage.postValue(bytes);
                sharedViewModel.setLiveFaceImage(bytes);

            } else {
                Toast.makeText(getActivity(), getResources().getString(R.string.liveness_failed), Toast.LENGTH_SHORT).show();
                if (numTimesLivenessFailed.getValue() != null) {
                    numTimesLivenessFailed.postValue(numTimesLivenessFailed.getValue() + 1);
                }
            }

        }


        @Override
        public void onTimedout(byte[] bytes) {
            Toast.makeText(getActivity(), getResources().getString(R.string.face_capture_timedout), Toast.LENGTH_LONG).show();
        }

        @Override
        public void onCancelled() {
            Toast.makeText(getActivity(), getResources().getString(R.string.face_capture_cancelled), Toast.LENGTH_LONG).show();
        }


        @Override
        public void OnFaceCaptureFailed(String s) {
            Toast.makeText(getActivity(), getResources().getString(R.string.face_capture_failed), Toast.LENGTH_LONG).show();
        }
    };

    @Override
    public View onCreateView(LayoutInflater inflater, ViewGroup container,
                             Bundle savedInstanceState) {

        binding = FaceCaptureFragmentBinding.inflate(inflater, container, false);
        View view = binding.getRoot();


        binding.progressLayoutInclude.progressIndicator.setProgress(100);
        binding.progressLayoutInclude.progressIndicatorText.setText("3 of 3");
        binding.progressLayoutInclude.progressLayoutHeading.setText(getResources().getString(R.string.label_face_match));
        binding.progressLayoutInclude.progressLayoutDesc.setText(getResources().getString(R.string.start_using_eid));

        binding.subHeading.setText(getResources().getString(R.string.label_verify));
        binding.txtDesc.setText(getResources().getString(R.string.match_data_from_id));


        sharedViewModel = new ViewModelProvider(requireActivity()).get(SharedViewModel.class);

        binding.btnScanFace.setOnClickListener(v -> captureFace());

        liveFaceImage.observe(getViewLifecycleOwner(), bytes -> {

            if (bytes != null && bytes.length > 0) {


                Navigation.findNavController(binding.getRoot()).navigate(R.id.action_faceCaptureFragment_to_faceMatchingFragment);
                liveFaceImage.postValue(null);
                numTimesLivenessFailed.postValue(0);
            }

        });

        numTimesLivenessFailed.observe(getViewLifecycleOwner(), integer -> {

            if (integer == null) {
                return;
            }

            if (integer >= 3) {
                binding.btnScanFace.setVisibility(View.GONE);
                Toast.makeText(requireContext(), getResources().getString(R.string.lable_liveness_failed_3_times), Toast.LENGTH_LONG).show();
            }

        });


        return view;
    }

    private void captureFace() {

        FaceCaptureController controller = FaceCaptureController.getInstance();
        controller.setAutoCapture(true);
        controller.setUseBackCamera(false);


        controller.startFaceCapture("", getActivity(), faceCaptureListener);
    }
}