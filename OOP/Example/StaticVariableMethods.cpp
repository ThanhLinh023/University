#include<iostream>
using namespace std;
class Math
{
    public:
        static int x, y;
        static int abs(int x)
        {
            return x < 0 ? -x : x;
        }
        static int add(int x, int y)
        {
            return x+y;
        }
        static int subtract(int x, int y)
        {
            return x-y;
        }
        static int min(int x, int y)
        {
            if (x < y) return x;
                return y;
        }
        static int max(int x, int y)
        {
            if (x > y) return x;
                return y;
        }
        static int pow(int x, int y)
        {
            int pow = 1;
            for (int i = 1; i <= y; i++)
                {
                    pow *= x;
                }
            return pow;
        }
};
int Math::x = 10;
int main() 
{
	cout << Math::abs(-2) << endl;
	cout << Math::add(2, 3) << endl;
	cout << Math::subtract(2, 3) << endl;
	cout << Math::min(2, 3) << endl;
	cout << Math::max(2, 3) << endl;
	cout << Math::pow(2, 3) << endl;
    Math a;
    a.x = 100;
    cout << a.x;
	return 0;
}