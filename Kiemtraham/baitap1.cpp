#include<iostream>
using namespace std;
void sapXep(float a, float b, float c)
{
    float tam;
    if( a > b)
    {
        tam = a;
        a = b;
        b = tam;
    }
    if(a > c)
    {
        tam = a;
        a = c;
        c = tam;
    }
    if(b > c)
    {
        tam = b;
        b = c;
        c = tam;
    }
    cout << "Sau khi sap xep : " << a << " " << b << " " << c;
}
int main()
{
    float x, y, z;
    cout << "Nhap 3 so vao : ";
    cin >> x >> y >> z;
    sapXep(x, y, z);
    return 0;
}