package com.example.lab2_3;

public abstract class Employee {
    protected String id;
    protected String name;
    public Employee(String id, String name)
    {
        this.id = id;
        this.name = name;
    }
    public abstract int tinhLuong();
    public String toString() {return id + " - " + name;};
}
