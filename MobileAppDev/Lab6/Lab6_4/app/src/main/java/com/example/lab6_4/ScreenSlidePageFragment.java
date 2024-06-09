package com.example.lab6_4;

import androidx.fragment.app.Fragment;
import android.os.Bundle;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.TextView;
import androidx.constraintlayout.widget.ConstraintLayout;

public class ScreenSlidePageFragment extends Fragment {
    private static final String ARG_NAME = "name";
    private static final String ARG_POSITION = "position";
    private static final String ARG_EMAIL = "email";
    private String name, position, email;

    public ScreenSlidePageFragment() {
    }
    public static ScreenSlidePageFragment newInstance(String name, String position, String email) {
        ScreenSlidePageFragment fragment = new ScreenSlidePageFragment();
        Bundle args = new Bundle();
        args.putString(ARG_NAME, name);
        args.putString(ARG_POSITION, position);
        args.putString(ARG_EMAIL, email);
        fragment.setArguments(args);
        return fragment;
    }
    @Override
    public void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        if (getArguments() != null) {
            name = getArguments().getString(ARG_NAME);
            position = getArguments().getString(ARG_POSITION);
            email = getArguments().getString(ARG_EMAIL);
        }
    }
    @Override
    public View onCreateView(LayoutInflater inflater, ViewGroup container,Bundle savedInstanceState) {
        View view =  inflater.inflate(R.layout.activity_main, container, false);
        TextView nameTextView = view.findViewById(R.id.john);
        TextView positionTextView = view.findViewById(R.id.role);
        TextView emailTextView = view.findViewById(R.id.mail);
        ConstraintLayout layout = view.findViewById(R.id.content);
        nameTextView.setText(name);
        positionTextView.setText(position);
        emailTextView.setText(email);
        return view;
    }
}
