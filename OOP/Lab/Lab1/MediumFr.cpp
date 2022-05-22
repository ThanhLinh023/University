#include <iostream>
#include <math.h>
using namespace std;
int gcd(int a, int b)
{
    if (a < 0)
        a *= -1;
    if (b < 0)
        b *= -1;
    if (a == 0 || b == 0)
        return a + b;
    while (a != b)
    {
        if (a > b)
            a -= b;
        else if (b > a)
            b -= a;
    }
    return a;
}
void rutGon(int a, int b)
    {
        if (b < 0)
        {
            a = -a;
            b = -b;
        }
        else cout << a / gcd(a, b) << "/" << b / gcd(a, b) << endl;
    }
class Fraction
{
private:
    int ts;
    int ms;
public:
    void input()
    {
        cin >> ts >> ms;
        while (ms == 0)
            cin >> ms;
    }
    void display(Fraction a, Fraction b)
    {
        int c[9];
        c[1] = a.ts * b.ms + a.ms * b.ts;
        c[2] = a.ms * b.ms;
        c[3] = a.ts * b.ms - a.ms * b.ts;
        c[4] = a.ms * b.ms;
        c[5] = a.ts * b.ts;
        c[6] = a.ms * b.ms;
        c[7] = a.ts * b.ms;
        c[8] = a.ms * b.ts;
        rutGon(c[1], c[2]);
        rutGon(c[3], c[4]);
        rutGon(c[5], c[6]);
        rutGon(c[7], c[8]);
    }
};
int main()
{
    Fraction a, b;
    a.input();
    b.input();
    a.display(a, b);
    return 0;
}