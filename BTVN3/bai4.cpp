#include<iostream>
#include<math.h>
using namespace std;
int main()
{
    int n, count (0);
    cout << "Nhap vao n : ";
    cin >> n;
    if (n > 0)
    {
        for (int i = 2; i <= sqrt(n); i++)
        {
            if (n % i == 0)
            {
                count++;
                break;
            }
        }
        if (count == 0)
        {
            cout << n << " la so nguyen to";
        }
        else
        {
            cout << n << " khong la so nguyen to";
        }
    }
    else
    {
        cout << "Nhap lai n";
    }
    return 0;
}