package com.example.lab3_2;

public class Contact {
    private int id;
    private String name;
    private String phoneNumber;
    Contact() {}
    Contact(int a, String b, String c)
    {
        this.id = a;
        this.name = b;
        this.phoneNumber = c;
    }
    void setId(int i) {this.id = i;}
    int getId() {return id;}
    void setName(String n) {this.name = n;}
    String getName() {return name;}
    void setPhoneNumber(String p) {this.phoneNumber = p;}
    String getPhoneNumber() {return phoneNumber;}
    public String toString() {return id + "  -  " + name + "  -  " + phoneNumber;}


}
