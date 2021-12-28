#include<iostream>
using namespace std;
int main()
{
    int month, year, day;
    cout << "Nhap vao thang va nam : ";
    cin >> month >> year;
    if (month > 0 && month <= 12 && year > 1975)
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
            {
                day = 31;
                break;
            }
            case 4:
            case 6:
            case 9:
            case 11:
            {
                day = 30;
                break;
            }
            default:
            {
                if (year % 400 == 0 || year % 4 == 0 && year % 100 != 0)
                {
                    day = 29;
                    break;
                }
                else
                {
                    day = 28;
                    break;
                }
            }
        }
        cout << "So ngay cua thang " << month << " nam " << year << " la : " << day;
    }
    else
    {
        cout << "Nhap lai";
    }
    return 0;
}