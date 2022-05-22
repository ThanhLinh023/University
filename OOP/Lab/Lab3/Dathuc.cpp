#include<iostream>
#include<math.h>
using namespace std;
class Dathuc
{
private:
    int pow;
    int hs[100];
public:
    Dathuc() {}
    void input()
    {
        cin >> pow;
        for (int i = 0; i <= pow; i++)
        {
            cin >> hs[i];
        }
    }
    void display()
    {
        for (int i = 0; i < pow; i++)
        {
            if (hs[i] != 0)
            {
                cout << hs[i] << "x^" << i;
                if (hs[i + 1] < 0)
                {
                    cout << "-";
                    hs[i + 1] = -hs[i + 1];
                }
                else cout << "+";
            }
            else continue;
        }
        cout << hs[pow] << "x^" << pow;
    }
    Dathuc add(Dathuc &x, Dathuc &y)
    {
        Dathuc result;
        result.pow = max(x.pow, y.pow);
        if (x.pow < result.pow)
        {
            for (int i = x.pow + 1; i <= result.pow; i++)
            {
                x.hs[i] = 0;
            }
        }
        if (y.pow < result.pow)
        {
            for (int i = y.pow + 1; i <= result.pow; i++)
            {
                y.hs[i] = 0;
            }
        }
        for (int i = 0; i <= result.pow; i++)
        {
            result.hs[i] = x.hs[i] + y.hs[i];
        }
        return result;
    }
    Dathuc diff(Dathuc &x, Dathuc &y)
    {
        Dathuc result;
        result.pow = max(x.pow, y.pow);
        if (x.pow < result.pow)
        {
            for (int i = x.pow + 1; i <= result.pow; i++)
            {
                x.hs[i] = 0;
            }
        }
        if (y.pow < result.pow)
        {
            for (int i = y.pow + 1; i <= result.pow; i++)
            {
                y.hs[i] = 0;
            }
        }
        for (int i = 0; i <= result.pow; i++)
        {
            result.hs[i] = x.hs[i] - y.hs[i];
        }
        return result;
    }
    Dathuc mul(Dathuc &x, Dathuc &y)
    {
        Dathuc result;
        result.pow = x.pow + y.pow;
        for (int i = 0; i <= result.pow; i++)
        {
            result.hs[i] = 0;
        }
        for (int i = 0; i <= x.pow; i++)
        {
            for (int j = 0; j <= y.pow; j++)
            {
                result.hs[i + j] += x.hs[i] * y.hs[j];
            }
        }
        return result;
    }
};
int main()
{
    Dathuc a;
    Dathuc b;
    int n;
    a.input();
    b.input();
    cin >> n;
    if (n == 1)
    {
        a.add(a, b).display();
    }
    if (n == 2)
    {
        a.diff(a, b).display();
    }
    if (n == 3)
    {
        a.mul(a, b).display();
    }
    return 0;
}