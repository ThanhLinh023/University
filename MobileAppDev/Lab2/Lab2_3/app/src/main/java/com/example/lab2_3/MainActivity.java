package com.example.lab2_3;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.view.View;
import android.widget.AdapterView;
import android.widget.ArrayAdapter;
import android.widget.Button;
import android.widget.EditText;
import android.widget.ListView;
import android.widget.RadioButton;
import android.widget.TextView;

import org.w3c.dom.Text;

import java.util.ArrayList;

public class MainActivity extends AppCompatActivity {
    EditText id;
    EditText name;
    RadioButton full;
    RadioButton part;
    Button btn;
    TextView div;
    ListView lv;
    ArrayList<Employee> emp;
    ArrayAdapter<Employee> adapter;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        id = (EditText) findViewById(R.id.manv_input);
        name = (EditText) findViewById(R.id.ten_input);
        full = (RadioButton) findViewById(R.id.chinhthuc);
        part = (RadioButton) findViewById(R.id.thoivu);
        btn = (Button) findViewById(R.id.btn);
        div = (TextView) findViewById(R.id.div);
        lv = (ListView) findViewById(R.id.list);
        emp = new ArrayList<Employee>();
        adapter = new ArrayAdapter<Employee>(this, android.R.layout.simple_list_item_1, emp);
        lv.setAdapter(adapter);
        btn.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                if (!full.isChecked() && !part.isChecked())
                {
                    div.setText("Chọn loại nhân viên trước");
                }
                else if (full.isChecked())
                {
                    emp.add(addNew(id.getText().toString(), name.getText().toString(), 1));
                    div.setText("");
                }
                else
                {
                    emp.add(addNew(id.getText().toString(), name.getText().toString(), 2));
                    div.setText("");
                }
                adapter.notifyDataSetChanged();
            }
        });
    }
    public Employee addNew(String id, String name, int role)
    {
        Employee tmp;
        if (role == 1)
        {
            tmp =  new FullTimeEmployee(id, name);
        }
        else {
            tmp = new PartTimeEmployee(id, name);
        }
        return tmp;
    }
}