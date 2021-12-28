#include<iostream>
using namespace std;
void input(int a[][50], int &m, int &n, int t)
{
    cout << "Nhap vao mang 2 chieu " << t << " :" << endl;
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
    int m, n, p, q, a[50][50], b[50][50], c[50][50];
    cout << "Nhap so dong mang 2 chieu 1 : ";
    cin >> m;
    cout << "Nhap so cot mang 2 chieu 1 : ";
    cin >> n;
    input(a, m, n, 1);
    cout << "Nhap so dong mang 2 chieu 2 : ";
    cin >> p;
    cout << "Nhap so cot mang 2 chieu 2 : ";
    cin >> q;
    input(b, p, q, 2);
    if (m == p && n == q)
    {
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {   
                c[i][j] = a[i][j] + b[i][j];
            }
        }
        cout << "Mang sau khi cong la : " << endl;
        for (int i = 0; i < m; i++)
        {   
            for (int j = 0; j < n; j++)
            {
                cout << c[i][j] << " ";
            }
            cout << endl;
        }
    }
    else
    {
        cout << "Khong the cong 2 mang nay";
    }
}