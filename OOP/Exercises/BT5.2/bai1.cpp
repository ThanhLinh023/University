#include<iostream>
using namespace std;
class Point
{
private:
    int td;
    int hd;
public:
    Point() {}
    Point(int x, int y) : td(x), hd(y) {}
    void input()
    {
        cin >> td >> hd;
    }
    void display()
    {
        cout << "(" << td << "," << hd << ")\n";
    }
    void setX(int x)
    {
        td = x;
    }
    void setY(int y)
    {
        hd = y;
    }
    int getX() {return td;}
    int getY() {return hd;}
    Point move()
    {
        Point p;
        char k;
        int d;
        cout << "Distance : ";
        cin >> d;
        cout << "Move by Ox(x)";
        cout << " or move by Oy(y) : ";
        cin >> k;
        if (k == 'x')
        {
            p.td = getX() + d;
            p.hd = getY();
        }
        if (k == 'y')
        {
            p.td = getX();
            p.hd = getY() + d;
        }
        return p;
    }
};
int main()
{
    Point a;
    a.input();
    a.display();
    a.move().display();
    return 0;
}