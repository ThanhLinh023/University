#include<iostream>
using namespace std;
void input(int a[], int &n)
{
    cout << "Nhap vao mang : ";
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
}
int main()
{
    int n, x, a[n], dem(0);
    do
    {
        cout << "Nhap so phan tu cua mang : ";
        cin >> n;
        if (n <= 0)
        {
            cout << "Nhap lai n.\n";
        }
    } while (n <= 0);
    input(a, n);
    for (int i = 0; i < n - 1; i++)
    {
        if (a[i] >= a[i+1])
        {
            dem++;
        }
    }
    if (dem == 0)
    {
        cout << "Mang tang dan";
    }
    else
    {
        cout << "Khong phai mang tang dan";
    }
    return 0;
}