#include<iostream>
using namespace std;
int b, c, d, m;
class Dongvat
{
public:
    Dongvat() {}
    virtual void sound() {}
    virtual void display() {}
};
class Bo : public Dongvat
{
public:
    Bo() {}
    void sound()
    {
        cout << "Booo";
    }
    void display()
    {
        cout << "Bo: " << b * m * 10;
    }
};
class Cuu : public Dongvat
{
public:
    Cuu() {}
    void sound()
    {
        cout << "Beee";
    }
    void display()
    {
        cout << "Cuu: " << c * m * 5;
    }
};
class De : public Dongvat
{
public:
    De() {}
    void sound()
    {
        cout << "Eeee";
    }
    void display()
    {
        cout << "De: " << d * m * 8;
    }
};
int main()
{
    Dongvat **dv;
    dv = new Dongvat * [3];
    dv[0] = new Bo();
    dv[1] = new Cuu();
    dv[2] = new De();
    cin >> b >> c >> d;
    cin >> m;
    for (int i = 0; i < b - 1; i++)
    {   
        dv[0]->sound();
        cout << ",";
    }
    dv[0]->sound();
    cout << ",";
    for (int i = 0; i < c - 1; i++)
    {   
        dv[1]->sound();
        cout << ",";
    }
    dv[1]->sound();
    cout << ",";
    for (int i = 0; i < d - 1; i++)
    {   
        dv[2]->sound();
        cout << ",";
    }
    dv[2]->sound();
    cout << endl;
    for (int i = 0; i < 3; i++)
    {
        dv[i]->display();
        cout << endl;
    }
    for (int i = 0; i < 3; i++)
    {
        delete dv[i];
    }
    delete dv;
    return 0;
}