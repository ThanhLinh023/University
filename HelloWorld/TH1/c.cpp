#include<iostream>
using namespace std;
int main()
{
    int sl, gia;
    int tien = 0;
    float vat = 0;
    cout << "Nhap so luong : ";
    cin >> sl;
    cout << "Nhap gia tien : ";
    cin >> gia;
    tien = sl * gia;
    vat = tien * 0.1;
    cout << "Tien phai tra la : " << tien << endl;
    cout << "Thue gia tri gia tang la : " << vat << endl;
    cout << "Tong tien thanh toan la : " << tien + vat;
    return 0; 
}