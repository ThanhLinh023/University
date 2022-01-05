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
        int dem(1);
        for (int j = i + 1; j <= strlen(s); j++)
        {
            if (s[j] == s[i])
            {
                dem++;
                s[j] = 0;
            }
        }
        if (s[i] != 0 and s[i] == ' ')
        {
            cout << "Khoang trang xuat hien : " << dem << " lan.\n";
        }
        if (s[i] != 0 and s[i] != ' ')
        {
            cout << "Ki tu " << s[i] << " xuat hien : " << dem << " lan.\n";
        }
    }
    return 0;
}