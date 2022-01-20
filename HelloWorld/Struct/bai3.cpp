#include<iostream>
#include<string.h>
using namespace std;

struct thongTin
{
    int ma;
    string ten;
    long long danSo;
    float square;
};

thongTin *input(thongTin *&a, int &n)
{
    a = new thongTin[n];
    cout << "Nhap vao thong tin cac tinh.\n";
    for (int i = 0; i < n; i++)
    {
        cout << "Nhap ma tinh : ";
        cin >> a[i].ma;
        cout << "Nhap ten tinh : ";
        cin.ignore();
        getline(cin, a[i].ten);
        cout << "Nhap dan so : ";
        cin >> a[i].danSo;
        cout << "Nhap dien tich : ";
        cin >> a[i].square;
        cout << "------------------\n";
    }
    return a;
}

void output(thongTin *&a, int n)
{
    cout << "\nThong tin cac tinh la : \n";
    for (int i = 0; i < n; i++)
    {
        cout << "\nMa tinh : " << a[i].ma;
        cout << "\nTen tinh : " << a[i].ten;
        cout << "\nDan so : " << a[i].danSo << " nguoi.";
        cout << "\nDien tich : " << a[i].square << " kilomet vuong.\n";
        cout << "------------------";
    }
}

int main()
{
    int n;
    thongTin *a;
    cout << "Nhap so luong tinh : ";
    cin >> n;
    input(a, n);
    output(a, n);
    cout << "\nCac tinh co dan so tren 1 trieu nguoi la : ";
    for (int i = 0; i < n; i++)
    {
        if (a[i].danSo > 1000000)
        {
            cout << a[i].ten << " ";
        }
    }
    int max = a[0].square;
    string k;
    for (int i = 0; i < n; i++)
    {
        if (a[i].square > max)
        {
            max = a[i].square;
            k = a[i].ten;
        }
    }
    cout << "\nTinh co dien tich lon nhat la : " << k;
    return 0;
}