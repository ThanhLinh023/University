#include<iostream>
#include<math.h>
using namespace std;
int main()
{
    float a, b, c, del, x1, x2;
    cout << "Nhap vao a b c : ";
    cin >> a >> b >> c;
    if (a == 0)
    {
        if (b == 0)
        {
            if (c == 0)
            {
                cout << "Phuong trinh co vo so nghiem";
            }
            else
            {
                cout << "Phuong trinh vo nghiem";
            }
        }
        else
        {
            cout << "Phuong trinh co nghiem x la : " << - c / b;
        }
    }
    else
    {
        del = b * b - 4 * a * c;
        if (del < 0)
        {
            cout << "Phuong trinh vo nghiem";
        }
        else if (del == 0)
        {
            cout << "Phuong trinh co nghiem kep x la : " << - b / (2 * a);
        }
        else
        {
            x1 = (-b + sqrt(del)) / (2 * a);
            x2 = (-b - sqrt(del)) / (2 * a);
            cout << "Phuong trinh co nghiem x1 la : " << x1 << endl;
            cout << "Phuong trinh co nghiem x2 la : " << x2;
        }
    }
    return 0;
}