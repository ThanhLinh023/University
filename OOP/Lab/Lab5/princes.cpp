#include<iostream>
using namespace std;
class Gate
{
protected:
    int type;
public:
    Gate() {}
    virtual void input() {}
    virtual int back() = 0;
    int getType()
    {
        return type;
    }
    void setType(int n)
    {
        type = n;
    }
};
class Business : public Gate
{
protected:
    int dongia;
    int sohang;
public:
    Business() {}
    void input()
    {
        cin >> dongia >> sohang;
    }
    int back()
    {
        return dongia * sohang;
    }
};
class Academic : public Gate
{
protected:
    int iq;
public:
    Academic() {}
    void input()
    {
        cin >> iq;
    }
    int back()
    {
        return iq;
    }
};
class Power : public Gate
{
protected:
    int pow;
public:
    Power() {}
    void input()
    {
        cin >> pow;
    }
    int back()
    {
        return pow;
    }
};
int main()
{
    int n, k;
    Gate **a;
    cin >> n;
    a = new Gate * [n];
    for (int i = 0; i < n; i++)
    {
        cin >> k;
        if (k == 1)
        {
            a[i] = new Business();
            a[i]->setType(1);
        }
        if (k == 2)
        {
            a[i] = new Academic();
            a[i]->setType(2);
        }
        if (k == 3)
        {
            a[i] = new Power();
            a[i]->setType(3);
        }
        a[i]->input();
    }
    int moneyOfPrince, IQofPrince, PowerOfPrince;
    int d(0);
    cin >> moneyOfPrince >> IQofPrince >> PowerOfPrince;
    for (int i = 0; i < n; i++)
    {
        if (a[i]->getType() == 1)
        {
            moneyOfPrince -= a[i]->back();
            if (moneyOfPrince < 0) d++;
        }
        if (a[i]->getType() == 2)
        {
            if (IQofPrince < a[i]->back()) d++;
        }
        if (a[i]->getType() == 3)
        {
            PowerOfPrince -= a[i]->back();
            if (PowerOfPrince < 0) d++;
        }
    }
    if (d == 0)
    {
        cout << moneyOfPrince << " " << IQofPrince << " " <<  PowerOfPrince;
    }
    else cout << "-1";
    for (int i = 0; i < n; i++)
    {
        delete a[i];
    }
    delete a;
    return 0;
}