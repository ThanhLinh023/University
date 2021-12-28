#include<iostream>
using namespace std;
int mu(int x, int n)
{
    if (n == 1) return x;
    if (n == 0) return 1;
    else return x * mu(x, n - 1);
}
int convertBin(int n)
{
    int sum(0), i(0);
    while (n)
    {
        int k = n % 10;
        n /= 10;
        sum += k * mu(2, i);
        i++;
    }
    return sum;
}
int main()
{
    int n;
    cout << "Nhap vao so n : ";
    cin >> n;
    cout << "So " << n << " sau khi chuyen qua thap phan la : " << convertBin(n);
    return 0;
}