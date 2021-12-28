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
    cout << "Cac phan tu chan va nho hon 20 la : ";
    for (int i = 0; i < n; i++)
    {
        if (a[i] < 20 && a[i] % 2 == 0)
        {
            cout << a[i] << " ";
        }
    }
    return 0;
}