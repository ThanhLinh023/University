#include<iostream>
#include<math.h>
using namespace std;
class Watch
{
private:
    int hour;
    int minute;
    int second;
public:
    Watch() {}
    void input()
    {
        cin >> hour >> minute >> second;
        if (hour < 0 || minute < 0 || second < 0)
        {
            hour = abs(hour);
            minute = abs(minute);
            second = abs(second);
        }
        if (second >= 60)
        {
            minute += (second / 60);
            second %= 60;
        }
        if (minute >= 60)
        {
           hour += (minute / 60);
           minute %= 60;
        }
        if (hour >= 24)
        {
            hour %= 24;
        }
    }
    void display()
    {
        if (hour < 0 || minute < 0 || second < 0)
        {
            hour = abs(hour);
            minute = abs(minute);
            second = abs(second);
        }
        cout << hour << "h " << minute << "p " << second << "s\n";
    }
    Watch operator++()
    {
        int t = hour * 3600 + minute * 60 + second;
        t += 1;
        hour = t / 3600;
        minute = (t % 3600) / 60;
        second = (t % 3600) % 60;
        return *this;
    }
    Watch operator--()
    {
        int t = hour * 3600 + minute * 60 + second;
        t -= 1;
        hour = t / 3600;
        minute = (t % 3600) / 60;
        second = (t % 3600) % 60;
        return *this;
    }
    Watch operator+(int &x)
    {
        Watch temp = *this;
        int t = hour * 3600 + minute * 60 + second;
        t += x;
        hour = t / 3600;
        minute = (t % 3600) / 60;
        second = (t % 3600) % 60;
        return temp;
    }
    Watch operator-(int &x)
    {
        Watch temp = *this;
        int t = hour * 3600 + minute * 60 + second;
        t = abs(t - x);
        hour = t / 3600;
        minute = (t % 3600) / 60;
        second = (t % 3600) % 60;
        return temp;
    }
};
int main()
{
    Watch a;
    a.input();
    int n;
    cin >> n;
    while (n > 0)
    {
        string s;
        cin >> s;
        if (s == "++")
        {
            a.operator++();
        }
        else if (s == "--")
        {
            a.operator--();
        }
        else if (s == "+")
        {
            int x;
            cin >> x;
            a.operator+(x);
        }
        else if (s == "-")
        {
            int y;
            cin >> y;
            a.operator-(y);
        }
        n--;
    }
    a.display();
    return 0;
}