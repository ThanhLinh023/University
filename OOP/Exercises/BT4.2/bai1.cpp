#include<iostream>
using namespace std;
class Fraction
{
private:
    int ts;
    int ms;
public:
    Fraction() {};
    Fraction(int x, int y) : ts(x), ms(y) {};
    void input()
    {
        cin >> ts >> ms;
        while (ms == 0) cin >> ms;
    }
    void display()
    {
        if (ms < 0)
        {
            ts = -ts;
            ms = -ms;
        }
        cout << ts << "/" << ms << endl;
    }
    Fraction add(Fraction a, Fraction b)
    {
        Fraction result;
        result.ts = a.ts * b.ms + a.ms * b.ts;
        result.ms = a.ms * b.ms;
        return result;
    }
    Fraction diff(Fraction a, Fraction b)
    {
        Fraction result;
        result.ts = a.ts * b.ms - a.ms * b.ts;
        result.ms = a.ms * b.ms;
        return result;
    }
    Fraction mul(Fraction a, Fraction b)
    {
        Fraction result;
        result.ts = a.ts * b.ts;
        result.ms = a.ms * b.ms;
        return result;
    }
    Fraction divide(Fraction a, Fraction b)
    {
        Fraction result;
        result.ts = a.ts * b.ms;
        result.ms = a.ms * b.ts;
        return result;
    }
};
int main()
{
    Fraction a, b;
    a.input();
    b.input();
    a.add(a, b).display();
    a.diff(a, b).display();
    a.mul(a, b).display();
    a.divide(a, b).display();
    return 0;
}