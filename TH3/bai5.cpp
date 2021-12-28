#include<iostream>
using namespace std;
void multiple(int n)
{
    cout << "Multiplication table of " << n << " :" << endl;
    for (int i = 1; i <= 10; i++)
    {
        cout << n << " * " << i << " = " << n * i << endl;
    }
}
int main()
{
    multiple(1);
    multiple(2);
    multiple(3);
    multiple(4);
    multiple(5);
    multiple(6);
    multiple(7);
    multiple(8);
    multiple(9);
    return 0;
}