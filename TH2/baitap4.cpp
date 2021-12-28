#include<iostream>
using namespace std;
int main()
{
    float km;
    int tien (0);
    cout << "Nhap so kilomet : ";
    cin >> km;
    if (km > 0 && km <= 1)
    {
        tien += km * 15000;
    }
    if (km > 1 && km <= 5)
    {
        tien += (km-1) * 13500 + 15000;
    }
    if (km > 5 && km <= 120)
    {
        tien += (km-5) * 11000 + 69000;
    }
    if (km > 120)
    {
        tien += ((km-5) * 11000 + 69000) * 0.9;
    }
    cout << "Tien phai tra la : " << tien;
    return 0;
}