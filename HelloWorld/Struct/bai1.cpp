#include<iostream>
using namespace std;

struct dt
{
    float heSo;
    int soMu;
};

void input(dt &a, dt &b)
{
    float temp1, temp2;
    cout << "Nhap he so don thuc thu nhat : ";
    cin >> temp1;
    a.heSo = temp1;
    cout << "Nhap so mu don thuc thu nhat : ";
    cin >> a.soMu;
    cout << "Nhap he so don thuc thu hai : ";
    cin >> temp2;
    b.heSo = temp2;
    cout << "Nhap so mu don thuc thu hai : ";
    cin >> b.soMu;
}

void output(dt a, dt b)
{
    cout << "Don thuc thu nhat la : " << a.heSo << "x^" << a.soMu << endl;
    cout << "Don thuc thu hai la : " << b.heSo << "x^" << b.soMu << endl;
}

void calc(dt a, dt b)
{
    if (a.soMu == b.soMu)
    {
        cout << "Tong hai don thuc la : " << a.heSo + b.heSo << "x^" << a.soMu << endl;
        cout << "Hieu hai don thuc la : " << a.heSo - b.heSo << "x^" << a.soMu << endl;
    }
    else cout << "Khong the cong.\n";
    cout << "Tich 2 don thuc la : " << a.heSo * b.heSo << "x^" << a.soMu + b.soMu << endl;
    cout << "Thuong 2 don thuc la : " << a.heSo / b.heSo << "x^" << a.soMu - b.soMu;
}

int main()
{
    dt x, y;
    input(x, y);
    output(x, y);
    calc(x, y);
    return 0;
}