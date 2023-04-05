package com.digitalid.mauritania.ui;

import android.graphics.Bitmap;
import android.graphics.BitmapFactory;
import android.os.Bundle;
import android.util.Log;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.Toast;

import androidx.annotation.NonNull;
import androidx.annotation.Nullable;
import androidx.fragment.app.Fragment;

import com.digitalid.mauritania.databinding.HomeFragemntBinding;
import com.digitalid.mauritania.utils.LoginSharedPreferences;

import java.io.IOException;
import java.security.GeneralSecurityException;

public class HomeFragment extends Fragment {

    HomeFragemntBinding binding;


    @Nullable
    @Override
    public View onCreateView(@NonNull LayoutInflater inflater, @Nullable ViewGroup container, @Nullable Bundle savedInstanceState) {


        binding = HomeFragemntBinding.inflate(inflater, container, false);
        View view = binding.getRoot();

        LoginSharedPreferences appSharedPreference = null;
        try {
            appSharedPreference = new LoginSharedPreferences(requireContext());
        } catch (GeneralSecurityException | IOException e) {
            Log.d("TAG", "Unable to create sharedprefs");
        }

        if (appSharedPreference == null) {
            Toast.makeText(requireContext(), "Something wrong", Toast.LENGTH_LONG).show();
            return view;
        }

        try {

            Bitmap faceImage = BitmapFactory.decodeFile(appSharedPreference.getFaceImagePath());

            binding.imgProfile.setImageBitmap(faceImage);


        } catch (Exception e) {

            binding.imgProfile.setImageBitmap(null);

        }

        binding.txtFirstName.setText(appSharedPreference.getFirstName());


        binding.txtNnn.setText(appSharedPreference.getNNI());
        binding.txtDob.setText(appSharedPreference.getDOB());
        binding.txtPob.setText(appSharedPreference.getPOB());
        binding.txtDateOfIssue.setText(appSharedPreference.getIssueDate());
        binding.txtGender.setText(appSharedPreference.getGender());
        binding.txtExpiryDate.setText(appSharedPreference.getExpiryDate());
        binding.txtNationality.setText(appSharedPreference.getNationality());
        binding.txtPhone.setText(appSharedPreference.getPhone());


        return view;

    }


    @Override
    public void onResume() {
        super.onResume();

        NavGraphActivity navGraphActivity = (NavGraphActivity) getActivity();

        navGraphActivity.getBottomNavigationView().setVisibility(View.VISIBLE);
    }
}
