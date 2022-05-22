#include<iostream>
#include<string>
using namespace std;
class Staff
{
private:
    string name;
    string dob;
    long long salary;
public:
    Staff() {}
    virtual void input()
    {
        cout << "Enter name: ";
        cin >> name;
        cout << "Enter date of birth: ";
        cin >> dob;
    }
    virtual void display()
    {
        cout << "Name: " << name;
        cout << "\nDate of birth: " << dob;
    }
    virtual long long getSalary() {}
};
class Officer : public Staff
{
private:
    int day;
public:
    Officer() {}
    void input()
    {
        Staff::input();
        cout << "Enter number of working day: ";
        cin >> day;
    }
    void display()
    {
        Staff::display();
        cout << "\nPosition: Officer";
        cout << "\nSalary: " << getSalary();
    }
    long long getSalary()
    {
        return day * 100000;
    }
};
class Manufacturer : public Staff
{
private:
    long long basicSal;
    int numOfPro;
public:
    Manufacturer() {}
    void input()
    {
        Staff::input();
        cout << "Basic salary: ";
        cin >> basicSal;
        cout << "Number of product: ";
        cin >> numOfPro;
    }
    void display()
    {
        Staff::display();
        cout << "\nPosition: Manufacturer";
        cout << "\nSalary: " << getSalary();
    }
    long long getSalary()
    {
        return (basicSal + numOfPro * 5000);
    }
};
int main()
{
    int n;
    cout << "Enter number of staff: ";
    cin >> n;
    Staff **staff;
    staff = new Staff *[n];
    for (int i = 0; i < n; i++)
    {
        cout << "Enter information of staff " << i + 1 << endl;
        string s;
        cout << "Enter position of staff: ";
        cin >> s;
        if (s == "Officer")
        {
            staff[i] = new Officer;
            staff[i]->input();
        }
        if (s == "Manufacturer")
        {
            staff[i] = new Manufacturer;
            staff[i]->input();
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << "---------------------------------\n";
        cout << "\tInformation of staff " << i + 1 << endl;
        staff[i]->display();
        cout << endl;
    }
    for (int i = 0; i < n; i++)
    {
        delete staff[i];
    }
    delete staff;
    return 0;
}