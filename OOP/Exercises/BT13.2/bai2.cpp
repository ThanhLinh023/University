#include<iostream>
using namespace std;
class Dathuc
{
private:
    int pow;
    int *a;
public:
    Dathuc() {}
    friend istream &operator>>(istream &is, Dathuc &a);
    friend ostream &operator<<(ostream &os, const Dathuc &a);
    //friend Dathuc operator[](Dathuc &a);
};
istream &operator>>(istream &is, Dathuc &a)
{
    cout << "\nNhap so mu: ";
    is >> a.pow;
    a.a = new int[a.pow];
    for (int i = 0; i <= a.pow; i++)
    {
        is >> a.a[i];
    }
    return is;
}
ostream &operator<<(ostream &os, const Dathuc &a)
{
    for (int i = a.pow; i > 1; i--)
    {
        if (a.a[i] != 0) os << a.a[i] << "^x" << i;
        if (a.a[i - 1] > 0) os << "+";
    }
    os << a.a[1] << "x";
    if (a.a[0] > 0) os << "+" << a.a[0];
    else os << a.a[0];
    return os;
}
int main()
{
    Dathuc a, b;
    cout << "Nhap da thuc thu nhat: ";
    cin >> a;
    cout << "Nhap da thuc thu hai: ";
    cin >> b;
    cout << "Da thuc thu nhat: " << a;
    cout << "\nDa thuc thu hai: " << b;
    return 0;
}