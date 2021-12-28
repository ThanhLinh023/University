#include<iostream>
using namespace std;
#define pi 3.14
int main()
{
    float r;
    cout << "Nhap ban kinh r : ";
    cin >> r;
    float chuvi = 0;
    float dientich = 0;
    chuvi = 2 * pi * r;
    dientich = pi * r * r;
    cout << "Chu vi la : " << chuvi << endl;
    cout << "Dien tich la : " << dientich;
    return 0;
}