#include<iostream>
#include<math.h>
using namespace std;
struct Point
{
    float x;
    float y;
};

void setPoint(Point &p, float a = 0, float b = 0)
{
    p.x = a;
    p.y = b;
}

int main()
{
    int n;
    Point points[100];
    cout << "Enter number of points: ";
    cin >> n;
    cout << "Enter points : \n";
    for (int i = 0; i < n; i++)
    {
        if (i % 3 == 0)
        {
            cout << "Enter x and y : ";
            cin >> points[i].x >> points[i].y;
            setPoint(points[i], points[i].x, points[i].y);
        }
        if (i % 3 == 1)
        {
            cout << "Enter x : ";
            cin >> points[i].x;
            setPoint(points[i], points[i].x);
        }
        if (i % 3 == 2)
        {
            setPoint(points[i]);
        }
    }
    cout << "Points: ";
    for (int i = 0; i < n; i++)
    {
        cout << "(" << points[i].x << "; " << points[i].y << ") ";
    }
    float max = 0;
    Point p, q;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            float distance = sqrt(pow(points[i].x - points[j].x, 2) + pow(points[i].y - points[j].y, 2));
            if (distance > max)
            {
                max = distance;
                p = points[i];
                q = points[j];
            }
        }
    }
    cout << "\n2 points have max distance: " << "(" << p.x << "; " << p.y << ") and (" << q.x << ", " << q.y << ")" << endl;
    return 0;
}