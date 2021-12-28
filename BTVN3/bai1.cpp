#include<iostream>
using namespace std;
int main()
{
    int n, sum (0);
    cout << "Nhap vao n : ";
    cin >> n;
    if (n > 0)
    {
        for (int i = 1; i <= n; i++)
        {
            sum += i;
        }
        cout << "Tong la : " << sum;
    }
    else
    {
        cout << "Nhap lai n";
    }
    return 0;
}