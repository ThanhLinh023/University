#include<iostream>
#include<math.h>
using namespace std;

class Complex
{
private:
    float real;
    float vir;
public:
    Complex() {}
    Complex(float x, float y) : real(x), vir(y) {}
    void input()
    {
        cin >> real >> vir;
    }
    void dislay()
    {
        if (vir != 0) cout << real << " + " << vir << "i" << endl;
        else cout << real << endl;
    }
    Complex add(Complex a, Complex b)
    {
        Complex result;
        result.real = a.real + b.real;
        result.vir = a.vir + b.vir;
        return result;
    }
    Complex diff(Complex a, Complex b)
    {
        Complex result;
        result.real = a.real - b.real;
        result.vir = a.vir - b.vir;
        return result;
    }
    Complex mul(Complex a, Complex b)
    {
        Complex result;
        result.real = a.real * b.real - a.vir * b.vir;
        result.vir = a.real * b.vir + a.vir * b.real;
        return result;
    }
    Complex divide(Complex a, Complex b)
    {
        Complex result;
        result.real = (a.real * b.real + a.vir * b.vir) / (pow(b.real, 2) + pow(b.vir, 2));
        result.vir = (b.real * a.vir - a.real * b.vir) / (pow(b.real, 2) + pow(b.vir, 2));
        return result;
    }
    float extreme()
    {
        return sqrt(pow(real, 2) + pow(vir, 2));
    }
};
int main()
{
    Complex x, y;
    x.input();
    y.input();
    x.add(x, y).dislay();
    x.diff(x, y).dislay();
    x.mul(x, y).dislay();
    x.divide(x, y).dislay();
    cout << x.extreme() << " " << y.extreme();
    return 0;
}