#include<iostream>
using namespace std;
class Bottle
{
public:
    Bottle() {}
    virtual void input() {}
    virtual float square() = 0;
    virtual float v() = 0;
};
class Cylinder : public Bottle
{
private:
    int h, r;
public:
    Cylinder() {}
    void input()
    {
        cin >> h >> r;
    }
    float square()
    {
        return (2 * 3.14 * r * h);
    }
    float v()
    {
        return (3.14 * r * r * h);
    }
};
class Rectangular : public Bottle
{
private:
    int h, l, w;
public:
    Rectangular() {}
    void input()
    {
        cin >> h >> l >> w;
    }
    float square()
    {
        return 2 * h * (l + w) + 2 * l * w;
    }
    float v()
    {
        return h * l * w;
    }
};
class Cube : public Bottle
{
private:
    int length;
public:
    Cube() {}
    void input()
    {
        cin >> length;
    }
    float square()
    {
        return (6 * length * length);
    }
    float v()
    {
        return (length * length * length);
    }
};
int main()
{
    int n, k;
    Bottle **a;
    cin >> n;
    a = new Bottle * [n];
    for (int i = 0; i < n; i++)
    {
        cin >> k;
        if (k == 1) a[i] = new Cylinder();
        if (k == 2) a[i] = new Rectangular();
        if (k == 3) a[i] = new Cube();
        a[i]->input();
    }
    float dt(0), thetich(0);
    for (int i = 0; i < n; i++)
    {
        dt += a[i]->square();
        thetich += a[i]->v();
    }
    cout << "Dien tich chai vo: " << dt;
    cout << "\nLuong nuoc tren mat dat: " << thetich * 0.1;
    for (int i = 0; i < n; i++)
    {
       delete a[i];
    }
    delete a;
    return 0;
}