#include<iostream>
using namespace std;
class Quaternion
{
private:
    int a, b, c, d;
public:
    Quaternion() {}
    Quaternion(int x, int y, int z, int t) : a(x), b(y), c(z), d(t) {}
    friend istream &operator>>(istream &in, Quaternion &x);
    friend ostream &operator<<(ostream &out, const Quaternion &x);
    Quaternion operator+(Quaternion &x)
    {
        Quaternion t;
        t.a = a + x.a;
        t.b = b + x.b;
        t.c = c + x.c;
        t.d = d + x.d;
        return t;
    }
    Quaternion operator-(Quaternion &x)
    {
        Quaternion t;
        t.a = a - x.a;
        t.b = b - x.b;
        t.c = c - x.c;
        t.d = d - x.d;
        return t;
    }
};
istream &operator>>(istream &in, Quaternion &x)
{
    in >> x.a >> x.b >> x.c >> x.d;
    return in;
}
ostream &operator<<(ostream &out, const Quaternion &x)
{
    out << "(" << x.a << "," << x.b << "," << x.c << "," << x.d << ")";
    return out;
}
int main() 
{
    Quaternion a, b;
    cin >> a >> b;
    cout << a + b;
    cout << endl;
    cout << a - b;
    system("pause");
    return 0;
}