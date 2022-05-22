#include<iostream>
#include<math.h>
using namespace std;
struct Point
{
    float x;
    float y;
};
int main()
{
    int n;
    Point diem[100];
    cout << "Enter number of points: ";
    cin >> n;
    cout << "Enter points: ";
    for (int i = 0; i < n; i++)
    {
        cin >> diem[i].x >> diem[i].y;
    }
    float max = 0;
    Point h, k;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            float distance = sqrt(pow(diem[i].x - diem[j].x, 2) + pow(diem[i].y - diem[j].y, 2));
            if (distance > max)
            {
                max = distance;
                h = diem[i];
                k = diem[j];
            }
        }
    }
    cout << "2 points have max distance: " << "(" << h.x << "; " << h.y << ") and (" << k.x << ", " << k.y << ")" << endl;
    return 0;
}