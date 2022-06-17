#include<iostream>
using namespace std;
class Time
{
private:
    int hour, min, sec;
public:
    Time() {}
    friend istream &operator>>(istream &is, Time &a);
    friend ostream &operator<<(ostream &os, const Time &a);
    friend Time operator++(Time &a);
    friend Time operator--(Time &a);
};
istream &operator>>(istream &is, Time &a)
{
    is >> a.hour >> a.min >> a.sec;
    return is;
}
ostream &operator<<(ostream &os, const Time &a)
{
    os << a.hour << "h " << a.min << "m " << a.sec << "s\n";
    return os;
}
Time operator++(Time &a)
{
    Time temp;
    int sum(0);
    sum = a.hour * 3600 + a.min * 60 + a.sec + 1;
    temp.hour = sum / 3600;
    temp.min = (sum % 3600) / 60;
    temp.sec = (sum % 3600) % 60;
    return temp;
}
Time operator--(Time &a)
{
    Time temp;
    int sum(0);
    sum = a.hour * 3600 + a.min * 60 + a.sec - 1;
    temp.hour = sum / 3600;
    temp.min = (sum % 3600) / 60;
    temp.sec = (sum % 3600) % 60;
    return temp;
}
int main()
{
    Time a, b;
    cout << "Nhap vao gio thu nhat: ";
    cin >> a;
    cout << "Nhap vao gio thu hai: ";
    cin >> b;
    a = ++a;
    b = --b;
    cout << "Gio thu nhat: ";
    cout << a;
    cout << "Gio thu hai: ";
    cout << b;
    return 0;
}