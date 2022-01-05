#include<iostream>
#include<string.h>
using namespace std;
void input(char s[100])
{
    cout << "Nhap vao chuoi : ";
    cin.getline(s, 100);
}
void gan(char s[100], int h[100])
{
    for (int i = 0; i < strlen(s); i++)
    {
        for (int j = i; j < strlen(s); j++)
        {
            if (s[i] == s[j])
            {
                h[i]++;
            }
        }
    }
}
void output(char s[100], int h[100])
{
    int max = h[0];
    for (int i = 0; i < strlen(s); i++)
    {
        if (h[i] > max) max = h[i];
    }
    for (int i = 0; i < strlen(s); i++)
    {
        if (h[i] == max and s[i] == ' ')
        {
            cout << "Ki tu khoang trong xuat hien nhieu nhat : " << max << " lan." << endl;
        }
        if (h[i] == max and s[i] != ' ')
        {
            cout << "Ki tu " << s[i] << " xuat hien nhieu nhat : " << max << " lan.\n";
        }
    }
}
int main()
{
    char s[100];
    int h[100] = {0};
    input(s);
    gan(s, h);
    output(s, h);
    return 0;
}