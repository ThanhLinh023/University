#include<iostream>
#include<stack>
#include<math.h>
using namespace std;
bool Prime(int n)
{
    if (n < 2) return false;
    else
    {
        for (int i = 2; i <= sqrt(n); i++)
        {
            if (n % i == 0) return false;
        }
        return true;
    }
}
class Cau5
{
private:
    stack<int> st;
public:
    Cau5() {}
    void pop()
    {
        st.pop();
    }
    void push(int n)
    {
        st.push(n);
    }
    bool isEmpty()
    {
        if (st.empty()) return true;
        return false;
    }
    int top()
    {
        return st.top();
    }
    int size()
    {
        return st.size();
    }
};
class Cau6
{
private:
    Cau5 a;
    int n;
public:
    Cau6() {}
    void input()
    {
        cout << "Enter number : ";
        cin >> n;
    }
    void analis()
    {
        int m = n;
        int i = 2;
        while (i <= m)
        {
            if (Prime(i))
            {
                while (m % i == 0)
                {
                    a.push(i);
                    m /= i;
                }
            }
            i++;
        }
    }
    void display()
    {
        cout << n << " = ";
        while (!a.isEmpty())
        {
            cout << a.top();
            if (a.size() > 1) cout << " * ";
            a.pop();
        }
    }
};
class Cau7
{
private:
    Cau5 b, c, d;
    int n;
public:
    Cau7 () {}
    void input()
    {
        cout << "Enter number : ";
        cin >> n;
    }
    void convertToBin()
    {
        int m = n;
        while (m > 0)
        {
            b.push(m % 2);
            m /= 2;
        }
        cout << n << " after converting to binary : ";
        while (!b.isEmpty())
        {
            cout << b.top();
            b.pop();
        }
    }
    void convertToHex()
    {
        int k = n;
        while (k > 0)
        {
            c.push(k % 16);
            k /= 16;
        }
        cout << n << " after converting to hex : ";
        while (!c.isEmpty())
        {
            switch (c.top())
            {
            case 10:
            {
                cout << "A";
                break;
            }
            case 11:
            {
                cout << "B";
                break;
            }
            case 12:
            {
                cout << "C";
                break;
            }
            case 13:
            {
                cout << "D";
                break;
            }
            case 14:
            {
                cout << "E";
                break;
            }
            case 15:
            {
                cout << "F";
                break;
            }
            default:
            {
                cout << c.top();
                break;
            }
            }
            c.pop();
        }
    }
    void convertToOct()
    {
        int p = n;
        while (p > 0)
        {
            d.push(p % 8);
            p /= 8;
        }
        cout << n << " after converting to octal : ";
        while (!d.isEmpty())
        {
            cout << d.top();
            d.pop();
        }
    }
};

int main()
{
    Cau6 k;
    cout << "6. ";
    k.input();
    k.analis();
    k.display();
    cout << endl;
    Cau7 m;
    cout << "7. ";
    m.input();
    m.convertToHex();
    cout << endl;
    m.convertToOct();
    cout << endl;
    m.convertToBin();
    return 0;
}