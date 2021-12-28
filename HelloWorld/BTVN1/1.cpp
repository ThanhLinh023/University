#include<iostream>
using namespace std;

int main()
{
    int m (0), n(0), p(0), q(0), tong (0), g(0), h (0), sum (0);
    int soXe;
    cout << "Nhap vao bien so : ";
    cin >> soXe;
    m = soXe / 1000;
    n = (soXe % 1000) / 100;
    p = (soXe % 100) / 10;
    q = soXe % 10;
    tong = m + n + p + q;
    g = tong / 10;
    h = tong % 10;
    sum = g + h;
    cout << "Bien so xe co " <<  sum << " nut.";
    return 0;
}