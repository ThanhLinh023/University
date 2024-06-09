package com.example.lab2_3;

public class FullTimeEmployee extends Employee {
    public FullTimeEmployee(String id, String name)
    {
        super(id, name);
    }
    @Override
    public int tinhLuong() {
        return 500;
    }
    @Override
    public String toString()
    {
        return super.toString() + " --> FullTime = " + tinhLuong();
    }
}
