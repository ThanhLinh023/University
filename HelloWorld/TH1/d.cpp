#include<iostream>
using namespace std;
int main()
{
    float toan, ly, hoa;
    float hst = 2.0;
    float hsl = 1.0;
    float hsh = 1.0;
    float dtb = 0;
    cout << "Nhap diem toan : ";
    cin >> toan;
    cout << "Nhap diem ly : ";
    cin >> ly;
    cout << "Nhap diem hoa : ";
    cin >> hoa;
    dtb = (toan * hst + ly * hsl + hoa * hsh) / (hst + hsl + hsh);
    cout << "Diem trung binh la : " << dtb;
    return 0;
}