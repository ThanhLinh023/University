#include<iostream>
using namespace std;
class Time
{
private:
    int hour;
    int minute;
    int second;
public:
    Time(int hour, int minute, int second)
    {
        this->hour = hour;
        this->minute = minute;
        this->second = second;
    }
    void setTime(int hour, int minute, int second)
    {
        this->hour = hour;
        this->minute = minute;
        this->second = second;
    }
    void setHour(int hour)
    {
        this->hour = hour;
    }
    void setMinute(int minute)
    {
        this->minute = minute;
    }
    void setSecond(int second)
    {
        this->second = second;
    }
    int getHour()
    {
        return hour;
    }
    int getMinute()
    {
        return minute;
    }
    int getSecond()
    {
        return second;
    }
    void nextSecond()
    {
        this->second = second + 1;
        if (second == 60)
        {
            this->second = 0;
            this->minute = minute + 1;
            if (minute == 60)
            {
                this->minute = 0;
                this->hour = hour + 1;
                if (hour == 24)
                {
                    this->hour = 0;
                }
            }
        }
    }
    void previousSecond()
    {
        this->second = second - 1;
        if (second == -1)
        {
            this->second = 59;
            this->minute = minute - 1;
            if (minute == -1)
            {
                this->minute = 59;
                this->hour = hour - 1;
                if (hour == -1)
                {
                    this->hour = 23;
                }
            }
        }
    }
    void display()
    {
        if (hour != 24)
        {
            if (hour > 10)
            {
                if (minute > 10)
                {
                    if (second > 10)
                    {
                        cout << hour << ":" << minute << ":" << second << endl;
                    }
                    else
                    {
                        cout << hour << ":" << minute << ":0" << second << endl;
                    }
                }
                else
                {
                    if (second > 10)
                    {
                        cout << hour << ":0" << minute << ":" << second << endl;
                    }
                    else
                    {
                        cout << hour << ":0" << minute << ":0" << second << endl;
                    }
                }
            }
            else
            {
                if (minute > 10)
                {
                    if (second > 10)
                    {
                        cout << "0" << hour << ":" << minute << ":" << second << endl;
                    }
                    else
                    {
                        cout << "0" << hour << ":" << minute << ":0" << second << endl;
                    }
                }
                else
                {
                    if (second > 10)
                    {
                        cout << "0" << hour << ":0" << minute << ":" << second << endl;
                    }
                    else    
                    {
                        cout << "0" << hour << ":0" << minute << ":0" << second << endl;
                    }
                }
            }
        }
        else
        {
            if (minute > 10)
            {
                if (second > 10)
                {
                    cout << "00" << ":" << minute << ":" << second << endl;
                }
                else
                {
                    cout << "00" << ":" << minute << ":0" << second << endl;
                }
            }
            else
            {
                if (second > 10)
                {
                    cout << "00" << ":0" << minute << ":" << second << endl;
                }
                else
                {
                    cout << "00" << ":0" << minute << ":0" << second << endl;
                }
            }
        }
    }
};
int main() 
{
	Time t(12, 1, 1);
	t.display();
	t.setTime(23, 59, 59);
	t.display();
	t.nextSecond();
	t.display();
	t.nextSecond();
	t.display();
	t.setTime(7, 0, 0);
	t.display();
	t.previousSecond();
	t.display();
	return 0;
}