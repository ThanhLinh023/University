#include<iostream>
using namespace std;
int input()
{
    int n;
    do 
    {
        cout << "Nhap chieu dai canh : ";
        cin >> n;
    } while (n < 0);
    return n;
}
void check(int a, int b, int c)
{
    if (a + b > c && a + c > b && b + c > a)
    {
        cout << "Day la tam giac";
        if (a == b && b == c)
        {
            cout << " deu";
        }
        if (a == b || b == c || a == c)
        {
            cout << " can";
        }
        if (a*a == b*b + c*c || b*b == a*a + c*c || c*c == a*a + b*b)
        {
            cout << " vuong";
        }
    }
    else
    {
        cout << "Khong phai tam giac";
    }
}
int main()
{
    check(input(), input(), input());
    return 0;
}