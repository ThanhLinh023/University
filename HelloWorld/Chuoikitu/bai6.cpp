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
    int dem(0);
    input(s);
    for (int i = 0; i < strlen(s); i++)
    {
        if (s[i] != s[strlen(s) - 1 - i])
        {
            dem++;
        }
    }
    if (dem == 0)
    {
        cout << "Chuoi doi xung.";
    }
    else
    {
        cout << "Chuoi khong doi xung.";
    }
    return 0;
}