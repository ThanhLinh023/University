#include<iostream>
using namespace std;
int main()
{
    int year;
    int tuoi = 0;
    cout << "Nhap nam sinh : ";
    cin >> year;
    tuoi = 2021 - year;
    cout << "Tuoi la : " << tuoi;
    return 0;
}