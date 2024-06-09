package com.example.lab2;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.widget.ArrayAdapter;
import android.widget.ListView;

public class Bai1 extends AppCompatActivity {
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.list_item_bai1);
        ListView lvPerson = (ListView) findViewById(R.id.name_list);
        final String arr[] ={"Teo", "Ti", "Bin", "Bo"};
        ArrayAdapter<String> adapter = new ArrayAdapter<String>(this, R.layout.list_item_bai1, R.id.title, arr);
        lvPerson.setAdapter(adapter);
    }
}