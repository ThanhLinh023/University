#include<iostream>
using namespace std;

/*int **input(int **a, int &m, int &n)
{
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
}*/

int main()
{
    int **a, m, n, d(0);
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
    if (m == n)
    {
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (a[i][j] != a[j][i])
                {
                    d++;
                }
            }
        }
        if (d == 0)
        {
            cout << "Mang doi xung";
        }   
        else
        {
            cout << "Mang khong doi xung";
        }
    }
    else
    {
        cout << "Mang khong doi xung";
    }
    for (int i = 0; i < m; i++)
    {
        delete[] a[i];
    }
    delete[] a;
    return 0;
}