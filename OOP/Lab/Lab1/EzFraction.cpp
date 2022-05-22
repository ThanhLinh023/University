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
        cin >> ts >> ms;
        while (ms == 0) cin >> ms;
    }
    void display()
    {
        cout << ts << "/" << ms << endl;
    }
    void rutGon()
    {
        int ucln = gcd(ts, ms);
        ts /= ucln;
        ms /= ucln;
    }
    int gcd(int a, int b)
    {
        if (b == 0) return abs(a);
        return gcd(b, a % b);
    }
};
int main()
{
    Fraction a[100];
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        a[i].input();
    }
    for (int i = 0; i < n; i++)
    {
        a[i].rutGon();
    }
    for (int i = 0; i < n; i++)
    {
        a[i].display();
    }
    return 0;
}