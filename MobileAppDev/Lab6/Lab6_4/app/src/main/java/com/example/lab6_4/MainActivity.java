package com.example.lab6_4;

import android.os.Bundle;
import androidx.activity.EdgeToEdge;
import androidx.appcompat.app.AppCompatActivity;
import androidx.core.graphics.Insets;
import androidx.core.view.ViewCompat;
import androidx.core.view.WindowInsetsCompat;
import androidx.fragment.app.Fragment;
import androidx.fragment.app.FragmentActivity;
import androidx.viewpager2.adapter.FragmentStateAdapter;
import androidx.viewpager2.widget.ViewPager2;

import java.util.ArrayList;
import java.util.List;

public class MainActivity extends FragmentActivity {
        private ViewPager2 viewPager;
        private FragmentStateAdapter pagerAdapter;

        @Override
        protected void onCreate(Bundle savedInstanceState) {
            super.onCreate(savedInstanceState);
            setContentView(R.layout.screen_slide);
            viewPager = findViewById(R.id.pager);
            pagerAdapter = new ScreenSlidePagerAdapter(this);
            ((ScreenSlidePagerAdapter) pagerAdapter).addFragment(ScreenSlidePageFragment.newInstance(
                    "Elizabeth Johnson", "Project Manager", "elizabethjohnson@example.com"
            ));
            ((ScreenSlidePagerAdapter) pagerAdapter).addFragment(ScreenSlidePageFragment.newInstance(
                    "Catherine Johnson", "President of Sales", "catherinejohnson@example.com"
            ));
            viewPager.setAdapter(pagerAdapter);
            viewPager.setPageTransformer(new DepthPageTransformer());
        }

        @Override
        public void onBackPressed() {
            if (viewPager.getCurrentItem() == 0) {
                super.onBackPressed();
            }
            else
            {
                viewPager.setCurrentItem(viewPager.getCurrentItem() - 1);
            }
        }

        private class ScreenSlidePagerAdapter extends FragmentStateAdapter {
            private final List<Fragment> fragmentList = new ArrayList<>();

            public ScreenSlidePagerAdapter(FragmentActivity fa) {
                super(fa);
            }

            public void addFragment(Fragment fragment) {
                fragmentList.add(fragment);
            }

            @Override
            public Fragment createFragment(int position) {
                return fragmentList.get(position);
            }

            @Override
            public int getItemCount() {
                return fragmentList.size();
            }
        }
    }
