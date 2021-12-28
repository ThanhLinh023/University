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
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (a[i] < a[j])
            {
                int temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
    cout << "Mang sau khi sap xep la : ";
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    return 0;
}