#include<iostream>
using namespace std;
int main()
{
    int x, n, pow(1);
    do
    {
        cout << "Insert x : ";
        cin >> x;
    } while (x == 0);
    do
    {
        cout << "Insert n : ";
        cin >> n;
        if (n < 0)
        {
            cout << "Insert n again." << endl;
        }
    } while (n < 0);
    for (int i = 1; i <= n; i++)
    {
        pow *= x;
    }
    cout << "Value of " << x << " power " << n << " = " << pow;
    return 0;
}