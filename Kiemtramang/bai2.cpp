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
void insert(int a[], int n, int &x)
{
    for (int i = 0; i < n; i++)
    {
        if (a[i] % 2 == 0)
        {
            a[i] = x;
        }
        cout << a[i] << " ";
    }
}
int main()
{
    int n, x, a[n];
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
    cout << "Nhap vao x : ";
    cin >> x;
    cout << "Mang sau khi chen : ";
    insert(a, n, x);
    return 0;
}