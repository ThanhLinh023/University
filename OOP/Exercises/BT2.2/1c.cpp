#include<iostream>
#include<math.h>
using namespace std;
class Fraction
{
public:
    int ts;
    int ms;
    void input()
    {
        cout << "Enter a fraction : ";
        cin >> ts >> ms;
    } 
};
int main()
{
    Fraction f1, f2;
    f1.input();
    f2.input();
    int gcd1 = abs(f1.ts) > abs(f1.ms) ? abs(f1.ts) : abs(f1.ms);
    while (gcd1 > 1)
    {
        if (f1.ts % gcd1 == 0 && f1.ms % gcd1 == 0)
        {
            f1.ts /= gcd1;
            f1.ms /= gcd1;
            break;
        }
        gcd1--;
    }
    int gcd2 = abs(f2.ts) > abs(f2.ms) ? abs(f2.ts) : abs(f2.ms);
    while (gcd2 > 1)
    {
        if (f2.ts % gcd2 == 0 && f2.ms % gcd2 == 0)
        {
            f2.ts /= gcd2;
            f2.ms /= gcd2;
            break;
        }
        gcd2--;
    }
    if (f1.ms < 0)
    {
        f1.ts *= -1;
        f1.ms *= -1;
    }
    if (f2.ms < 0)
    {
        f2.ts *= -1;
        f2.ms *= -1;
    }
    Fraction sum, diff, prod, quot;
    sum.ts = f1.ts * f2.ms + f2.ts * f1.ms;
    sum.ms = f1.ms * f2.ms;
    diff.ts = f1.ts * f2.ms - f2.ts * f1.ms;
    diff.ms = f1.ms * f2.ms;
    prod.ts = f1.ts * f2.ts;
    prod.ms = f1.ms * f2.ms;
    quot.ts = f1.ts * f2.ms;
    quot.ms = f1.ms * f2.ts;
    cout << "Sum: " << sum.ts << "/" << sum.ms << endl;
    cout << "Difference: " << diff.ts << "/" << diff.ms << endl;
    cout << "Product: " << prod.ts << "/" << prod.ms << endl;
    cout << "Quotient: " << quot.ts << "/" << quot.ms << endl;
    return 0;
}