package com.example.lab2_7;

public class Employee {
    private String id, fullName;
    private boolean isMng;
    Employee() {}
    Employee(String a, String b, boolean c)
    {
        this.id = a;
        this.fullName = b;
        this.isMng = c;
    }
    String getFullName() {return fullName;}
    boolean isManager() {return isMng;}
}
