#include<iostream>
#include<string>
using namespace std;
class Person
{
private:
    string name;
    string dob;
    string address;
public:
    Person() {}
    virtual void input()
    {
        cin.ignore();
        cout << "Enter name: ";
        getline(cin, name);
        cout << "Enter date of birth: ";
        cin >> dob;
        cin.ignore();
        cout << "Enter address: ";
        getline(cin, address);
    }
    virtual void display()
    {
        cout << "Name: " << name;
        cout << "\nDate of birth: " << dob;
        cout << "\nAddress: " << address;
    }
};
class Student : public Person
{
private:
    string id;
    float gpa;
public:
    Student() {}
    void input()
    {
        Person::input();
        cout << "Enter student's ID: ";
        cin >> id;
        cout << "Enter GPA: ";
        cin >> gpa;
    }
    void display()
    {
        Person::display();
        cout << "\nWork place: School";
        cout << "\nStudent's ID: " << id;
        cout << "\nGPA: " << gpa;
    }
};
class Engineer : public Person
{
private:
    long long basicSal;
    int dayOff;
    int yearOfEx;
public:
    Engineer() {}
    void input()
    {
        Person::input();
        cout << "Enter basic salary: ";
        cin >> basicSal;
        cout << "Enter number of dayoff: ";
        cin >> dayOff;
        cout << "Year of experience: ";
        cin >> yearOfEx;
    }
    void display()
    {
        Person::display();
        cout << "\nWork place: Factory";
        cout << "\nBasic salary: " << basicSal;
        cout << "\nNumber of dayoff: " << dayOff;
        cout << "\nYear of experience: " << yearOfEx;
    }
};
class Singer : public Person
{
private:
    string typeMusic;
    int numOfShow;
    int numOfAlbum;
public:
    Singer() {}
    void input()
    {
        Person::input();
        cout << "Enter type of music: ";
        cin >> typeMusic;
        cout << "Enter number of show: ";
        cin >> numOfShow;
        cout << "Enter number of album: ";
        cin >> numOfAlbum;
    }
    void display()
    {
        Person::display();
        cout << "\nWork place: Theater";
        cout << "\nType of music: " << typeMusic;
        cout << "\nNumber of show: " << numOfShow;
        cout << "\nNumber of album: " << numOfAlbum;
    }
};
class Doctor : public Person
{
private:
    string depart;
    int workYear;
public:
    Doctor() {}
    void input()
    {
        Person::input();
        cout << "Enter main department: ";
        cin >> depart;
        cout << "Enter number of working year: ";
        cin >> workYear;
    }
    void display()
    {
        Person::display();
        cout << "\nWork place: Hospital";
        cout << "\nMain department: " << depart;
        cout << "\nNumber of working year: " << workYear;
    }
};
int main()
{
    int n;
    cout << "Number of person: ";
    cin >> n;
    Person **a;
    a = new Person *[n];
    for (int i = 0; i < n; i++)
    {
        string s;
        cout << "Enter information of person " << i + 1 << endl;
        cout << "Enter job: ";
        cin >> s;
        if (s == "Student")
        {
            a[i] = new Student;
            a[i]->input();
        }
        if (s == "Engineer")
        {
            a[i] = new Engineer;
            a[i]->input();
        }
        if (s == "Singer")
        {
            a[i] = new Singer;
            a[i]->input();
        }
        if (s == "Doctor")
        {
            a[i] = new Doctor;
            a[i]->input();
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << "---------------------------------\n";
        cout << "\tInformation of person " << i + 1 << endl;
        a[i]->display();
        cout << endl;
    }
    cout << "-------------------------------------\n";
    for (int i = 0; i < n; i++)
    {
        delete a[i];
    }
    delete[] a;
    return 0;
}