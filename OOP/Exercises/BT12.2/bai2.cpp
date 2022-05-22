#include<iostream>
#include<math.h>
#include<algorithm>
using namespace std;
class Dathuc
{
private:
    int hs;
    int num[100];
public:
    Dathuc() {}
    void input()
    {
        cout << "Enter pow: ";
        cin >> hs;
        cout << "Enter number: ";
        for (int i = 0; i <= hs; i++)
        {
            cin >> num[i];
        }
    }
    void display()
    {
        cout << num[0] << "x^0";
        for (int i = 1; i <= hs; i++)
        {
            if (num[i] != 0)
            {
                if (num[i] > 0)
                {
                    cout << "+" << num[i] << "x^" << i;
                }
                if (num[i] < 0)
                {
                    cout << num[i] << "x^" << i;
                }
            }
        }
    }
    int value(int x)
    {
        int sum(0);
        for (int i = 0; i <= hs; i++)
        {
            sum += num[i] * pow(x, i);
        }
        return sum;
    }
    friend Dathuc operator+(Dathuc &a, Dathuc &b);
    friend Dathuc operator-(Dathuc &a, Dathuc &b);
};
Dathuc operator+(Dathuc &a, Dathuc &b)
{
    Dathuc t;
    t.hs = max(a.hs, b.hs);
    if (a.hs < t.hs)
    {
        for (int i = a.hs + 1; i <= t.hs; i++)
        {
            a.num[i] = 0;
        }
    }
    if (b.hs < t.hs)
    {
        for (int i = b.hs + 1; i <= t.hs; i++)
        {
            b.num[i] = 0;
        }
    }
    for (int i = 0; i <= t.hs; i++)
    {
        t.num[i] = a.num[i] + b.num[i];
    }
    return t;
}
Dathuc operator-(Dathuc &a, Dathuc &b)
{
    Dathuc t;
    t.hs = max(a.hs, b.hs);
    if (a.hs < t.hs)
    {
        for (int i = a.hs + 1; i <= t.hs; i++)
        {
            a.num[i] = 0;
        }
    }
    if (b.hs < t.hs)
    {
        for (int i = b.hs + 1; i <= t.hs; i++)
        {
            b.num[i] = 0;
        }
    }
    for (int i = 0; i <= t.hs; i++)
    {
        t.num[i] = a.num[i] - b.num[i];
    }
    return t;
}
int main()
{
    Dathuc x, y, m, n;
    int t;
    x.input();
    y.input();
    x.display();
    cout << endl;
    y.display();
    m = x + y;
    n = x - y;
    cout << "\nSum: ";
    m.display();
    cout << "\nSub: ";
    n.display();
    cout << "\nEnter x: ";
    cin >> t;
    cout << "Value of first polynomial at " << t << " is: " << x.value(t);
    cout << "\nValue of second polynomial at " << t << " is: " << y.value(t);
    return 0; 
}