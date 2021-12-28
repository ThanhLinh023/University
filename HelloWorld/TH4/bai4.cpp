#include<iostream>
using namespace std;
int giaiThua(int n)
{
    int gt(1);
    if (n % 2 == 0)
    {
        for (int i = 1; i <= n; i++)
        {
            if (i % 2 == 0)
            {
                gt *= i;
            }
        }
    }
    else
    {
        for (int i = 1; i <= n; i++)
        {
            if (i % 2 != 0)
            {
                gt *= i;
            }
        }
    }
    return gt;
}
int main()
{
    int n;
    do
    {
        cout << "Nhap vao n : ";
        cin >> n;
        if (n < 0)
        {
            cout << "Nhap lai n.\n";
        }
    } while (n <= 0);
    cout << n << "!! = " << giaiThua(n);
    return 0;
}