#include<iostream>
#include<math.h>
using namespace std;
class Time
{
private:
    int hour, minute, second;
public:
    Time() {}
    void input()
    {
        cout << "Enter time: ";
        cin >> hour >> minute >> second;
    }
    void display()
    {
        cout << hour << "h" << minute << "m" << second << "s";
    }
    friend Time operator+(Time &a, Time &b);
    friend Time operator-(Time &a, Time &b);
    friend bool operator>(Time &a, Time &b);
    friend bool operator<(Time &a, Time &b);
};
Time operator+(Time &a, Time &b)
{
    Time t;
    int sum(0);
    sum = a.hour * 3600 + a.minute * 60 + a.second + b.hour * 3600 + b.minute * 60 + b.second;
    t.hour = sum / 3600;
    t.minute = (sum % 3600) / 60;
    t.second = (sum % 3600) % 60;
    return t;
}
Time operator-(Time &a, Time &b)
{
    Time t;
    int sum(0);
    sum = abs(a.hour * 3600 + a.minute * 60 + a.second - b.hour * 3600 - b.minute * 60 - b.second);
    t.hour = sum / 3600;
    t.minute = (sum % 3600) / 60;
    t.second = (sum % 3600) % 60;
    return t;
}
bool operator>(Time &a, Time &b)
{
    if (a.hour > b.hour)
        return true;
    else if (a.hour < b.hour)
        return false;
    else
    {
        if (a.minute > b.minute)
            return true;
        else if (a.minute < b.minute)
            return false;
        else
        {
            if (a.second > b.second)
                return true;
            else
                return false;
        }
    }
}
bool operator<(Time &a, Time &b)
{
    if (a.hour < b.hour)
        return true;
    else if (a.hour > b.hour)
        return false;
    else
    {
        if (a.minute < b.minute)
            return true;
        else if (a.minute > b.minute)
            return false;
        else
        {
            if (a.second < b.second)
                return true;
            else
                return false;
        }
    }
}
int main()
{
    Time x, y, m, n;
    x.input();
    y.input();
    cout << "The first: ";
    x.display();
    cout << endl;
    cout << "The second: ";
    y.display();
    m = x + y;
    n = x - y;
    cout << endl;
    cout << "Sum of time: ";
    m.display();
    cout << endl;
    cout << "Sub of time: ";
    n.display();
    cout << endl;
    if (x > y)
    {
        x.display();
        cout << " is bigger\n";
    }
    else if (x < y)
    {
        y.display();
        cout << " is bigger\n";
    }
    else
    {
        x.display();
        cout << " is as same as ";
        y.display();
    }
    return 0;
}