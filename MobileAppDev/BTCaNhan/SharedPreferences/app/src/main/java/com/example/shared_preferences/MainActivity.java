package com.example.shared_preferences;

import androidx.appcompat.app.AppCompatActivity;

import android.content.SharedPreferences;
import android.graphics.Typeface;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.TextView;
import android.widget.Toast;

import java.util.Date;

public class MainActivity extends AppCompatActivity implements View.OnClickListener {
    Button simplePref, fancyPref;
    TextView caption;
    boolean fancyPrefChosen = false;
    View myLayout1Vertical;
    final int mode = AppCompatActivity.MODE_PRIVATE;
    final String MYPREFS = "MyPreferences_001";
    SharedPreferences mySharedPreferences;
    SharedPreferences.Editor myEditor;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        myLayout1Vertical = (View) findViewById(R.id.linLayout1Vertical);
        caption = (TextView) findViewById(R.id.txtCaption1);
        caption.setText("This is a sample line suggesting the way the UI looks after you choose your preference");
        mySharedPreferences = getSharedPreferences(MYPREFS, 0);
        myEditor = mySharedPreferences.edit();
        if (mySharedPreferences != null && mySharedPreferences.contains("backColor"))
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
    public void onClick(View v) {
        myEditor.clear();
        if (v.getId() == simplePref.getId()) {
            myEditor.putInt("backColor", R.color.black);
            myEditor.putInt("textSize", 12);
        } else { // case btnFancyPref
            myEditor.putInt("backColor", R.color.blue);
            myEditor.putInt("textSize", 20);
            myEditor.putString("textStyle", "bold");
            myEditor.putInt("layoutColor", R.color.green);
        }
        myEditor.commit();
        applySavedPreferences();
    }
    @Override
    protected void onPause() {
        myEditor.putString("DateLastExecution", new Date().toLocaleString());
        myEditor.commit();
        super.onPause();
    }

    public void applySavedPreferences() {
        int backColor = mySharedPreferences.getInt("backColor",R.color.black);
        int textSize = mySharedPreferences.getInt("textSize", 12);
        String textStyle = mySharedPreferences.getString("textStyle", "normal");
        int layoutColor = mySharedPreferences.getInt("layoutColor", R.color.dkgray);
        String msg = "color " + backColor + "\n" + "size " + textSize
                + "\n" + "style " + textStyle;
        Toast.makeText(getApplicationContext(), msg, Toast.LENGTH_LONG).show();

        caption.setBackgroundColor(backColor);
        caption.setTextSize(textSize);
        if (textStyle.compareTo("normal")==0){
            caption.setTypeface(Typeface.SERIF,Typeface.NORMAL);
        }
        else
        {
            caption.setTypeface(Typeface.SERIF,Typeface.BOLD);
        }
        myLayout1Vertical.setBackgroundColor(layoutColor);
    }
}