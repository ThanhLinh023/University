#include<iostream>
using namespace std;

void input(int a[], int &n)
{
    cout << "Nhap vao mang so nguyen : ";
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
}

int cauA(int a[], int n)
{   
    int sum(0);
    for (int i = 0; i < n; i++)
    {
        sum += a[i];
    }
    return sum;
}

int cauB(int a[], int n, int x)
{
    int d(0);
    for (int i = 0; i < n; i++)
    {
        if (a[i] == x)
        {
            d++;
        }
    }
    return d;
}

void cauC(int a[], int n)
{
    cout << "Cac phan tu chan nho hon 20 la : ";
    for (int i = 0; i < n; i++)
    {
        if (a[i] % 2 == 0 and a[i] < 20)
        {
            cout << a[i] << " ";
        }
    }
    cout << "\n";
}

void cauD(int a[], int n)
{
    int min = a[0];
    int k(0);
    for (int i = 0; i < n; i++)
    {
        if (a[i] < min)
        {
            min = a[i];
            k = i;
        }
    }
    cout << "Vi tri phan tu nho nhat trong mang la : " << k << endl;
}

void cauE(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            int t = a[i];
            a[i] = a[j];
            a[j] = t;
        }
    }
    cout << "Mang sau khi dao nguoc la : ";
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
}

int main()
{
    int a[100], n, x;
    do
    {
        cout << "Nhap so phan tu cua mang : ";
        cin >> n;
        if (n <= 0)
        {
            cout << "Nhap lai so phan tu cua mang : ";
            cin >> n;
        }
    } while (n <= 0);
    input(a, n);
    cout << "Tong cac phan tu trong mang la : " << cauA(a, n) << endl;
    cout << "Nhap vao x : ";
    cin >> x;
    cout << "Phan tu " << x << " xuat hien : " << cauB(a, n, x) << " lan.\n";
    cauC(a, n);
    cauD(a, n);
    cauE(a, n);
    return 0;
}