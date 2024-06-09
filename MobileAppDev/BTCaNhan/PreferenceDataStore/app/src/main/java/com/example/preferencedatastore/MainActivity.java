package com.example.preferencedatastore;

import android.annotation.SuppressLint;
import android.graphics.Typeface;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.TextView;
import android.widget.Toast;

import androidx.appcompat.app.AppCompatActivity;
import androidx.datastore.preferences.core.MutablePreferences;
import androidx.datastore.preferences.core.Preferences;
import androidx.datastore.preferences.core.PreferencesKeys;
import androidx.datastore.preferences.rxjava3.RxPreferenceDataStoreBuilder;
import androidx.datastore.rxjava3.RxDataStore;

import java.util.concurrent.atomic.AtomicInteger;

import io.reactivex.rxjava3.core.Flowable;
import io.reactivex.rxjava3.core.Single;

public class MainActivity extends AppCompatActivity implements View.OnClickListener {
    Button simplePref, fancyPref;
    TextView caption;
    View myLayout1Vertical;
    RxDataStore<Preferences> dataStore;
    final int mode = AppCompatActivity.MODE_PRIVATE;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        myLayout1Vertical = (View) findViewById(R.id.linLayout1Vertical);
        caption = (TextView) findViewById(R.id.txtCaption1);
        caption.setText("This is a sample line suggesting the way the UI looks after you choose your preference");
        dataStore = new RxPreferenceDataStoreBuilder(this, /*name=*/ "PreferenceDataStore").build();
        Preferences.Key<String> EXAMPLE_COUNTER = PreferencesKeys.stringKey("PreferenceDataStore");

        Flowable<Integer> exampleCounterFlow = dataStore.data().map(prefs -> Integer.valueOf(prefs.get(EXAMPLE_COUNTER)));
        if (exampleCounterFlow != null && exampleCounterFlow.equals("backColor"))
        {
            applySavedPreferences();
        }
        else
        {
            Toast.makeText(getApplicationContext(), "No Preferences found", Toast.LENGTH_LONG).show();
        }
        simplePref = (Button) findViewById(R.id.btnPrefSimple);
        simplePref.setOnClickListener(this);
        fancyPref = (Button) findViewById(R.id.btnPrefFancy);
        fancyPref.setOnClickListener(this);
    }
    @SuppressLint("CheckResult")
    public void onClick(View v) {
        Preferences.Key<Integer> backColorKey = PreferencesKeys.intKey("backColor");
        Preferences.Key<Integer> textSizeKey = PreferencesKeys.intKey("textSize");
        Preferences.Key<String> textStyleKey = PreferencesKeys.stringKey("textStyle");
        Preferences.Key<Integer> layoutColorKey = PreferencesKeys.intKey("layoutColor");

        dataStore.updateDataAsync(preferences -> {
            MutablePreferences mutablePreferences = preferences.toMutablePreferences();

            if (v.getId() == simplePref.getId())
            {
                mutablePreferences.remove(backColorKey);
                mutablePreferences.set(backColorKey, R.color.black);
                mutablePreferences.remove(textSizeKey);
                mutablePreferences.set(textSizeKey, 12);
            }
            else if (v.getId() == fancyPref.getId())
            {
                mutablePreferences.remove(backColorKey);
                mutablePreferences.set(backColorKey, R.color.blue);
                mutablePreferences.remove(textSizeKey);
                mutablePreferences.set(textSizeKey, 20);
                mutablePreferences.remove(textStyleKey);
                mutablePreferences.set(textStyleKey, "bold");
                mutablePreferences.remove(layoutColorKey);
                mutablePreferences.set(layoutColorKey, R.color.green);
            }
            return Single.just(mutablePreferences);
        }).subscribe(preferences -> {
            applySavedPreferences();
        });
    }
    public void applySavedPreferences() {
        Preferences.Key<Integer> backColorKey = PreferencesKeys.intKey("backColor");
        Preferences.Key<Integer> textSizeKey = PreferencesKeys.intKey("textSize");
        Preferences.Key<String> textStyleKey = PreferencesKeys.stringKey("textStyle");
        Preferences.Key<Integer> layoutColorKey = PreferencesKeys.intKey("layoutColor");

        dataStore.data().subscribe(preferences -> {
            int backColor = preferences.get(backColorKey);
            int textSize = preferences.get(textSizeKey);
            String textStyle = preferences.get(textStyleKey);
            int layoutColor = preferences.get(layoutColorKey);

            String msg = "color " + backColor + "\n" + "size " + textSize
                    + "\n" + "style " + textStyle;
            Toast.makeText(getApplicationContext(), msg, Toast.LENGTH_LONG).show();

            caption.setBackgroundColor(backColor);
            caption.setTextSize(textSize);
            if (textStyle.compareTo("normal") == 0) {
                caption.setTypeface(Typeface.SERIF, Typeface.NORMAL);
            } else {
                caption.setTypeface(Typeface.SERIF, Typeface.BOLD);
            }
            myLayout1Vertical.setBackgroundColor(layoutColor);
        });
    }
}