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
    Dathuc operator+(Dathuc &x)
    {
        Dathuc result = *this;
        result.pow = max(pow, x.pow);
        if (pow < result.pow)
        {
            for (int i = pow + 1; i <= result.pow; i++)
            {
                hs[i] = 0;
            }
        }
        if (x.pow < result.pow)
        {
            for (int i = x.pow + 1; i <= result.pow; i++)
            {
                x.hs[i] = 0;
            }
        }
        for (int i = 0; i <= result.pow; i++)
        {
            result.hs[i] = hs[i] + x.hs[i];
        }
        return result;
    }
    Dathuc operator-(Dathuc &x)
    {
        Dathuc result = *this;
        result.pow = max(pow, x.pow);
        if (pow < result.pow)
        {
            for (int i = pow + 1; i <= result.pow; i++)
            {
                hs[i] = 0;
            }
        }
        if (x.pow < result.pow)
        {
            for (int i = x.pow + 1; i <= result.pow; i++)
            {
                x.hs[i] = 0;
            }
        }
        for (int i = 0; i <= result.pow; i++)
        {
            result.hs[i] = hs[i] - x.hs[i];
        }
        return result;
    }
    Dathuc operator*(Dathuc &x)
    {
        Dathuc result = *this;
        result.pow = pow + x.pow;
        for (int i = 0; i <= result.pow; i++)
        {
            result.hs[i] = 0;
        }
        for (int i = 0; i <= pow; i++)
        {
            for (int j = 0; j <= x.pow; j++)
            {
                result.hs[i + j] += hs[i] * x.hs[j];
            }
        }
        return result;
    }
};
int main()
{
    Dathuc a, b;
    char k;
    a.input();
    b.input();
    cin >> k;
    if (k == '+')
    {
        a.operator+(b).display();
    }
    else if (k == '-')
    {
        a.operator-(b).display();
    }
    else if (k == '*')
    {
        a.operator*(b).display();
    }
    return 0;
}