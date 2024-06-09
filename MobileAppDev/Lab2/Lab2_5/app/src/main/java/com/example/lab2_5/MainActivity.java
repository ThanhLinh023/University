package com.example.lab2_5;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.view.View;
import android.widget.AdapterView;
import android.widget.Button;
import android.widget.CheckBox;
import android.widget.EditText;
import android.widget.GridView;
import android.widget.Spinner;
import android.widget.Toast;

import java.util.ArrayList;

public class MainActivity extends AppCompatActivity {
    EditText name;
    Spinner dropDown;
    CheckBox isPro;
    Button btn;
    GridView gdList;
    ArrayList<Dish> dishOnDrop, dishOnGrid;
    DishAdapter dAdapter;
    SpinnerAdapter sAdapter;
    Dish tmp;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        dishOnDrop = new ArrayList<Dish>();
        dishOnDrop.add(new Dish("Thumbnail 1", R.drawable.first_thumbnail));
        dishOnDrop.add(new Dish("Thumbnail 2", R.drawable.second_thumbnail));
        dishOnDrop.add(new Dish("Thumbnail 3", R.drawable.third_thumbnail));
        dishOnDrop.add(new Dish("Thumbnail 4", R.drawable.fourth_thumbnail));
        dishOnDrop.add(new Dish("Thumbnail 5", R.drawable.fifth_thumbnail));

        dropDown = (Spinner) findViewById(R.id.spinner);
        sAdapter = new SpinnerAdapter(getApplicationContext(), R.layout.dropdown_list, dishOnDrop);
        dropDown.setAdapter(sAdapter);

        dropDown.setOnItemSelectedListener(new AdapterView.OnItemSelectedListener() {
            @Override
            public void onItemSelected(AdapterView<?> parent, View view, int position, long id) {
                tmp = dishOnDrop.get(position);
            }

            @Override
            public void onNothingSelected(AdapterView<?> parent) {
            }
        });
        btn = (Button) findViewById(R.id.btn);
        name = (EditText) findViewById(R.id.name_input);
        isPro = (CheckBox) findViewById(R.id.checkbox);
        gdList = (GridView) findViewById(R.id.grid);
        dishOnGrid = new ArrayList<Dish>();
        dAdapter = new DishAdapter(this, R.layout.dish_in_gridview, dishOnGrid);
        gdList.setAdapter(dAdapter);
        btn.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                Dish addNew = new Dish(name.getText().toString(), tmp.getThumb());
                if (isPro.isChecked())
                {
                    addNew.setPro(true);
                }
                else {
                    addNew.setPro(false);
                }
                dishOnGrid.add(addNew);
                name.setText("");
                dropDown.setSelection(0);
                isPro.setChecked(false);
                Toast.makeText(MainActivity.this, "Add new dish succesfully", Toast.LENGTH_SHORT).show();
                dAdapter.notifyDataSetChanged();
            }
        });
    }
}