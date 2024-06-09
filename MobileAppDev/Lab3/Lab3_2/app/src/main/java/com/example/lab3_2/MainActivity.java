package com.example.lab3_2;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.util.Log;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.AdapterView;
import android.widget.ArrayAdapter;
import android.widget.ListView;
import android.widget.TextView;

import org.jetbrains.annotations.Nullable;

import java.util.ArrayList;
import java.util.List;

public class MainActivity extends AppCompatActivity {
    ListView list;

    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        DatabaseHandler db = new DatabaseHandler(this);
        db.addContact(new Contact(1, "Micheal", "03322312832"));
        db.addContact(new Contact(2, "Nguyen D", "03322312832"));
        db.addContact(new Contact(3, "Tommy Teo", "03322312832"));
        db.addContact(new Contact(4, "Karik Tom", "03322312832"));
        List<Contact> contacts = db.getAllContacts();

        list = findViewById(R.id.list);

        ArrayAdapter<Contact> adapter = new ArrayAdapter<Contact>(
                this,
                R.layout.item,
                R.id.contactDetails,
                contacts
        ) {
            public View getView(int position, @Nullable View convertView, ViewGroup parent) {
                if (convertView == null) {
                    convertView = LayoutInflater.from(getContext()).inflate(R.layout.item, parent, false);
                }
                Contact contact = getItem(position);
                TextView textViewContactDetails = convertView.findViewById(R.id.contactDetails);
                textViewContactDetails.setText(contact.getId() + "\t\t\t\t\t" + contact.getName() + "\t\t\t\t\t" + contact.getPhoneNumber());

                return convertView;
            }
        };
        list.setAdapter(adapter);
        list.setOnItemLongClickListener(new AdapterView.OnItemLongClickListener() {
            @Override
            public boolean onItemLongClick(AdapterView<?> parent, View view, int position, long id) {
                Contact cont = contacts.get(position);
                contacts.remove(position);
                db.deleteContact(cont);
                adapter.notifyDataSetChanged();
                return true;
            }
        });
    }
}