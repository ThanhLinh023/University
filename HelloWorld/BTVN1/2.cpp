#include<iostream>
using namespace std;

int main()
{
    char c;
    cout << "Nhap vao ki tu : ";
    cin >> c;
    cout << "Ki tu in hoa tuong ung voi ki tu " << c << " la " << char (c - 32);
    return 0;
}