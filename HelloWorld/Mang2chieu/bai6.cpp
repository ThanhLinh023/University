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
int main()
{
    int m, n, a[50][50], dem1(0), dem2(0);
    cout << "Nhap so dong : ";
    cin >> m;
    cout << "Nhap so cot : ";
    cin >> n;
    input(a, m, n);
    if (m == n)
    {
        for (int i = 0; i < m; i++)
        {   
            for (int j = 0; j < m; j++)
            {
                if (i == j and a[j][j] != 1) dem1++;
                if (i != j and a[i][j] !=0) dem2++;
            }
        }
        if (dem1 == 0 and dem2 == 0)
        {
            cout << "Day la ma tran don vi";
        }
        else
        {
            cout << "Day khong phai ma tran don vi";
        }
    }
    else
    {
        cout << "Day khong phai ma tran don vi";
    }
}