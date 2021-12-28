#include<iostream>
using namespace std;
int pow(int x, int n)
{
    if (n == 1) return x;
    if (n == 0) return 1;
    else return x * pow(x, n - 1);
}
int main()
{
    int x, n;
    do
    {
        cout << "Nhap vao x : ";
        cin >> x;
        if (x < 0)
        {
            cout << "Nhap lai x." << endl;
        }
    } while (x <= 0);
    do
    {
        cout << "Nhap vao n : ";
        cin >> n;
        if (n < 0)
        {
            cout << "Nhap lai n." << endl;
        }
    } while (n < 0);
    cout << x << " mu " << n << " = " << pow(x, n);
    return 0;
}