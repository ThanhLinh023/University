#include<iostream>
#include<string.h>
using namespace std;
void input(char s[100])
{
    cout << "Nhap vao chuoi : ";
    cin.getline(s, 100);
}
int main()
{
    char s[100];
    input(s);
    if (s[0] >= 65 and s[0] <= 90)
    {
        for (int i = 0; i < strlen(s); i++)
        {
            if (i % 2 == 0)
            {
                s[i] = tolower(s[i]);
            }
            else
            {
                s[i] = toupper(s[i]);
            }
        }
    }
    else
    {
        for (int i = 0; i < strlen(s); i++)
        {
            if (i % 2 == 0)
            {
                s[i] = toupper(s[i]);
            }
            else
            {
                s[i] = tolower(s[i]);
            }
        }
    }
    cout << "Chuoi moi la : ";
    cout << s;
    return 0;
}