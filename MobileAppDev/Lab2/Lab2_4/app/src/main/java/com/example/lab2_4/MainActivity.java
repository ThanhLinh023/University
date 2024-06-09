package com.example.lab2_4;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.CheckBox;
import android.widget.EditText;
import android.widget.ListView;

import java.util.ArrayList;

public class MainActivity extends AppCompatActivity {
    EditText id, name;
    CheckBox isMng;
    Button btn;
    ArrayList<Employee> emp;
    ListView lv;
    EmployeeAdapter e_adapter;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        id = (EditText) findViewById(R.id.id_input);
        name = (EditText) findViewById(R.id.name_input);
        isMng = (CheckBox) findViewById(R.id.check_box);
        btn = (Button) findViewById((R.id.btn));
        lv = (ListView) findViewById((R.id.list_view));
        emp = new ArrayList<Employee>();
        e_adapter = new EmployeeAdapter(this, R.layout.item_employee, emp);
        lv.setAdapter(e_adapter);
        btn.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                Employee tmp;
                if (isMng.isChecked())
                {
                    tmp = new Employee(id.getText().toString(), name.getText().toString(), true);
                }
                else
                {
                    tmp = new Employee(id.getText().toString(), name.getText().toString(), false);
                }
                emp.add(tmp);
                e_adapter.notifyDataSetChanged();
            }
        });
    }
}