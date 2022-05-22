#include<iostream>
using namespace std;
class Boat
{
protected:
    string id;
    int number;
public:
    Boat() {}
    virtual void input()
    {
        cin >> id >> number;
    }
    virtual void display()
    {
        cout << id << " - ";
    }
};
class Ghe : public Boat
{
private:
    int haveEngine;
public:
    Ghe() {}
    void input()
    {
        Boat::input();
        cin >> haveEngine;
    }
    void display()
    {
        if (haveEngine == 1)
        {
            Boat::display();
            cout << "Ghe - " << number << " thuyen vien - Co Dong Co";
        }
        else
        {
            Boat::display();
            cout << "Ghe - " << number << " thuyen vien";
        }
    }
};
class NormalBoat : public Boat
{
private:
    string label;
public:
    NormalBoat() {}
    void input()
    {
        Boat::input();
        cin >> label;
    }
    void display()
    {
        Boat::display();
        cout << "Thuyen thuong - " << number << " thuyen vien - " << label;
    }
};
class BigBoat : public Boat
{
private:
    string label;
    int distance;
public:
    BigBoat() {}
    void input()
    {
        Boat::input();
        cin >> label >> distance;
    }
    void display()
    {
        Boat::display();
        cout << "Thuyen lon - " << number << " thuyen vien - " << label << " - " << distance << "m";
    }
};
int main()
{
    int n, k;
    Boat **a;
    cin >> n;
    a = new Boat * [n];
    for (int i = 0; i < n; i++)
    {
        cin >> k;
        if (k == 1) a[i] = new Ghe();
        if (k == 2) a[i] = new NormalBoat();
        if (k == 3) a[i] = new BigBoat();
        a[i]->input();
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