#include<iostream>
using namespace std;
class CPU
{
protected:
    string ma;
    string hang;
    int soCore;
    float xung;
    int gia;
public:
    CPU() {}
    void input()
    {
        cin >> ma;
    }
    virtual void display()
    {
        cout << "CPU: " << ma;
    }
    virtual int layGia() = 0;
};
class Alpha : public CPU
{
public:
    Alpha()
    {
        soCore = 2;
        xung = 1.8;
        gia = 200;
        hang = "Black";
    }
    void display()
    {
        CPU::display();
        cout << " Alpha " << hang << " " << soCore << " " << xung << " " << gia;
    }
    int layGia()
    {
        return gia;
    }
};
class Beta : public CPU
{
public:
    Beta()
    {
        soCore = 4;
        xung = 2.46;
        gia = 400;
        hang = "Black";
    }
    void display()
    {
        CPU::display();
        cout << " Beta " << hang << " " << soCore << " " << xung << " " << gia;
    }
    int layGia()
    {
        return gia;
    }
};
class Gamma : public CPU
{
public:
    Gamma()
    {
        soCore = 4;
        xung = 2.6;
        gia = 600;
        hang = "White";
    }
    void display()
    {
        CPU::display();
        cout << " Gamma " << hang << " " << soCore << " " << xung << " " << gia;
    }
    int layGia()
    {
        return gia;
    }
};
class Vo
{
protected:
    string maVo;
    string hang;
    int gia;
    string mau;
public:
    Vo() {}
    virtual void input()
    {
        cin >> maVo;
    }
    virtual void display()
    {
        cout << "Vo smartphone: " << maVo;
    }
    virtual int layGia() = 0;
};
class Nhom : public Vo
{
public:
    Nhom()
    {
        gia = 400;
        hang = "Black";
    }
    void input()
    {
        Vo::input();
        int k;
        cin >> k;
        if (k == 1)
        {
            mau = "Do";
        }
        if (k == 2)
        {
            mau = "Den";
        }
    }
    void display()
    {
        Vo::display();
        cout << " Nhom " << hang << " " << mau << " " << gia;
    }
    int layGia()
    {
        return gia;
    }
};
class Nhua : public Vo
{
public:
    Nhua()
    {
        gia = 200;
        hang = "White";
    }
    void input()
    {
        Vo::input();
        int k;
        cin >> k;
        if (k == 1)
        {
            mau = "Do";
        }
        if (k == 2)
        {
            mau = "Den";
        }
        if (k == 3)
        {
            mau = "Xanh";
        }
    }
    void display()
    {
        Vo::display();
        cout << " Nhua " << hang << " " << mau << " " << gia;
    }
    int layGia()
    {
        return gia;
    }
};
class Manhinh
{
protected:
    string maMH;
    string hang;
    int gia;
public:
    Manhinh() {}
    
    virtual void input() {}
    virtual void display() {}
    virtual int layGia() = 0;
};
class HD : public Manhinh
{
public:
    HD()
    {
        gia = 200;
    }
    void display()
    {
        cout << " HD " << gia;
    }
    int layGia()
    {
        return gia;
    }
};
class FHD : public Manhinh
{
protected:
    int chongLoa;
public:
    FHD() {}
    void input()
    {
        cin >> chongLoa;
        if (chongLoa == 1)
        {
            gia = 500;
        }
        if (chongLoa == 0)
        {
            gia = 300;
        }
    }
    void display()
    {
        Manhinh::display();
        cout << " FullHD " << gia;
        if (chongLoa == 1)
        {
            cout << " Co chong loa";
        }
    }
    int layGia()
    {
        return gia;
    }
};
class Phone
{
protected:
    string ma;
    CPU *loai;
    Manhinh *mh;
    Vo *voMay;
    string maMH, hang;
public:
    Phone() {}
    virtual void input()
    {
        cin >> ma;
    }
    virtual void display()
    {
        cout << "Smartphone: " << ma;
    }
    virtual float tinhTien() = 0;
};
class Venus : public Phone
{
public:
    Venus() {}
    void input()
    {
        Phone::input();
        int k1, k2, k3;
        cin >> k1;
        if (k1 == 1)
        {
            loai = new Alpha();
        }
        if (k1 == 2)
        {
            loai = new Beta();
        }
        loai->input();
        cin >> maMH;
        cin >> hang;
        cin >> k2;
        if (k2 == 1)
        {
            mh = new HD();
        }
        if (k2 == 2)
        {
            mh = new FHD();
            mh->input();
        }
        cin >> k3;
        if (k3 == 1)
        {
            voMay = new Nhom();
        }
        if (k3 == 2)
        {
            voMay = new Nhua();
        }
        voMay->input();
    }
    void display()
    {
        Phone::display();
        cout << " Venus " << tinhTien();
        cout << endl;
        loai->display();
        cout << endl;
        cout << "Man hinh: " << maMH << " " << hang;
        mh->display();
        cout << endl;
        voMay->display();
    }
    float tinhTien()
    {
        return (loai->layGia() + mh->layGia() + voMay->layGia()) * 1.3;
    }
};
class Mars : public Phone
{
public:
    Mars() {}
    void input()
    {
        int k1;
        cin >> k1;
        if (k1 == 1)
        {
            loai = new Alpha();
        }
        if (k1 == 2)
        {
            loai = new Beta();
        }
        if (k1 == 3)
        {
            loai = new Gamma();
        }
        mh = new FHD();
        mh->input();
        voMay = new Nhom();
        voMay->input();
    }
    void display()
    {
        Phone::display();
        cout << " Mars " << tinhTien();
        cout << endl;
        loai->display();
        cout << endl;
        mh->display();
        cout << endl;
        voMay->display();
    }
    float tinhTien()
    {
        return (loai->layGia() + mh->layGia() + voMay->layGia()) * 1.5;
    }
};
class Jupiter : public Phone
{
public:
    Jupiter()
    {
        loai = new Gamma();
        mh = new FHD();
        voMay = new Nhom();
    }
    void display()
    {
        Phone::display();
        cout << " Jupiter " << tinhTien();
        cout << endl;
        loai->display();
        cout << endl;
        mh->display();
        cout << endl;
        voMay->display();
    }
    float tinhTien()
    {
        return (loai->layGia() + mh->layGia() + voMay->layGia()) * 1.8;
    }
};
int main()
{
    int n;
    Phone **a;
    cin >> n;
    a = new Phone * [n];
    for (int i = 0; i < n; i++)
    {
        int k;
        cin >> k;
        if (k == 1) a[i] = new Venus();
        if (k == 2) a[i] = new Mars();
        if (k == 3) a[i] = new Jupiter();
        a[i]->input();
    }
    for (int i = 0; i < n; i++)
    {
        a[i]->display();
    }
    for (int i = 0; i < n; i++)
    {
        delete a[i];
    }
    delete a;
    return 0;
}