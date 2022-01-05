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
    for (int i = 0; i < strlen(s); i++)
    {
        if (s[i] >= 65 && s[i] <= 90)
        {
            cout << s[i] << " ";
        }
    }
    return 0;
}