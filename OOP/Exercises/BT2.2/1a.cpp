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
    Fraction a;
    a.input();
    int gcd = abs(a.ts) > abs(a.ms) ? abs(a.ts) : abs(a.ms);
    while (gcd > 1)
    {
        if (a.ts % gcd == 0 && a.ms % gcd == 0)
        {
            a.ts /= gcd;
            a.ms /= gcd;
            break;
        }
        gcd--;
    }
    if (a.ms < 0)
    {
        a.ts *= -1;
        a.ms *= -1;
    }
    a.display();
}