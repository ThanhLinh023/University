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
    int n, x, a[n], sum(0);
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
    for (int i = 0; i < n; i++)
    {
        if (i % 2 == 0)
        {
            sum += a[i];
        }
    }
    cout << "Tong cac phan tu o vi tri chan la : " << sum;
    return 0;
}