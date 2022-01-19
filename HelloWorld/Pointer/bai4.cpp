#include<iostream>
using namespace std;

int main()
{
    int m, n, p, q;
    int **a, **b, **c;
    cout << "Nhap so dong ma tran thu nhat : ";
    cin >> m;
    cout << "Nhap so cot ma tran thu nhat : ";
    cin >> n;
    a = new int*[m];
    for (int i = 0; i < m; i++)
    {
        a[i] = new int[n];
    }
    cout << "Nhap vao ma tran thu nhat : \n";
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> a[i][j];
        }
    }
    cout << "Nhap so dong ma tran thu hai : ";
    cin >> p;
    cout << "Nhap so cot ma tran thu hai : ";
    cin >> q;
    b = new int*[p];
    for (int i = 0; i < p; i++)
    {
        b[i] = new int[q];
    }
    cout << "Nhap vao ma tran thu hai : \n";
    for (int i = 0; i < p; i++)
    {
        for (int j = 0; j < q; j++)
        {
            cin >> b[i][j];
        }
    }
    c = new int*[m];
    for (int i = 0; i < m; i++)
    {
        c[i] = new int[n];
    }
    if (m == p and n == q)
    {
        for (int i = 0; i < p; i++)
        {
            for (int j = 0; j < q; j++)
            {
                c[i][j] = a[i][j] + b[i][j];
            }
        }
        cout << "Mang sau khi cong la : \n";
        for (int i = 0; i < p; i++)
        {
            for (int j = 0; j < q; j++)
            {
                cout << c[i][j] << " ";
            }
            cout << endl;
        }
    }
    else cout << "Khong the cong 2 ma tran";
    for (int i = 0; i < m; i++)
    {
        delete[] a[i];
    }
    delete[] a;
    for (int i = 0; i < p; i++)
    {
        delete[] b[i];
    }
    delete[] b;
    for (int i = 0; i < m; i++)
    {
        delete[] c[i];
    }
    delete[] c;
    return 0;
}