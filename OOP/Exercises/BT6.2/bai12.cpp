#include<iostream>
#include<math.h>
using namespace std;
class Point
{
private:
    float hd;
    float td;
public:
    Point()
    {
        hd = td = 0;
    }
    Point(float x, float y) : hd(x), td(y) {}
    void input()
    {  
        cin >> hd >> td;
    }
    void display()
    {
        cout << "(" << hd << "," << td << ")\n";
    }
    Point move(Point x)
    {
        Point a;
        a.hd = hd + x.hd;
        a.td = td + x.td;
        return a;
    }
    float distance(Point x)
    {
        return sqrt(pow((hd - x.hd), 2) + pow((td - x.td), 2));
    }
};
class Triangle
{
private:
    Point a, b, c;
public:
    Triangle() {}
    Triangle(Point a, Point b, Point c) : a(a), b(b) , c(c) {}
    void input()
    {
        a.input();
        b.input();
        c.input();
    }
    void display()
    {
        a.display();
        b.display();
        c.display();
    }
    void move(Point v)
    {
        a.move(v).display();
        b.move(v).display();
        c.move(v).display();
    }
    float perimeter()
    {
       return (a.distance(b) + a.distance(c) + b.distance(c)) / 2;
    }
    float square()
    {
        float p = perimeter();
        return sqrt(p * (p - a.distance(b)) * (p - a.distance(c)) * (p - b.distance(c)));
    }
};
int main()
{
    int num;
    cout << "\tBai 1\n";
    cout << "- Number of points: ";
    cin >> num;
    Point *a, v;
    a = new Point[num];
    for (int i = 0; i < num; i++)
    {
        a[i].input();
    }
    cout << "- Points: \n";
    for (int i = 0; i < num; i++)
    {
        a[i].display();
    }
    float max(0), min(1e10);
    for (int i = 0; i < num; i++)
    {
        for (int j = i + 1; j < num; j++)
        {
            float dis1 = a[i].distance(a[j]);
            if (dis1 > max) 
            {
                max = dis1;
            }
        }
    }
    for (int i = 0; i < num; i++)
    {
        for (int j = i + 1; j < num; j++)
        {
            float dis2 = a[i].distance(a[j]);
            if (dis2 < min)
            {
                min = dis2;
            }
        }
    }
    cout << "- Maximum distance: " << max;
    cout << "\n- Minimum distance: " << min;
    cout << "\n- Enter vector v: ";
    v.input();
    cout << "- Points after moving by v: \n";
    for (int i = 0; i < num; i++)
    {
        a[i].move(v).display();
    }
    cout << "\tBai 2\n";
    Triangle *b;
    int n;
    cout << "- Number of triangles: ";
    cin >> n;
    b = new Triangle[n];
    for (int i = 0; i < n; i++)
    {
        cout << "- Enter triangle " << i + 1 << endl;
        b[i].input();
    }
    for (int i = 0; i < n; i++)
    {
        cout << "- Triangle " << i + 1 << endl;
        b[i].display();
    }
    float max1(0), max2(0);
    for (int i = 0; i < n; i++)
    {
        float k = b[i].perimeter();
        float j = b[i].square();
        if (k > max1)
        {
            max1 = k;
        }
        if (j > max2) max2 = j;
    }
    cout << "- Triangle has biggest perimeter: " << max1;
    cout << "\n- Triangle has biggest square: " << max2;
    Point m;
    cout << "\n- Enter v: ";
    m.input();
    for (int i = 0; i < n; i++)
    {
        cout << "- Triangle " << i + 1 << " after moving by v: \n";
        b[i].move(m);
    }
    return 0;
}