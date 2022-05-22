#include<iostream>
using namespace std;
int b, c, d, m;
class Bo
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
class Cuu
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
class De
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
    Bo bo1;
    Cuu cuu1;
    De de1;
    cin >> b >> c >> d;
    cin >> m;
    for (int i = 0; i < b - 1; i++)
    {   
        bo1.sound();
        cout << ",";
    }
    bo1.sound();
    cout << ",";
    for (int i = 0; i < c - 1; i++)
    {   
        cuu1.sound();
        cout << ",";
    }
    cuu1.sound();
    cout << ",";
    for (int i = 0; i < d - 1; i++)
    {   
        de1.sound();
        cout << ",";
    }
    de1.sound();
    cout << endl;
    bo1.display();
    cout << endl;
    cuu1.display();
    cout << endl;
    de1.display();
    return 0;
}