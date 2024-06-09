package com.example.lab2_2;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.view.View;
import android.widget.AdapterView;
import android.widget.ArrayAdapter;
import android.widget.Button;
import android.widget.EditText;
import android.widget.ListView;
import android.widget.TextView;

import java.util.ArrayList;

public class MainActivity extends AppCompatActivity {
    ListView lv;
    ArrayList<String> names;
    Button btn;
    ArrayAdapter<String> adapter;
    EditText input;
    TextView index;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        lv = (ListView) findViewById(R.id.show_name);
        btn = (Button) findViewById(R.id.btn);
        input = (EditText) findViewById(R.id.input);
        index = (TextView) findViewById((R.id.index));
        names = new ArrayList<String>();
        adapter = new ArrayAdapter<String>(this, android.R.layout.simple_list_item_1, names);
        lv.setAdapter(adapter);
        btn.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                names.add(input.getText().toString());
                adapter.notifyDataSetChanged();
            }
        });
        lv.setOnItemClickListener(new AdapterView.OnItemClickListener() {
            @Override
            public void onItemClick(AdapterView<?> parent, View view, int position, long id) {
                String value = lv.getItemAtPosition(position).toString();
                index.setText("Position :" + position+ " ; Value = " + value);
            }
        });
        lv.setOnItemLongClickListener(new AdapterView.OnItemLongClickListener() {
            @Override
            public boolean onItemLongClick(AdapterView<?> parent, View view, int position, long id) {
                names.remove(position);
                index.setText(" ");
                adapter.notifyDataSetChanged();
                return false;
            }
        });
    }
}