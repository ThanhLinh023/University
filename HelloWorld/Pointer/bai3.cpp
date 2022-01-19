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
    int max = a[0][0];
    int min = a[0][0];
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (a[i][j] > max) max = a[i][j];
        }
    }
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (a[i][j] < min) min = a[i][j];
        }
    }
    cout << "Gia tri lon nhat va nho nhat trong mang la : " << max << " " << min;
    for (int i = 0; i < m; i++)
    {
        delete[] a[i];
    }
    delete[] a;
    return 0;
}