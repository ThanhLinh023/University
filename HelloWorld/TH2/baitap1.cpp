#include<iostream>
using namespace std;
int main()
{
    float a, b, c, tam;
    cout << "Nhap vao a b c : ";
    cin >> a >> b >> c;
    if ( a > b)
    {
        tam = a;
        a = b;
        b = tam;
    }
    if (a > c)
    {
        tam = a;
        a = c;
        c = tam;
    }
    if (b > c)
    {
        tam = b;
        b = c;
        c = tam;
    }
    cout << "Sau khi sap xep : " << a << " " << b << " " << c;
    return 0;
}