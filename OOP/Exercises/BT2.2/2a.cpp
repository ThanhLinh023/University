#include <iostream>
using namespace std;
class Date
{
public:
    int day;
    int month;
    int year;
    void input()
    {
        cin >> day >> month >> year;
    }
    void display()
    {
        cout << day << "/" << month << "/" << year << endl;
    }
};
int main()
{
    Date today;
    today.input();
    if (today.day > 0 && today.day < 32 && today.month > 0 && today.month < 13 && today.year > 0)
    {
        switch (today.month)
        {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            today.day++;
            if (today.day >= 32)
            {
                today.day = 1;
                today.month++;
                if (today.month >= 13)
                {
                    today.day = 1;
                    today.month = 1;
                    today.year++;
                }
            }
            break;
        case 4:
        case 6:
        case 9:
        case 11:
            today.day++;
            if (today.day >= 31)
            {
                today.day = 1;
                today.month++;
            }
            break;
        case 2:
            today.day++;
            if (today.year % 400 == 0 || (today.year % 4 == 0 && today.year % 100 != 0))
            {
                if (today.day >= 30)
                {
                    today.day = 1;
                    today.month++;
                }
            }
            else
            {
                if (today.day >= 29)
                {
                    today.day = 1;
                    today.month++;
                }
            }
            break;
        }
        today.display();
    }
    else
        cout << "ERROR";
    return 0;
}
