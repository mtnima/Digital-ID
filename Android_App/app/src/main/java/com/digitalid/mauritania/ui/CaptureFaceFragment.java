package com.digitalid.mauritania.ui;

import android.os.Bundle;
import android.view.LayoutInflater;
import android.view.MenuItem;
import android.view.View;
import android.view.ViewGroup;
import android.widget.Toast;

import androidx.activity.OnBackPressedCallback;
import androidx.annotation.NonNull;
import androidx.annotation.Nullable;
import androidx.fragment.app.Fragment;
import androidx.lifecycle.MutableLiveData;
import androidx.lifecycle.ViewModelProvider;
import androidx.navigation.Navigation;

import com.digitalid.mauritania.R;
import com.digitalid.mauritania.databinding.CryptoFaceMatchingFragmentBinding;
import com.digitalid.mauritania.viewmodel.SharedViewModel;
import com.phoenixcapture.camerakit.FaceBox;

import ai.tech5.pheonix.capture.controller.FaceCaptureController;
import ai.tech5.pheonix.capture.controller.FaceCaptureListener;

public class CaptureFaceFragment extends Fragment {

    CryptoFaceMatchingFragmentBinding binding;
    private final MutableLiveData<byte[]> liveFaceImage = new MutableLiveData<>();

    private final MutableLiveData<Integer> numTimesLivenessFailed = new MutableLiveData<>();




    @Nullable
    @Override
    public View onCreateView(@NonNull LayoutInflater inflater, @Nullable ViewGroup container, @Nullable Bundle savedInstanceState) {


        binding = CryptoFaceMatchingFragmentBinding.inflate(inflater, container, false);
        View view = binding.getRoot();


        requireActivity().getOnBackPressedDispatcher().addCallback(getViewLifecycleOwner(), callback);


        SharedViewModel   sharedViewModel = new ViewModelProvider(requireActivity()).get(SharedViewModel.class);




        binding.btnScanFace.setOnClickListener(v -> {
            FaceCaptureController controller = FaceCaptureController.getInstance();
            controller.setAutoCapture(true);
            controller.setUseBackCamera(false);

            controller.startFaceCapture("", requireContext(), faceCaptureListener);
        });


        liveFaceImage.observe(getViewLifecycleOwner(), bytes -> {

            if (bytes != null && bytes.length > 0) {

                liveFaceImage.postValue(null);
                numTimesLivenessFailed.postValue(0);

                sharedViewModel.setLiveFaceImage(bytes);

                Navigation.findNavController(binding.getRoot()).navigate(R.id.action_blankFragment_to_navigation_third_party_login_keycloak);


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


    OnBackPressedCallback callback = new OnBackPressedCallback(true /* enabled by default */) {

        @Override
        public void handleOnBackPressed() {

            Navigation.findNavController(binding.getRoot()).navigate(R.id.action_fragment4_to_loginGraph);

            NavGraphActivity navGraphActivity = (NavGraphActivity) getActivity();

            MenuItem item = navGraphActivity.getBottomNavigationView().getMenu().findItem(R.id.navigation_home);
            item.setChecked(true);
        }
    };


    @Override
    public void onResume() {
        super.onResume();

        NavGraphActivity navGraphActivity = (NavGraphActivity) getActivity();

        navGraphActivity.getBottomNavigationView().setVisibility(View.GONE);
    }

    private final FaceCaptureListener faceCaptureListener = new FaceCaptureListener() {
        @Override
        public void onFaceCaptured(byte[] bytes, FaceBox faceBox) {

            if (faceBox != null && faceBox.mLiveness >= 0.5) {

                liveFaceImage.postValue(bytes);


            } else {
                Toast.makeText(getActivity(), getResources().getString(R.string.liveness_failed), Toast.LENGTH_SHORT).show();
                if (numTimesLivenessFailed.getValue() != null) {
                    numTimesLivenessFailed.postValue(numTimesLivenessFailed.getValue() + 1);
                }
            }

        }

        @Override
        public void OnFaceCaptureFailed(String s) {
            Toast.makeText(getActivity(), getResources().getString(R.string.face_capture_failed), Toast.LENGTH_LONG).show();
        }

        @Override
        public void onCancelled() {
            Toast.makeText(getActivity(), getResources().getString(R.string.face_capture_cancelled), Toast.LENGTH_LONG).show();
        }

        @Override
        public void onTimedout(byte[] bytes) {
            Toast.makeText(getActivity(), getResources().getString(R.string.face_capture_timedout), Toast.LENGTH_LONG).show();
        }
    };
}
