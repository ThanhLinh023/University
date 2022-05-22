#include<iostream>
#include<math.h>
using namespace std;
class Point
{
private:
    float x;
    float y;
public:
    Point() {}
    void input()
    {
        cin >> x >> y;
    }
    float getX() {return x;}
    float getY() {return y;}
};
class Polygon
{
private:
    Point *test;
    int num;
public:
    Polygon() {}
    void input()
    {
        cin >> num;
        test = new Point[num];
        for (int i = 0; i < num; i++)
        {
            test[i].input();
        }
    }
    float square()
    {
        float s1(0);
        for (int i = 0; i < num - 1; i++)
        {
            s1 += test[i].getX() * test[i + 1].getY();
        }
        s1 += test[num - 1].getX() * test[0].getY();
        float s2(0);
        for (int i = 0; i < num - 1; i++)
        {
            s2 += test[i].getY() * test[i + 1].getX();
        }
        s2 += test[num - 1].getY() * test[0].getX();
        return (s1 - s2) / 2;
    }
};
int main()
{
    Polygon a;
    a.input();
    if (a.square() < 0) cout << -a.square();
    else cout << a.square();
    return 0;
}