#include<iostream>
using namespace std;
int main()
{
    int n, a[n];
    int dem = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++)
    {
        if (a[i] != a[n-1-i])
        {
            dem++;
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
    return 0;
}