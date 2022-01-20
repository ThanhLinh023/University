#include<iostream>
#include<math.h>

using namespace std;

struct diem
{
    int hd;
    int td;
};

void input(diem &a)
{
    cout << "Nhap hoanh do : ";
    cin >> a.hd;
    cout << "Nhap tung do : ";
    cin >> a.td;
}
void output(diem a)
{
    cout << "Toa do diem vua nhap la : ";
    cout << "(" << a.hd << "; " << a.td << ")";
}
int main()
{
    diem x, y;
    int k1(0), k2(0);
    cout << "Nhap 2 diem bat ki.\n";
    input(x);
    output(x);
    cout << "\n";
    input(y);
    output(y);
    k1 = y.hd - x.hd;
    k2 = y.td - x.td;
    cout << "\nCau b, khoang cach giua 2 diem " << "(" << x.hd << "; " << x.td << ")" << " va " << "(" << y.hd << "; " << y.td << ")" << " la : ";
    cout << sqrt((k1 * k1) + (k2 * k2)) << "\n";
    cout << "Cau c, diem doi xung qua goc toa do cua diem " << "(" << x.hd << "; " << x.td << ")" << " la " << "(" << -x.hd << "; " << -x.td << ")";
    cout << " va cua diem " << "(" << y.hd << "; " << y.td << ")" << " la " << "(" << -y.hd << "; " << -y.td << ")";
    cout << "\nCau d, diem doi xung qua truc Ox cua diem " << "(" << x.hd << "; " << x.td << ")" << " la " << "(" << x.hd << "; " << -x.td << ")";
    cout << " va doi xung qua truc Oy la " << "(" << -x.hd << "; " << x.td << ")";
    cout << "\nDiem doi xung qua truc Ox cua diem " << "(" << y.hd << "; " << y.td << ")" << " la " << "(" << y.hd << "; " << -y.td << ")";
    cout << " va doi xung qua truc Oy la " << "(" << -y.hd << "; " << y.td << ")";
    return 0;
}
