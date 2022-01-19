#include<iostream>
using namespace std;

int **input(int **&a, int &m, int &n)
{
    a = new int*[m];
    for (int i = 0; i < m; i++)
    {
        a[i] = new int[n];
    }
    cout << "Nhap vao ma tran : \n";
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> a[i][j];
        }
    }
    return a;
}

bool check(int **&a, int &m)
{
    int d1(0), d2(0);
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (i == j and a[i][i] != 1) d1++;
            if (i != j and a[i][j] != 0) d2++;
        }
    }
    if (d1 == 0 and d2 == 0) return true;
    return false;
}

int main()
{
    int **a, m, n;
    cout << "Nhap vao so dong : ";
    cin >> m;
    cout << "Nhap vao so cot : ";
    cin >> n;
    input(a, m, n);
    if (m == n)
    {
        if (check(a, m)) 
        {
            cout << "Day la ma tran don vi.";
        }
        else
        {
            cout << "Khong phai ma tran don vi.";
        }
    }
    else cout << "Khong phai ma tran don vi.";
    return 0;
}