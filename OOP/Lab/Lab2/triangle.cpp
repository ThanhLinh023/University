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
    void display()
    {
        cout << "(" << x << "," << y << ")\n";
    }
    Point move(float degree, float d)
    {
        Point p;
        p.x = x + d * cos(degree * 3.14 / 180);
        p.y = y + d * sin(degree * 3.14 / 180);
        return p;
    }
};
int main()
{
    Point a, b, c;
    float o, d;
    a.input();
    b.input();
    c.input();
    cin >> o >> d;
    a.move(o, d).display();
    b.move(o, d).display();
    c.move(o, d).display();
    return 0;
}
