#include<iostream>
#include<math.h>
using namespace std;

void input(int a[][50], int &m, int &n)
{
    cout << "Nhap vao mang 2 chieu : \n";
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> a[i][j];
        }
    }
}

bool Prime(int n)
{
    int dem(0);
    if (n < 2) return false;
    else
    {
        for (int  i = 2; i <= sqrt(n); i++)
        {
            if (n % i == 0) dem++;
        }
        if (dem == 0) return true;
        else return false;
    }
}

int cauA(int a[][50], int m, int n)
{
    int max = a[0][0];
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (a[i][j] > max)
            {
                max = a[i][j];
            }
        }
    }
    return max;
}

void cauB(int a[][50], int m)
{
    cout << "Cac phan tu nam nua tren duong cheo chinh la : ";
    for (int i = 0; i < m; i++)
    {
        for (int j = i; j < m; j++)
        {
            cout << a[i][j] << " ";
        }
    }
    cout << endl;
}

void cauC(int a[][50], int m, int n)
{
    for (int i = 0; i < m; i++)
    {
        int min = a[i][0];
        for (int j = 0; j < n; j++)
        {
            if (a[i][j] < min)
            {
                min = a[i][j];
            }
        }
        cout << "Gia tri nho nhat tren hang " << i << " la : " << min << endl;
    }
}

void cauD(int a[][50], int m, int n)
{
    for (int j = 0; j < n; j++)
    {
        int max = a[0][j];
        for (int i = 0; i < m; i++)
        {
            if (a[i][j] > max)
            {
                max = a[i][j];
            }
        }
        cout << "Gia tri lon nhat tren cot " << j << " la : " << max << endl;
    }
}

void cauE(int a[][50], int m, int n)
{
    cout << "Cac phan tu la so nguyen to la : ";
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (Prime(a[i][j]))
            {
                cout << a[i][j] << " ";
            }
        }
    }
}

int main()
{
    int m, n, a[50][50];
    cout << "Nhap so vao so hang cua mang : ";
    cin >> m;
    cout << "Nhap so vao so cot cua mang : ";
    cin >> n;
    input(a, m, n);
    cout << "Phan tu lon nhat cua mang la : " << cauA(a, m, n) << endl;
    if (m == n) cauB(a, m);
    cauC(a, m, n);
    cauD(a, m, n);
    cauE(a, m, n);
    return 0;
}