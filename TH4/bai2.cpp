#include<iostream>
using namespace std;
int cauA(int n)
{
    if (n == 1) return 1;
    else return n + cauA(n - 1);
}
int cauB(int n)
{
    if (n == 1) return 1;
    else return n * n + cauB(n - 1);
}
float cauC(int n)
{
    if (n == 1) return 1;
    else return 1.0/n + cauC(n - 1);
}
int cauD(int n)
{
    int sum(0), p(1);
    for (int i = 1; i <= n; i++)
    {
        p *= i;
        sum += p;
    }
    return sum;
}
int main()
{
    int n;
    do
    {
        cout << "Nhap vao n : ";
        cin >> n;
        if (n <= 0)
        {
            cout << "Nhap lai n.\n";
        }
    } while (n <= 0);
    cout << "Cau a, S = " << cauA(n) << endl;
    cout << "Cau b, S = " << cauB(n) << endl;
    cout << "Cau c, S = " << cauC(n) << endl;
    cout << "Cau d, S = " << cauD(n);
    return 0;
}