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
    void display()
    {
        if (vir == 0) cout << real << endl;
        else if (real == 0) cout << vir << "i\n";
        else if (vir != 0 && vir < 0) cout << real << " - " << -vir << "i" << endl;
        else cout << real << " + " << vir << "i" << endl;
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
    Complex quote(Complex c1, Complex c2)
    {
        Complex result;
        Complex a, b;
        a.real = 2;
        a.vir = 0;
        b.real = 4;
        b.vir = 0;
        result = divide((mul(add(c1, c2), diff(c2, mul(a, c1)))), diff(c1, mul(b, c2)));
        return result;
    }
};
int main()
{
    Complex c1, c2;
    c1.input();
    c2.input();
    if (c1.extreme() == 0 || c2.extreme() == 0) cout << "ERROR";
    else
    {
        c1.quote(c1, c2).display();
    }
    return 0;
}