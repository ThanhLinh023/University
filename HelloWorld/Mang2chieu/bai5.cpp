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
    if (n == p)
    {
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < q; j++)
            {
                for (int t = 0; t < n; t++)
                {
                    c[i][j] += (a[i][t] * b[t][j]);
                }
            }
        }
        cout << "Mang sau khi nhan duoc la : " << endl;
        for (int i = 0; i < m; i++)
        {   
            for (int j = 0; j < q; j++)
            {
                cout << c[i][j] << " ";
            }
            cout << endl;
        }
    }
    else
    {
        cout << "Khong the nhan 2 mang";
    }
}