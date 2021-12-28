#include<iostream>
using namespace std;
int main()
{
    int a, b ,c;
    cout << "Nhap vao do dai 3 canh : ";
    cin >> a >> b >> c;
    if (a + b > c && a + c > b && b + c > a)
    {
        cout << "Day la tam giac";
        if (a == b && b == c && a == c)
        {
            cout << " deu";
        }
        if (a == b && a != c || b == c && b != a || a == c && a != b)
        {
            cout << " can";
        }
        if (a*a == b*b + c*c || b*b == a*a + c*c || c*c == a*a + b*b)
        {
            cout << " vuong";
        }
    }
    else
    {
        cout << "Khong phai tam giac";
    }
    return 0;
}