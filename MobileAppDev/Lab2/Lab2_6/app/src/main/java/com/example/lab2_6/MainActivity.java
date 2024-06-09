package com.example.lab2_6;

import androidx.appcompat.app.AppCompatActivity;
import androidx.recyclerview.widget.LinearLayoutManager;
import androidx.recyclerview.widget.RecyclerView;

import android.os.Bundle;

import java.util.ArrayList;

public class MainActivity extends AppCompatActivity {
    private ArrayList<Hero> mHeros ;
    private RecyclerView mRecyclerHero;
    private HeroAdapter mHeroAdapter ;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        mRecyclerHero = findViewById(R.id.recyclerHero);
        mHeros = new ArrayList<>();
        createHeroList();
        mHeroAdapter = new HeroAdapter(this,mHeros);
        mRecyclerHero.setAdapter(mHeroAdapter);
        mRecyclerHero.setLayoutManager(new LinearLayoutManager(this));
    }
    private void createHeroList() {
        mHeros.add(new Hero("Thor",R.drawable.image_thor));
        mHeros.add(new Hero("IronMan",R.drawable.image_ironman));
        mHeros.add(new Hero("Hulk",R.drawable.image_hulk));
        mHeros.add(new Hero("SpiderMan",R.drawable.image_spiderman));
        mHeros.add(new Hero("Thor",R.drawable.image_thor));
        mHeros.add(new Hero("IronMan",R.drawable.image_ironman));
        mHeros.add(new Hero("Hulk",R.drawable.image_hulk));
        mHeros.add(new Hero("SpiderMan",R.drawable.image_spiderman));
        mHeros.add(new Hero("Thor",R.drawable.image_thor));
        mHeros.add(new Hero("IronMan",R.drawable.image_ironman));
    }
}