package com.example.lab2_3;

public class PartTimeEmployee extends Employee{
    public PartTimeEmployee(String id, String name)
    {
        super(id, name);
    }
    @Override
    public int tinhLuong() {
        return 150;
    }
    @Override
    public String toString()
    {
        return super.toString() + " --> PartTime = " + tinhLuong();
    }
}
