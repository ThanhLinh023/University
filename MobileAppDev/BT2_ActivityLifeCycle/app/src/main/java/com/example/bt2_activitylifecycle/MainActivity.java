package com.example.bt2_activitylifecycle;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.util.Log;

public class MainActivity extends AppCompatActivity {
    private static final String T = "Activity Life Cycle";
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        Log.i(T, "onCreate function is called");
    }
    @Override
    protected void onStart()
    {
        super.onStart();
        Log.i(T, "onStart function is called");
    }
    @Override
    protected void onResume()
    {
        super.onResume();
        Log.i(T, "onResume function is called");
    }
    @Override
    protected void onPause()
    {
        super.onPause();
        Log.i(T, "onPause function is called");
    }
    @Override
    protected void onRestart()
    {
        super.onRestart();
        Log.i(T, "onRestart function is called");
    }
    @Override
    protected void onStop()
    {
        super.onStop();
        Log.i(T, "onStop function is called");
    }
    @Override
    protected void onDestroy()
    {
        super.onDestroy();
        Log.i(T, "onDestroy function is called");
    }
}