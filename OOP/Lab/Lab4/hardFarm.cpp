#include<iostream>
using namespace std;
int b, c, d, t, m;
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
        int t = 0, mid = b / 2, res = b, milk = 0;
        for (int i = 1; i <= m; i++)
        {
            if (t <= 3)
            {
                res += mid;
                milk += 10 * b;
            }
            else
            {
                b += mid;
                mid = b / 2;
                milk += 10 * b;
                t = 0;
                res += mid;
            }
            t++;
        }
        cout << "Bo: " << res << "," << milk;
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
        int t = 0, mid = c / 2, res = c, milk = 0;
        for (int i = 1; i <= m; i++)
        {
            if (t <= 3)
            {
                res += mid;
                milk += 5 * c;
            }
            else
            {
                c += mid;
                mid = c / 2;
                milk += 5 * c;
                t = 0;
                res += mid;
            }
            t++;
        }
        cout << "Cuu: " << res << "," << milk;
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
        int t = 0, mid = d / 2, res = d, milk = 0;
        for (int i = 1; i <= m; i++)
        {
            if (t <= 3)
            {
                res += mid;
                milk += 8 * d;
            }
            else
            {
                d += mid;
                mid = d / 2;
                milk += 8 * d;
                t = 0;
                res += mid;
            }
            t++;
        }
        cout << "De: " << res << "," << milk;
    }
};
class Tho
{
public:
    Tho() {}
    void display()
    {
        int t1 = 0, mid = t / 2, res = m + mid;
        for (int i = 1; i <= m; i++)
        {
            if (t1 <= 1)
            {
                res += mid;
            }
            else
            {
                t += mid;
                mid = t / 2;
                t1 = 0;
                res += mid;
            }
            t1++;
        }
        cout << "Tho: " << res << ",0";
    }
};
int main()
{
    Bo bo1;
    Cuu cuu1;
    De de1;
    Tho tho1;
    cin >> b >> c >> d >> t;
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
    cout << ",,,,,";
    cout << endl;
    bo1.display();
    cout << endl;
    cuu1.display();
    cout << endl;
    de1.display();
    cout << endl;
    tho1.display();
    return 0;
}