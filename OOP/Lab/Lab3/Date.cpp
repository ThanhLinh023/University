#include <iostream>
#include <math.h>
using namespace std;
bool leapYear(int y)
{
    if (y % 400 == 0 || (y % 4 == 0 && y % 100 != 0)) return true;
    return false;
}
class Date
{
public:
    int day, month, year;
    Date() {}
    void input()
    {
        cin >> day >> month >> year;
        day = abs(day);
        month = abs(month);
        year = abs(year);
        switch (month)
        {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            day %= 31;
            if (day == 0) day = 31;
            break;
        }
    }
    void increase(int &x)
    {
        switch (month)
        {
            case 1:
            case 3:
            case 5:
            case 7:
            case 8:
            case 10:
            case 12:
                day += x;
                if (day > 31)
                {
                    month += (day / 31);
                    day %= 31;
                }
                if (month > 12)
                {
                    month %= 12;
                    year += 1;
                }
                break;
            case 4:
            case 6:
            case 9:
            case 11:
                day += x;
                if (day > 30)
                {
                    month += (day / 30);
                    day %= 30;
                }
                if (month > 12)
                {
                    month %= 12;
                    year += 1;
                }
                break;
            case 2:
                if (leapYear(year))
                {
                    day += x;
                    if (day > 29)
                    {
                        month += (day / 29);
                        day %= 29;
                    }
                    if (month > 12)
                    {
                        month %= 12;
                        year += 1;
                    }
                }
                else
                {
                    day += x;
                    if (day > 28)
                    {
                        month += (day / 28);
                        day %= 28;
                    }
                    if (month > 12)
                    {
                        month %= 12;
                        year += 1;
                    }
                }
                break;
                
        }
    }
    void decrease(int &x)
    {
        day -= x;
        if (day < 1)
        {
            month -= 1;
            day = 31 + day;
        }
    }
    int diff(Date &y)
    {
        int dY(0), dM(0), d(0);
        for (int i = year; i < y.year; i++)
        {
            if (leapYear(i)) dY += 366;
            else dY += 365;
        }
        int a[] = {31,28,31,30,31,30,31,31,30,31,30,31};
        if (leapYear(y.year)) a[1] = 29;
        if (month > y.month)
        {
            for (int i = y.month; i < month; i++)
            {
                dM -= a[i - 1];
            }
        }
        else
        {
            for (int i = month; i < y.month; i++)
            {
                dM += a[i - 1];
            }
        }
        d = abs(y.day - day);
        return (dY + dM + d);
    }
};
int main()
{
    Date a;
    int n;
    a.input();
    if (a.day > 0 && a.day <= 31 && a.month > 0 && a.month <= 12 && a.year > 0)
    {
        while (1)
        {
            cin >> n;
            if (n == 1)
            {
                int x;
                cin >> x;
                a.increase(x);
            }
            else if (n == 2)
            {
                int y;
                cin >> y;
                a.decrease(y);
            }
            else if (n == 3)
            {
                Date b;
                b.input();
                cout << a.diff(b);
                break;
            }
        }
    }
    else cout << "ERROR";
    return 0;
}