#include<iostream>
using namespace std;
class Point
{
private:
    float hd;
    float td;
public:
    Point() {}
    void input()
    {
        cin >> hd >> td;
    }
    void display()
    {
        cout << "(" << hd << "," << td << ")" << endl;
    }
    void doublePoint()
    {
        hd *= 2;
        td *= 2;
    }
    void root()
    {
        hd = 0;
        td = 0;
    }
    void move(int o, int d)
    {
        if (o == 0)
        {
            hd += d;
        }
        else
        {
            td += d;
        }
    }
};
int main()
{
    Point c;
    c.input();
    int n, x;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        if (x == 1)
        {
            c.doublePoint();
        }
        if (x == 2)
        {
            c.root();
        }
        if (x == 3)
        {
            int o, d;
            cin >> o >> d;
            c.move(o, d);
        }
    }
    c.display();
    return 0;
}