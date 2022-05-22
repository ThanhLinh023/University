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
    void increase()
    {
        int t = hour * 3600 + minute * 60 + second;
        t += 1;
        hour = t / 3600;
        minute = (t % 3600) / 60;
        second = (t % 3600) % 60;
    }
    void decrease()
    {
        int t = hour * 3600 + minute * 60 + second;
        t -= 1;
        hour = t / 3600;
        minute = (t % 3600) / 60;
        second = (t % 3600) % 60;
    }
    void increaseX(int &x)
    {
        int t = hour * 3600 + minute * 60 + second;
        t += x;
        hour = t / 3600;
        minute = (t % 3600) / 60;
        second = (t % 3600) % 60;
    }
    void decreaseX(int &x)
    {
        int t = hour * 3600 + minute * 60 + second;
        t = abs(t - x);
        hour = t / 3600;
        minute = (t % 3600) / 60;
        second = (t % 3600) % 60;
    }
};
int main()
{
    Watch a;
    a.input();
    int n;
    while (1)
    {
        cin >> n;
        if (n == 1)
        {
            a.increase();
        }
        if (n == 2)
        {
            a.decrease();
        }
        if (n == 3)
        {
            int x;
            cin >> x;
            a.increaseX(x);
        }
        if (n == 4)
        {
            int y;
            cin >> y;
            a.decreaseX(y);
        }
        if (n == -1)
        {
            a.display();
            break;
        }
    }
    return 0;
}