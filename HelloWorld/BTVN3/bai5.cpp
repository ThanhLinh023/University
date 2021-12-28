#include<iostream>
using namespace std;
int main()
{
    for (int i = 1; i < 50; i++)
    {
        if (i % 2 == 0 || i == 3 || i == 9 || i == 31)
        {
            continue;
        }
        cout << i << " ";
    }
    return 0;
}