#include<iostream>
using namespace std;
void input(int a[][50], int &m, int &n)
{
    cout << "Nhap vao mang 2 chieu : " << endl;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> a[i][j];
        }
    }
}
int sumOfrow(int a[][50], int n, int &k)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += a[k][i];
    }
    return sum;
}
int sumOfColum(int a[][50], int m, int &k)
{
    int sum = 0;
    for (int i = 0; i < m; i++)
    {
        sum += a[i][k];
    }
    return sum;
}
int sumOfarray(int a[][50], int m, int n)
{
    int sum = 0;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            sum += a[i][j];
        }
    }
    return sum;
}
int sumMainline(int a[][50], int m)
{
    int sum = 0;
    for (int i = 0; i < m; i++)
    {
        sum += a[i][i];
    }
    return sum;
}
int sumAbove(int a[][50], int m)
{
    int sum = 0;
    for (int i = 0; i < m; i++)
    {
        for (int j = i; j < m; j++)
        {
            sum += a[i][j];
        }
    }
    return sum;
}
int sumBelow(int a[][50], int m)
{
    int sum = 0;
    for (int j = 0; j < m; j++)
    {
        for (int i = j; i < m; i++)
        {
            sum += a[i][j];
        }
    }
    return sum;
}
int main()
{
    int m, n, a[50][50];
    cout << "Nhap so dong : ";
    cin >> m;
    cout << "Nhap so cot : ";
    cin >> n;
    input(a, m, n);
    if (m == n)
    {
        cout << "Tong cac phan tu la : " << sumOfarray(a, m, n) << endl;
        cout << "Tong duong cheo chinh la : " << sumMainline(a, m) << endl;
        cout << "Tong nua tren la : " << sumAbove(a, m) << endl;
        cout << "Tong nua duoi la : " << sumBelow(a, m);
    }
}