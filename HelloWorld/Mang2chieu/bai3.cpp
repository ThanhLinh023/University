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
int maxi(int a[][50], int m, int n)
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
int mini(int a[][50], int m, int n)
{
    int min = a[0][0];
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (a[i][j] < min)
            {
                min = a[i][j];
            }
        }
    }
    return min;
}
int main()
{
    int m, n, a[50][50];
    cout << "Nhap so dong : ";
    cin >> m;
    cout << "Nhap so cot : ";
    cin >> n;
    input(a, m, n);
    cout << "Max = " << maxi(a, m, n) << endl;
    cout << "Min = " << mini(a, m, n);
    return 0;
}