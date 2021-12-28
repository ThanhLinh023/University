#include<iostream>
#include<math.h>
using namespace std;
bool Prime(int n)
{
    int dem (0);
    if (n < 2)
    {
        return false;
    }
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
        else return false;
    }
}
void input(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
}
int main()
{
    int n, a[n];
    cin >> n;
    input(a, n);
    for (int i = 0; i < n; i++)
    {
        if (Prime(a[i]))
        {
            cout << a[i] << " ";
        }
        else
        {
            cout << "Mang khong co so nguyen to";
        }
    }
    return 0;
}