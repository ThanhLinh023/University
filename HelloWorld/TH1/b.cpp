#include<iostream>
using namespace std;
int main()
{
    int a, b;
    cout << "Nhap vao a : ";
    cin >> a;
    cout << "Nhap vao b : ";
    cin >> b;
    cout << "Tong hai so la : " << a + b << endl;
    cout << "Hieu hai so la : " << a - b << endl;
    cout << "Tich hai so la : " << a * b << endl;
    if (b != 0)
    {
        cout << "Thuong hai so la : " << (float)a / b;;
    }
    else
    {
        cout << "Thuong khong xac dinh";
    }
    return 0;
}