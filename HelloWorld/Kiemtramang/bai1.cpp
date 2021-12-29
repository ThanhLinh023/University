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
void dele(int a[], int &n, int &x)
{
    for (int i = 0; i < n; i++)
    {
        if (a[i] < x)
        {
            for (int j = i; j < n; j++)
            {
                a[j] = a[j+1];
            }
            n--;
            i--;
        }
    }
}
int main()
{
    int n, x, a[50];
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
    cout << "Nhap vao so x : ";
    cin >> x;
    dele(a, n, x);
    cout << "Mang sau khi xoa : ";
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    return 0;
}