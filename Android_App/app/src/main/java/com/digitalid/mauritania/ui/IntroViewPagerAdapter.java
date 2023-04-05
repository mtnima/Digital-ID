package com.digitalid.mauritania.ui;

import android.os.Bundle;

import androidx.annotation.NonNull;
import androidx.fragment.app.Fragment;
import androidx.viewpager2.adapter.FragmentStateAdapter;

public class IntroViewPagerAdapter extends FragmentStateAdapter {

    private int numPages;


    public IntroViewPagerAdapter(@NonNull Fragment fragment,int numPages) {
        super(fragment);
        this.numPages = numPages;
    }

    @NonNull
    @Override
    public Fragment createFragment(int position) {


        Fragment fragment = new ViewPagerContentFragment();


        Bundle bundle = new Bundle();
        bundle.putInt("index",position);

        fragment.setArguments(bundle);

        return fragment;
    }

    @Override
    public int getItemCount() {
        return numPages;
    }
}
