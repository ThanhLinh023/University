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
    void display()
    {
        cout << ts << "/" << ms << endl;
    }   
};
int main()
{
    Fraction a1;
    Fraction a2;
    a1.input();
    a2.input();
    int gcd1 = abs(a1.ts) > abs(a1.ms) ? abs(a1.ts) : abs(a1.ms);
    while (gcd1 > 1)
    {
        if (a1.ts % gcd1 == 0 && a1.ms % gcd1 == 0)
        {
            a1.ts /= gcd1;
            a1.ms /= gcd1;
            break;
        }
        gcd1--;
    }
    int gcd2 = abs(a2.ts) > abs(a2.ms) ? abs(a2.ts) : abs(a2.ms);
    while (gcd2 > 1)
    {
        if (a2.ts % gcd2 == 0 && a2.ms % gcd2 == 0)
        {
            a2.ts /= gcd2;
            a2.ms /= gcd2;
            break;
        }
        gcd2--;
    }
    if (a1.ms < 0)
    {
        a1.ts *= -1;
        a1.ms *= -1;
    }
    if (a2.ms < 0)
    {
        a2.ts *= -1;
        a2.ms *= -1;
    }
    if (a1.ts * a2.ms > a2.ts * a1.ms)
    {
        a1.display();
    }
    else
    {
        a2.display();
    }
    return 0;
}