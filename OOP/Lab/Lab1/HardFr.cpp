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
        if (ms < 0)
        {
            ts = -ts;
            ms = -ms;
        }
    }
    void display()
    {
        cout << ts << "/" << ms << endl;
    }
    double simplify(int a, int b)
    {
        double sum(0);
        sum = 1.0 * a / b;
        return sum;
    }
};
int main()
{
    Fraction a, b, temp;
    int n;
    double max = -pow(10, 9);
    double min = pow(10, 9);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        temp.input();
        double res = temp.simplify(temp.ts, temp.ms);
        if (res < min)
        {
            a.ts = temp.ts;
            a.ms = temp.ms;
            min = res;
        }
        if (res > max)
        {
            b.ts = temp.ts;
            b.ms = temp.ms;
            max = res;
        }
    }
    a.display();
    b.display();
    return 0;
}