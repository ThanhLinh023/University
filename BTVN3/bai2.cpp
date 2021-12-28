#include<iostream>
using namespace std;
int main()
{
    int n;
    cout << "Nhap vao n : ";
    cin >> n;
    if (n > 0)
    {
        for (int i = 1; i <= n; i++)
        {
            if (n % i == 0)
            {
                cout << "Uoc cua " << n << " la : " << i << " " << endl;
            }
        }
    }
    else
    {
        cout << "Nhap lai n";
    }
    return 0;
}