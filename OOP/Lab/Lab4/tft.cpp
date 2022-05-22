#include<iostream>
using namespace std;
static int m;
class Assassin
{
private:
    int dmg;
public:
    Assassin() {}
    virtual void input()
    {
        cin >> dmg;
    }
    int getDmg() {return dmg;}
    virtual void display()
    {
        cout << " - Sat thuong gay ra: " << totalDmg();
    }
    virtual int totalDmg() = 0;
};
class Shaco : public Assassin
{
public:
    Shaco() {}
    int totalDmg()
    {
        int t(0);
        for (int i = 1; i <= m; i++)
        {
            t += ((getDmg() + 10) * 2);
        }
        return t;
    }
    void display()
    {
        cout << "Shaco";
        Assassin::display();
    }
};
class Zed : public Assassin
{
public:
    Zed() {}
    int totalDmg()
    {
        int t(0);
        for (int i = 1; i <= m; i++)
        {
            if (i % 3 == 0)
            {
                t += (getDmg() + 10) * 3;
            }
            else
            {
                t += (getDmg() + 10);
            }
        }
        return t;
    }
    void display()
    {
        cout << "Zed";
        Assassin::display();
    }
};
int main()
{
    int n, k;
    cin >> n;
    Assassin **a;
    a = new Assassin * [n];
    for (int i = 0; i < n; i++)
    {
        cin >> k;
        if (k == 1)
        {
            a[i] = new Shaco();
            a[i]->input();
        }
        if (k == 2)
        {
            a[i] = new Zed();
            a[i]->input();
        }
    }
    cin >> m;
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