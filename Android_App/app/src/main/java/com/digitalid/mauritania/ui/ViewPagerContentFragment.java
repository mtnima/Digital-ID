package com.digitalid.mauritania.ui;

import android.os.Bundle;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;

import androidx.annotation.NonNull;
import androidx.annotation.Nullable;
import androidx.core.content.ContextCompat;
import androidx.fragment.app.Fragment;

import com.digitalid.mauritania.R;
import com.digitalid.mauritania.databinding.ViewpagerContentFragemntBinding;

public class ViewPagerContentFragment extends Fragment {

    ViewpagerContentFragemntBinding binding;

    private static final int[] images = {R.drawable.welcome, R.drawable.tutorial, R.drawable.verified_identity,
            R.drawable.secure_login,R.drawable.start_identity_verification};


    @Nullable
    @Override
    public View onCreateView(@NonNull LayoutInflater inflater, @Nullable ViewGroup container, @Nullable Bundle savedInstanceState) {


        binding = ViewpagerContentFragemntBinding.inflate(inflater, container, false);
        View view = binding.getRoot();


        String[] headings = getResources().getStringArray(R.array.intro_page_headings);
        String[] subHeadings = getResources().getStringArray(R.array.intro_page_sub_headings);


        int page = getArguments().getInt("index");




        binding.introImg.setImageDrawable(ContextCompat.getDrawable(requireContext(), images[page]));

        binding.introHeading.setText(headings[page]);
        binding.introDesription.setText(subHeadings[page]);


        return view;
    }
}
