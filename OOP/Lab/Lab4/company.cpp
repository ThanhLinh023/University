#include<iostream>
#include<string>
using namespace std;
static int m = 0;
static int n = 0;
class Staff
{
private:
    string name;
public:
    Staff() {}
    virtual void input()
    {
        cin >> name;
    }
    virtual void display()
    {
        cout << name;
    }
    virtual int getSalary() = 0;
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
        cin >> day;
        n += day;
    }
    void display()
    {
        Staff::display();
        cout << ": " << getSalary();
    }
    int getSalary()
    {
        return day * 100;
    }
};
class Manufacturer : public Staff
{
private:
    int basicSal;
    int numOfPro;
public:
    Manufacturer() {}
    void input()
    {
        Staff::input();
        cin >> basicSal >> numOfPro;
        m += numOfPro;
    }
    void display()
    {
        Staff::display();
        cout << ": " << getSalary();
    }
    int getSalary()
    {
        return (basicSal + numOfPro * 5);
    }
};
class Boss : public Staff
{
public:
    Boss() {}
    void input()
    {
        Staff::input();
    }
    void display()
    {
        Staff::display();
        cout << ": " << getSalary();
    }
    int getSalary()
    {
        return (100 + m * 2 + n * 40);
    }
};
int main()
{
    int n, k;
    cin >> n;
    Staff **a;
    a = new Staff * [n];
    for (int i = 0; i < n; i++)
    {
        cin >> k;
        if (k == 1)
        {
            a[i] = new Manufacturer();
            a[i]->input();
        }
        if (k == 2)
        {
            a[i] = new Officer();
            a[i]->input();
        }
        if (k == 3)
        {
            a[i] = new Boss();
            a[i]->input();
        }
    }
    for (int i = 0; i < n; i++)
    {
        a[i]->display();
        cout << endl;
    }
    for (int i = 0; i < n; i++)
    {
        delete a[i];
    }
    delete a;
    return 0;
}