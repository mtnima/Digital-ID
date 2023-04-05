package com.digitalid.mauritania.ui;

import android.os.Bundle;
import android.util.Log;
import android.view.LayoutInflater;
import android.view.MenuItem;
import android.view.View;
import android.view.ViewGroup;

import androidx.activity.OnBackPressedCallback;
import androidx.annotation.NonNull;
import androidx.annotation.Nullable;
import androidx.fragment.app.Fragment;
import androidx.lifecycle.ViewModelProvider;
import androidx.navigation.Navigation;

import com.digitalid.mauritania.R;
import com.digitalid.mauritania.databinding.ThirdPartyResultBinding;
import com.digitalid.mauritania.utils.LoginSharedPreferences;
import com.digitalid.mauritania.utils.UiText;
import com.digitalid.mauritania.viewmodel.QRLoginViewModel;
import com.digitalid.mauritania.viewmodel.SharedViewModel;

import java.io.IOException;
import java.security.GeneralSecurityException;

public class ThirdPartyLoginResult extends Fragment {

    private LoginSharedPreferences loginSharedPreferences;
    private SharedViewModel sharedViewModel;
    private ThirdPartyResultBinding binding;
    private QRLoginViewModel qrLoginViewModel;

    @Nullable
    @Override
    public View onCreateView(@NonNull LayoutInflater inflater, @Nullable ViewGroup container, @Nullable Bundle savedInstanceState) {
        binding = ThirdPartyResultBinding.inflate(inflater, container, false);
        View view = binding.getRoot();


        sharedViewModel = new ViewModelProvider(requireActivity()).get(SharedViewModel.class);


        qrLoginViewModel = new ViewModelProvider(this).get(QRLoginViewModel.class);


        requireActivity().getOnBackPressedDispatcher().addCallback(getViewLifecycleOwner(), callback);

        binding.btnConnect.setOnClickListener(v -> handleOnBackPress());

        return view;
    }

    @Override
    public void onViewCreated(@NonNull View view, @Nullable Bundle savedInstanceState) {
        super.onViewCreated(view, savedInstanceState);


        try {
            loginSharedPreferences = new LoginSharedPreferences(requireContext());
        } catch (GeneralSecurityException | IOException e) {
            Log.d("TAG", "Unable to create encrypted sharedpreferences");
        }


        binding.btnRetry.setOnClickListener(v -> perfromQrLogin());


        qrLoginViewModel.isProcessing().observe(getViewLifecycleOwner(), aBoolean -> binding.progressCircular.setVisibility(Boolean.TRUE.equals(aBoolean) ? View.VISIBLE : View.GONE));


        qrLoginViewModel.getStatusMessage().observe(getViewLifecycleOwner(), this::handleStatusMessage);


        qrLoginViewModel.getQrLoginStatus().observe(getViewLifecycleOwner(), isLoggedIn -> {

            binding.progressLayout.setVisibility(View.GONE);
            binding.loginResult.setVisibility(View.VISIBLE);


            if (Boolean.TRUE.equals(isLoggedIn)) {

                binding.imgMatchStatus.setImageDrawable(getResources().getDrawable(R.drawable.done, null));
                binding.txtStatus.setText(getResources().getString(R.string.label_login_successful));
                binding.txtStatusDesc.setText(getResources().getString(R.string.login_success_description));
            } else {
                binding.imgMatchStatus.setImageDrawable(getResources().getDrawable(R.drawable.error, null));
                binding.txtStatus.setText(getResources().getString(R.string.label_login_error));
                binding.txtStatusDesc.setText(getResources().getString(R.string.login_error_description));
            }

        });


        perfromQrLogin();

    }


    private void perfromQrLogin() {

        if (Boolean.TRUE.equals(sharedViewModel.isNetworkAvailable())) {

            binding.btnRetry.setVisibility(View.GONE);
            binding.txtStatusDesc.setText("");

            //qrlogin start
            qrLoginViewModel.qrLogin(loginSharedPreferences.getNNI(), sharedViewModel.getQrcodeContent());


        } else {

            binding.btnRetry.setVisibility(View.VISIBLE);
            binding.txtStatusDesc.setText(getResources().getString(R.string.label_no_internet));

        }
    }


    private void handleStatusMessage(UiText s) {
        if (s == null) {
            binding.txtPtogressDesc.setText("");
            return;
        }



        binding.txtPtogressDesc.setText(s.asString(requireContext()));
    }

    OnBackPressedCallback callback = new OnBackPressedCallback(true /* enabled by default */) {

        @Override
        public void handleOnBackPressed() {

            handleOnBackPress();
        }
    };


    private void handleOnBackPress() {


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
