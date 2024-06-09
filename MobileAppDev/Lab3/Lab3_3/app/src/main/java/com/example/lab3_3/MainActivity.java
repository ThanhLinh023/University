package com.example.lab3_3;

import android.annotation.SuppressLint;
import android.content.ContentValues;
import android.content.DialogInterface;
import android.content.Intent;
import android.database.Cursor;
import android.database.SQLException;
import android.database.sqlite.SQLiteDatabase;
import android.os.Bundle;
import android.view.View;
import android.widget.AdapterView;
import android.widget.ArrayAdapter;
import android.widget.Button;
import android.widget.EditText;
import android.widget.ListView;
import android.widget.TextView;
import android.widget.Toast;

import androidx.appcompat.app.AlertDialog;
import androidx.appcompat.app.AppCompatActivity;

import java.io.File;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.util.ArrayList;
import com.example.lab3_3.StudentInfoActivity;


import java.util.ArrayList;

public class MainActivity extends AppCompatActivity {
    String DB_PATH_SUFFIX = "/databases/";
    SQLiteDatabase database=null;
    String DATABASE_NAME="qlsv.db";
    //Khai báo ListView
    ListView lv;
    ArrayList<String> mylist;
    ArrayAdapter<String> myadapter;
    private Button btnInsert;
    private Button btnDelete;
    private Button btnUpdate;
    private Button btnQuery;
    private EditText txtMSSV;
    private EditText txtLop;
    private EditText txtName;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        processCopy();
        database = openOrCreateDatabase("qlsv.db",MODE_PRIVATE, null);
        lv = findViewById(R.id.listView);
        updateListView();

        btnInsert = findViewById(R.id.btnInsert);
        btnDelete = findViewById(R.id.btnDelete);
        btnUpdate = findViewById(R.id.btnUpdate);
        btnQuery = findViewById(R.id.btnQuery);
        btnInsert.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                insertStudent();
            }
        });
        btnDelete.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                deleteStudent();
            }
        });
        btnUpdate.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                updateStudent();
            }
        });
        btnQuery.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                queryStudent();
            }
        });

        lv.setOnItemClickListener(new AdapterView.OnItemClickListener() {
            @Override
            public void onItemClick(AdapterView<?> parent, View view, int position, long id) {
                String clickedItem = (String) parent.getItemAtPosition(position);

                String[] temp = clickedItem.split("-");
                String[] stringArray = {"MSSV: "+temp[0], "Lop: "+temp[1], "Ten: "+temp[2]};
                Toast.makeText(MainActivity.this, "MSSV: " +temp[0] +  " Class: "+temp[1] + " Name: " + temp[2], Toast.LENGTH_SHORT).show();
            }
        });


    }
    private void insertStudent() {
        try {
            txtName = findViewById(R.id.txtName);
            txtLop = findViewById((R.id.txtLop));
            txtMSSV = findViewById((R.id.txtMSSV));
            String name = txtName.getText().toString(); // Example name
            String mssv = (txtMSSV.getText().toString());
            String lop = txtLop.getText().toString();
            if (name.isEmpty() || mssv.isEmpty() || lop.isEmpty()){
                Toast.makeText(MainActivity.this, "Input fields cannot be empty", Toast.LENGTH_SHORT).show();
                return;
            }

            ContentValues values = new ContentValues();
            values.put("MSSV", mssv);
            values.put("Lop", lop);
            values.put("Hoten", name);

            long newRowId = database.insert("qlsv", null, values);

            if (newRowId != -1) {
                Toast.makeText(MainActivity.this, "Inserted successfully!", Toast.LENGTH_SHORT).show();
                updateListView();
            } else {
                Toast.makeText(MainActivity.this, "Failed to insert student!", Toast.LENGTH_SHORT).show();
            }
        } catch (SQLException e) {
            Toast.makeText(getApplicationContext(), "Message to display", Toast.LENGTH_SHORT).show();
        }
    }

    private void deleteStudent(){
        txtMSSV = findViewById((R.id.txtMSSV));
        String mssv = (txtMSSV.getText().toString());
        if (mssv.isEmpty()){
            Toast.makeText(MainActivity.this, "MSSV cannot be empty", Toast.LENGTH_SHORT).show();
            return;
        }
        int rowsAffected = database.delete("qlsv", "mssv = ?", new String[]{mssv});

        if (rowsAffected > 0) {
            Toast.makeText(MainActivity.this, "Deleted successfully", Toast.LENGTH_SHORT).show();
            txtName.setText("");
            txtLop.setText("");
            txtMSSV.setText("");
        } else {
            Toast.makeText(MainActivity.this, "No record found with the given student ID (MSSV)", Toast.LENGTH_SHORT).show();
        }
        updateListView();
    }

    private void updateStudent(){
        txtName = findViewById(R.id.txtName);
        txtLop = findViewById((R.id.txtLop));
        txtMSSV = findViewById((R.id.txtMSSV));
        String name = txtName.getText().toString(); // Example name
        String mssv = (txtMSSV.getText().toString());
        String lop = txtLop.getText().toString();
        if (mssv.isEmpty() || ( name.isEmpty() && lop.isEmpty())){
            Toast.makeText(MainActivity.this, "Input fields cannot be empty", Toast.LENGTH_SHORT).show();
            return;
        }
        ContentValues values = new ContentValues();
        if (!lop.isEmpty()) values.put("Lop", lop);
        if (!name.isEmpty()) values.put("Hoten", name);

        int rowsAffected = database.update("qlsv", values, "mssv = ?", new String[]{mssv});

        if (rowsAffected > 0) {
            Toast.makeText(MainActivity.this, "Record updated successfully", Toast.LENGTH_SHORT).show();
        } else {
            Toast.makeText(MainActivity.this, "No record found with the given student ID (MSSV)", Toast.LENGTH_SHORT).show();
        }
        updateListView();
    }
    private void queryStudent(){
        txtMSSV = findViewById((R.id.txtMSSV));
        String mssv = (txtMSSV.getText().toString());

        mylist = new ArrayList<>();
        myadapter = new ArrayAdapter<>(MainActivity.this,
                android.R.layout.simple_list_item_1, mylist);
        lv.setAdapter(myadapter);

        Cursor c;
        if (mssv.isEmpty()){
            c = database.query("qlsv",null,null,null,null,null,null);
        }else{
            c = database.query("qlsv", null, "mssv = ?", new String[]{mssv}, null, null, null);
        }

        c.moveToFirst();
        String data = "";
        while (c.isAfterLast() == false)
        {
            data = c.getString(0)+"-"+c.getString(1)+"- "+c.getString(2);
            mylist.add(data);
            c.moveToNext();
        }
        c.close();
        myadapter.notifyDataSetChanged();

    }
    private void updateListView(){
        mylist = new ArrayList<>();
        myadapter = new ArrayAdapter<>(MainActivity.this,
                android.R.layout.simple_list_item_1, mylist);
        lv.setAdapter(myadapter);
        Cursor c = database.query("qlsv",null,null,null,null,null,null);
        c.moveToFirst();
        String data = "";
        while (c.isAfterLast() == false)
        {
            data = c.getString(0)+"-"+c.getString(1)+"- "+c.getString(2);
            mylist.add(data);
            c.moveToNext();
        }
        c.close();
        myadapter.notifyDataSetChanged();
    }
    private void processCopy() {
        //private app
        File dbFile = getDatabasePath(DATABASE_NAME);
        if (!dbFile.exists())
        {
            try {
                CopyDataBaseFromAsset();
                Toast.makeText(this, "Copying sucess from Assets folder",
                        Toast.LENGTH_LONG).show();
            }
            catch (Exception e){
                Toast.makeText(this, e.toString(),
                        Toast.LENGTH_LONG).show();
            }
        }
    }
    private String getDatabasePath() {
        return getApplicationInfo().dataDir + DB_PATH_SUFFIX+
                DATABASE_NAME;
    }
    public void CopyDataBaseFromAsset() {
        try {
            InputStream myInput;
            myInput = getAssets().open(DATABASE_NAME);
            String outFileName = getDatabasePath();
            File f = new File(getApplicationInfo().dataDir +
                    DB_PATH_SUFFIX);
            if (!f.exists()) f.mkdir();
            OutputStream myOutput = new FileOutputStream(outFileName);
            int size = myInput.available();

            byte[] buffer = new byte[size];
            myInput.read(buffer);
            myOutput.write(buffer);
            myOutput.flush();
            myOutput.close();
            myInput.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}