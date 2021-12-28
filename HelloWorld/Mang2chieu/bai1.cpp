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
/*void output(int a[][50], int m, int n)
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}*/
int main()
{
    int m, n, a[50][50], dem(0);
    cout << "Nhap so dong : ";
    cin >> m;
    cout << "Nhap so cot : ";
    cin >> n;
    input(a, m, n);
    if (m == n)
    {
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (a[i][j] != a[j][i])
                {
                    dem++;
                }
            }
        }
        if (dem == 0)
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
    return 0;
}