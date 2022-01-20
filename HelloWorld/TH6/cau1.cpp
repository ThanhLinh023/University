#include<iostream>
using namespace std;

int *input(int *&a, int &n)
{
    a = new int[n];
    cout << "Nhap vao mang : ";
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    return a;
}

void output(int *a, int n)
{
    cout << "Mang vua nhap : ";
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
}

int sum(int *a, int n)
{
    int s(0);
    for (int i = 0; i < n; i++)
    {
        s += a[i];
    }
    return s;
}

void sort(int *a, int n)
{
    int *b = new int[n];
    for (int i = 0; i < n; i++)
    {
        b[i] = a[i];
    }
    cout << "\nCau c, mang sap xep giam dan : ";
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (b[i] < b[j])
            {
                int t = b[i];
                b[i] = b[j];
                b[j] = t;
            }    
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << b[i] << " ";
    }
}

int xuat(int *a, int n, int x)
{
    int d(0);
    for (int i = 0; i < n; i++)
    {
        if (a[i] == x) d++;
    }
    return d;
}

void input2(int *a, int n)
{
    cout << "\nCau e, cac phan tu chan nho hon 20 : ";
    for (int i = 0; i < n; i++)
    {
        if (a[i] % 2 == 0 and a[i] < 20)
        {
            cout << a[i] << " ";
        }
    }
}

int tim(int *a, int n)
{
    int min = a[0], k(0);
    for (int i = 0; i < n; i++)
    {
        if (a[i] < min)
        {
            min = a[i];
            k = i;
        }
    }
    return k;
}

void dao(int *a, int n)
{
    cout << "\nCau g, day sau khi dao nguoc : ";
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            int t = a[i];
            a[i] = a[j];
            a[j] = t;
        }    
    }
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
}

int main()
{
    int *a, n, x;
    cout << "Nhap so phan tu : ";
    cin >> n;
    input(a, n);
    output(a, n);
    cout << "\nCau b, tong cac phan tu : " << sum(a, n);
    sort(a, n);
    cout << "\nNhap vao 1 so x : ";
    cin >> x;
    cout << "Cau d, so lan xuat hien cua " << x << " trong mang la : " << xuat(a, n, x);
    input2(a, n);
    cout << "\nCau f, vi tri phan tu nho nhat la vi tri : " << tim(a, n);
    dao(a, n);
    return 0;
}