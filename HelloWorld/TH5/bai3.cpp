#include<iostream>
#include<string.h>
using namespace std;

void input(char s[100])
{
    cout << "Nhap vao chuoi : ";
    cin.getline(s, 100);
}

void cauA(char s[100])
{
    cout << "Cac ki tu in thuong trong chuoi la : ";
    for (int i = 0; i < strlen(s); i++)
    {
        if (s[i] >= 'a' and s[i] <= 'z')
        {
            cout << s[i] << " ";
        }
    }
    cout << "\n";
}

string cauB(char s[100])
{
    for (int i = 0; i < strlen(s); i++)
    {
        for (int j = i + 1; j < strlen(s); j++)
        {
            char t = s[i];
            s[i] = s[j];
            s[j] = t;
        }
    }
    return s;
}

void cauC(char s[100])
{
    cauB(s);
    char h[100] = " ";
    for (int i = 0; i < strlen(s); i++)
    {
        if (i % 2 == 0)
        {
            h[i] = toupper(s[i]);
        }
        else
        {
            h[i] = tolower(s[i]);
        }
    }
    cout << "Chuoi moi la : " << h << endl;
}

int dem(char s[100], char x)
{
    int d(0);
    for (int i = 0; i < strlen(s); i++)
    {
        if (s[i] == x)
        {
            d++;
        }
    }
    return d;
}

void cauD(char s[100])
{
    cout << "Cac ki tu xuat hien 1 lan la : ";
    for (int i = 0; i < strlen(s); i++)
    {
        if (dem(s, s[i]) == 1) cout << s[i] << " ";
    }
    cout << "\n";
}

void del(char s[100], int x)
{
    int n = strlen(s);
    for (int i = x; i < n ; i++)
    {
        s[i] = s[i+1];
    }
    n--;
}

void cauE(char s[100])
{
    while (s[0] == ' ')
    {
        del(s, 0);
    }
    cout << "Chuoi sau khi xoa khoang trang : " << s;
}

int main()
{
    char s[100];
    input(s);
    cauA(s);
    cout << "Chuoi sau khi dao nguoc la : " << cauB(s) << endl;
    cauC(s);
    cauD(s);
    cauE(s);
    return 0;
}