#include<iostream>
using namespace std;

int main()
{
    int sum1 = 0;
    int sum2 = 0;
    sum1 = ((999 + 3) * ((999 - 3) / 3 + 1))/2;
    sum2 = ((995 + 5) * ((999 - 5) / 5 + 1))/2;
    cout << "Tong cac boi so cua 3 va 5 nho hon 1000 la : " << sum1 + sum2;
    return 0;
}