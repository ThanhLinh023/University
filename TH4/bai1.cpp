#include<iostream>
#include<math.h>
using namespace std;
int cauA(int n)
{
    int sum(0), k;
    while (n > 0)
    {
        k = n % 10;
        sum = sum * 10 + k;
        n /= 10;
    }
    return sum;
}
bool cauB(int n)
{
    int sqr = sqrt(n);
    if (sqr * sqr == n) return true;
    return false;
}
bool cauC(int n)
{
    int dem(0);
    if (n < 2) return false;
    else
    {
        for (int i = 2; i <= sqrt(n); i++)
        {
            if (n % i == 0)
            {
                dem++;
            }
        }
        if (dem == 0) return true;
        return false;
    }
}
int cauD(int n)
{
    int sum(0);
    while (n != 0)
    {
        int odd = n % 10;
        if (odd % 2 != 0)
        {
            sum += odd;
        }
        n /= 10;
    }
    return sum;
}
int cauE(int n)
{
    int sum(0);
    for (int i = 1; i <= n; i++)
    {
        if (cauC(i))
        {
            sum += i;
        }
    }
    return sum;
}
int cauF(int n)
{
    int sum(0);
    for (int i = 1; i <= n; i++)
    {
        if (cauB(i))
        {
            sum += i;
        }
    }
    return sum;
}
int cauG(int n)
{
    int sum(0);
    for (int i = 1; i < n; i++)
    {
        if (n % i == 0)
        {
            sum += i;
        }
    }
    return sum;
}
int main()
{
    int n;
    do
    {
        cout << "Nhap vao n : ";
        cin >> n;
        if (n <= 0)
        {
            cout << "Nhap lai n.\n";
        }
    } while (n <= 0);
    cout << "So dao nguoc cua " << n << " la : " << cauA(n) << endl;
    if (cauB(n))
    {
        cout << n << " la so chinh phuong." << endl;
    }
    else
    {
        cout << n << " khong phai la so chinh phuong." << endl;
    }
    if (cauC(n))
    {
        cout << n << " la so nguyen to." << endl;
    }
    else
    {
        cout << n << " khong phai la so nguyen to." << endl;
    }
    cout << "Tong cac chu so le cua " << n << " la : " << cauD(n) << endl;
    cout << "Tong cac so nguyen to nho hon " << n << " la : " << cauE(n) << endl;
    cout << "Tong cac chinh phuong nho hon " << n << " la : " << cauF(n) << endl;
    cout << "Tong cac uoc so cua " << n << " la : " << cauG(n);
    return 0;
}