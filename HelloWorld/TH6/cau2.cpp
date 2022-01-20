#include<iostream>
#include<math.h>
using namespace std;

struct phanSo 
{
    int ts;
    int ms;
};

void input(phanSo &a)
{
    cout << "Nhap vao phan so : ";
    cin >> a.ts >> a.ms;
    if (a.ms < 0)
    {
        a.ts = -a.ts;
        a.ms = abs(a.ms);
    }
}

void calc(phanSo a, phanSo b)
{
    int msc = a.ms * b.ms;
    int tong(0), hieu(0), tich(0), thuong(0);
    tong = a.ts * (msc / a.ms) + b.ts * (msc / b.ms);
    hieu = a.ts * (msc / a.ms) - b.ts * (msc / b.ms);
    tich = a.ts * b.ts;
    thuong = a.ts * b.ms;
    if (tong == 0 and hieu == 0 )
    {
        cout << "\nCau b, tong va hieu hai phan so " << a.ts << "/" << a.ms << " va " << b.ts << "/" << b.ms << " la 0 va 0.";
    }
    else if (tong != 0 and hieu == 0)
    {
        cout << "\nCau b, tong va hieu cua hai phan so " << a.ts << "/" << a.ms << " va " << b.ts << "/" << b.ms << " la : " << tong << "/" << msc << " va 0.";
    }
    else if (tong == 0 and hieu != 0)
    {
        cout << "\nCau b, tong va hieu cua hai phan so " << a.ts << "/" << a.ms << " va " << b.ts << "/" << b.ms << " la : 0 va " << tong << "/" << msc;
    }
    else cout << "\nCau b, tong va hieu hai phan so " << a.ts << "/" << a.ms << " va " << b.ts << "/" << b.ms << " la : " << tong << "/" << msc << " va " << hieu << "/" << msc;
    if (a.ts == 0 or b.ts == 0) cout << "\nCau c, tich va thuong hai phan so la 0 va 0.";
    else cout << "\nCau c, tich va thuong hai phan so " << a.ts << "/" << a.ms << " va " << b.ts << "/" << b.ms << " la : " << a.ts * b.ts << "/" << a.ms * b.ms << " va " << a.ts * b.ms << "/" << a.ms * b.ts;
}

int main()
{
    phanSo x, y;
    input(x);
    input(y);
    if (x.ms != 0 and y.ms != 0)
    {
        if (x.ts == 0 and y.ts == 0)
        {
            cout << "Hai phan so vua nhap la : 0 va 0";
        }
        else if (x.ts != 0 and y.ts == 0)
        {
            cout << "Hai phan so vua nhap la : " << x.ts << "/" << x.ms << " va 0"; 
        }
        else if (x.ts == 0 and y.ts != 0)
        {
            cout << "Hai phan so vua nhap la : 0 va " << y.ts << "/" << y.ms;
        }
        else cout << "Hai phan so vua nhap la : " << x.ts << "/" << x.ms << " va " << y.ts << "/" << y.ms;
        calc(x, y);
    }
    else cout << "Khong the thuc hien.";
    return 0;
}
