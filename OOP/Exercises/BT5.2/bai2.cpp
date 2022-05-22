#include<iostream>
#include<math.h>
using namespace std;
class Point
{
private:
    int x;
    int y;
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
    int getX() {return x;}
    int getY() {return y;}
    Point move(int dx, int dy)
    {
        Point result;
        result.x = x + dx;
        result.y = y + dy;
        return result;
    }
    Point rotate(int degree)
    {
        Point result;
        result.x = x * cos(degree) - y * sin(degree);
        result.y = x * sin(degree) + y * cos(degree);
        return result;
    }
    Point zoom(int k)
    {
        Point result;
        result.x = x * k;
        result.y = y * k;
        return result;
    }
};
class Triangle
{
private:
    Point a, b, c;
public:
    Triangle() {}
    void input()
    {
        cout << "Enter points: \n";
        a.input();
        b.input();
        c.input();
    }
    void move()
    {
        int dx, dy;
        cout << "Enter distance to move: ";
        cin >> dx >> dy;
        cout << "After moving: ";
        a.move(dx, dy).display();
        b.move(dx, dy).display();
        c.move(dx, dy).display();
    }
    void rotate()
    {
        int d;
        cout << "Enter degree: ";
        cin >> d;
        cout << "After rotating: ";
        a.rotate(d).display();
        b.rotate(d).display();
        c.rotate(d).display();
    }
    void zoom()
    {
        int p;
        cout << "Enter positive to zoom out, negative to zoom in: ";
        cin >> p;
        cout << "After zooming: ";
        a.zoom(p).display();
        b.zoom(p).display();
        c.zoom(p).display();
    }
    ~Triangle() {}
};
int main()
{
    Triangle q;
    q.input();
    q.move();
    q.rotate();
    q.zoom();
    return 0;
}