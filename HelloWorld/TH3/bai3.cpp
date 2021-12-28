#include<iostream>
using namespace std;
int main()
{
    long long n, gt (1);
    do
    {
        cout << "Insert n : ";
        cin >> n;
        if (n < 0)
        {
            cout << "Insert n again.\n";
        }
    } while (n <= 0);
    if (n % 2 == 0)
    {
        for (int i = 1; i <= n; i++)
        {
            if (i % 2 == 0)
            {
                gt *= i;
            }
        }
    }
    else
    {
        for (int i = 1; i <= n; i++)
        {
            if (i % 2 != 0)
            {
                gt *= i;
            }
        }
    }
    cout << n << "! = " << gt;
    return 0;
}