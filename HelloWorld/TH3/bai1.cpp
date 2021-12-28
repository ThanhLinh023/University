#include<iostream>
using namespace std;
int main()
{
    int n, gt (1);
    do
    {
        cout << "Insert n : ";
        cin >> n;
        if (n < 0)
        {
            cout << "Insert n again." << endl;
        }
    } while (n <= 0);
    for (int i = 1; i <= n; i++)
    {
        gt *= i;
    }
    cout << n << "! = " << gt;
    return 0;
}