package com.example.lab2_5;

public class Dish {
    private String name;
    private int thumb;
    private boolean isPro;
    Dish () {}
    Dish(String a, int b)
    {
        this.name = a;
        this.thumb = b;
    }
    public String getName() {return name;}
    public int getThumb() {return thumb;}
    public void setPro(boolean a) {this.isPro = a;}
    public boolean isPro() {return isPro;}
}
