//STT: 25 - Họ và tên: Vương Thanh Linh - Buổi 4 - Bài 1
#include<iostream>
#include<time.h>
#include<ctime>
#include<cstdlib>
using namespace std;
int d1(0), d2(0);
void createX(int x[100], int &n)
{
    srand(time(0));
    for (int i = 0; i < n; i++)
    {
        int t = (100 + rand() % 301);
        x[i] = t;
    }
}

void createY(int y[100], int &n)
{
    srand(time(0));
    y[0] = rand() % 131;
    for (int i = 1; i < n; i++)
    {
        y[i] = y[i - 1] + 1 + rand() % 16;
    }
}

void printArr(int a[100], int &n)
{
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
}
int linearSearch(int a[100], int &n, int x)
{
    for (int i = 0; i < n ; i++)
    {
        if (a[i] == x)
        {
            return i;
            break;
        }
    }
    return -1;
}
int binarySearch(int a[100], int &n, int x)
{
    int l, m, r;
    l = 0;
    r = n - 1;
    while (l <= r)
    {
        m = (l + r) / 2;
        if (a[m] == x)
        {
            return m;
        }
        if (a[m] > x)
        {
            r = m - 1;
        }
        else
        {
            l = m + 1;
        }
    }
    return -1;
}
int interpolationSearch(int a[100], int &n, int &x)
{
    int l, m, r;
    l = 0;
    r = n - 1;
    while (l <= r)
    {
        m = l + ((r - l) * (x - a[l])) / (a[r] - a[l]);
        if (a[m] == x)
        {
            return m;
        }
        if (a[m] > x)
        {
            r = m - 1;
        }
        else
        {
            l = m + 1;
        }
    }
    return -1;
}
void bin(int a[100], int &n, int x)
{
    int l, m, r;
    l = 0;
    r = n - 1;
    while (l <= r)
    {
        m = (l + r) / 2;
        d1++;
        if (a[m] == x)
        {
            return;
        }
        if (a[m] > x)
        {
            r = m - 1;
        }
        else
        {
            l = m + 1;
        }
    }
}
void interpol(int a[100], int &n, int &x)
{
    int l, m, r;
    l = 0;
    r = n - 1;
    while (l <= r)
    {
        m = l + ((r - l) * (x - a[l])) / (a[r] - a[l]);
        d2++;
        if (a[m] == x)
        {
            return;
        }
        if (a[m] > x)
        {
            r = m - 1;
        }
        else
        {
            l = m + 1;
        }
    }
    return;
}
int main()
{
    int x[100], y[100];
    int k;
    cout << "------------------MENU----------------\n";
    cout << "1. Tao mang\n";
    cout << "\tA. Tao mang arrayX\n";
    cout << "\tB. Tao mang arrayY\n";
    cout << "2. Xuat mang\n";
    cout << "\tA. Xuat mang arrayX\n";
    cout << "\tB. Xuat mang arrayY\n";
    cout << "3. Tim kiem tuyen tinh\n";
    cout << "\tA. Ap dung mang arrayX\n";
    cout << "\tB. Ap dung mang arrayY\n";
    cout << "4. Tim kiem nhi phan, ap dung mang arrayY\n";
    cout << "5. Tim kiem noi suy, ap dung mang arrayY\n";
    cout << "6. So sanh so lan tim kiem, ap dung arrayY\n";
    cout << "------------------END----------------\n";
    while(1)
    {
        cout << "\tLua chon: ";
        cin >> k;
        switch(k)
        {
            case 1:
            {
                int n = 30 + rand() % 21;
                createX(x, n);
                createY(y, n);
                cout << "Da tao xong 2 mang tu dong";
                cout << "\n--------------------------------\n";
                break;
            }
            case 2:
            {
                int n = 30 + rand() % 21;
                cout << "Mang arrayX: ";
                printArr(x, n);
                cout << "\nMang arrayY: ";
                printArr(y, n);
                cout << "\n--------------------------------\n";
                break;
            }
            case 3:
            {
                int n = 30 + rand() % 21;
                int k = 100 + rand() % 301;
                cout << "Nhap X can tim: " << k;
                if (linearSearch(x, n, k) == -1)
                {
                    cout << endl;
                    cout << k << " khong co trong mang arrayX\n";
                }
                else
                {
                    cout << endl;
                    cout << k << " o vi tri " << linearSearch(x, n, k) << " trong mang arrayX";
                    cout << endl;
                }
                if (linearSearch(y, n, k) == -1)
                {
                    cout << endl;
                    cout << k << " khong co trong mang arrayY\n";
                }
                else
                {
                    cout << endl;
                    cout << k << " o vi tri " << linearSearch(y, n, k) << " trong mang arrayY";
                    cout << endl;
                }
                cout << "--------------------------------\n";
                break;
            }
            case 4:
            {
                int n = 30 + rand() % 21;
                int k = 100 + rand() % 301;
                cout << "Nhap X can tim: " << k;
                if (binarySearch(y, n, k) == -1)
                {
                    cout << endl;
                    cout << k << " khong co trong mang arrayY\n";
                }
                else
                {
                    cout << endl;
                    cout << k << " o vi tri " << binarySearch(y, n, k) << " trong mang arrayY";
                    cout << endl;
                }
                cout << "--------------------------------\n";
                break;
            }
            case 5:
            {
                int n = 30 + rand() % 21;
                int k = 100 + rand() % 301;
                cout << "Nhap X can tim: " << k;
                if (interpolationSearch(y, n, k) == -1)
                {
                    cout << endl;
                    cout << k << " khong co trong mang arrayY\n";
                }
                else
                {
                    cout << endl;
                    cout << k << " o vi tri " << interpolationSearch(y, n, k) << " trong mang arrayY";
                    cout << endl;
                }
                cout << "--------------------------------\n";
                break;
            }
            case 6:
            {
                int a[100];
                int n = 30 + rand() % 21;
                createY(a, n);
                int k = 100 + rand() % 301;
                cout << "Gia tri can tim: " << k;
                bin(a, n, k);
                interpol(a, n, k);
                cout << "\nSo lan tim kiem bang tim kiem nhi phan o mang arrayY: " << d1;
                cout << "\nSo lan tim kiem bang tim kiem noi suy o mang arrayY: " << d2;
                cout << "\n--------------------------------\n";
                break;
            }
        }
    }
    return 0;
}