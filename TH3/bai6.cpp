#include<iostream>
using namespace std;
int main()
{
    int n, ev(0), odd(0);
    do
    {
        cout << "Insert n : ";
        cin >> n;
        if (n < 0)
        {
            cout << "Insert n again.\n";
        }
    } while (n <= 0);
    while (n > 0)
    {
        if ((n % 10) % 2 == 0)
        {
            ev++;
        }
        else
        {
            odd++;
        }
        n /= 10;
    }
    cout << "Quantity of event number is : " << ev << endl;
    cout << "Quantity of odd number is : " << odd;
    return 0;
}