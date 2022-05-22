#include<iostream>
using namespace std;
class myInt
{
private:
    int a;
public:
    myInt() {}
    myInt(int x) : a(x) {}
    myInt operator+(myInt &x)
    {
        return myInt(a - x.a);
    }
    myInt operator*(myInt &x)
    {
        return myInt(a * x.a);
    }
    friend ostream &operator<<(ostream &out, const myInt &x);
};
ostream &operator<<(ostream &out, const myInt &x)
{
    out << x.a << endl;
    return out;
}
int main()
{
    myInt a(4), b(5);
    cout << (a + b) * a;
    cout << a * b;
    system("pause");
    return 0;
}