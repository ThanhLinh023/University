#include<iostream>
using namespace std;
int main()
{
    int n;
    do
    {
        cout << "Insert n : ";
        cin >> n;
        if (n < 0)
        {
            cout << "Insert n again.\n";
        }
    } while (n <= 0);
    cout << n << " after reversing is : ";
    while (n > 0)
    {
        cout << n % 10;
        n /= 10;
    }
    return 0;
}