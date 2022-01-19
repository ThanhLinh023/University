#include<iostream>
using namespace std;

int main()
{
    int **a, m, n;
    cout << "Nhap so dong : ";
    cin >> m;
    cout << "Nhap so cot : ";
    cin >> n;
    a = new int*[m];
    for (int i = 0; i < m; i++)
    {
        a[i] = new int[n];
    }
    cout << "Nhap vao mang 2 chieu : \n";
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> a[i][j];
        }
    }
    for (int i = 0; i < m; i++)
    {
        int s1(0);
        for (int j = 0; j < n; j++)
        {
            s1 += a[i][j];
        }
        cout << "Tong tren dong " << i << " la : " << s1 << endl;
    }
    for (int j = 0; j < n; j++)
    {
        int s2(0);
        for (int i = 0; i < m; i++)
        {
            s2 += a[i][j];
        }
        cout << "Tong tren cot " << j << " la : " << s2 << endl;
    }
    int s3(0);
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            s3 += a[i][j];
        }
    }
    cout << "Tong phan tu toan mang la : " << s3 << endl;
    if (m == n)
    {
        int s4(0);
        for (int i = 0; i < m; i++)
        {
            s4 += a[i][i];
        }
        cout << "Tong phan tu tren duong cheo chinh : " << s4 << endl;
        int s5(0);
        for (int i = 0; i < m; i++)
        {
            for (int j = i; j < m; j++)
            {
                s5 += a[i][j];
            }
        }
        cout << "Tong phan tu nua tren la : " << s5 << endl;
        int s6(0);
        for (int j = 0; j < m; j++)
        {
            for (int i = j; i < m; i++)
            {
                s6 += a[i][j];
            }
        }
        cout << "Tong phan tu nua duoi la : " << s6;
    }
    for (int i = 0; i < m; i++)
    {
        delete[] a[i];
    }
    delete[] a;
    return 0;
}