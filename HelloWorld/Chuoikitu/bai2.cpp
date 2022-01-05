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
        for (int j = i + 1; j < strlen(s); j++)
        {
            if (s[i] != s[j])
            {
                char t = s[i];
                s[i] = s[j];
                s[j] = t;
            }
        }
    }
    cout << "Chuoi sau khi dao nguoc la : ";
    cout << s;
    return 0;
}