#include<iostream>
#include<ctime>
#include<cstdlib>
using namespace std;
int a, b, c;
class Robot
{
public:
    Robot() {}
    virtual int totalEnergy() {}
    virtual void display() {}
};
class Pedion : public Robot
{
private:
    int f;
public:
    Pedion() {}
    int getF()
    {
        srand(time(0));
        f = 1 + rand() % 5;
        return f;
    }
    int totalEnergy()
    {
        int t;
        t = 20 * 10 + (getF() + 1) * 10 / 2;
        return t * a;
    }
    void display()
    {
        cout << "\nType: Pedion";
        cout << "\nM: 20";
        cout << "\nTotal energy used: " << totalEnergy();
        cout << endl;
    }
};
class Zattacker : public Robot
{
private:
    int p;
public:
    Zattacker() {}
    int getP()
    {
        srand(time(0));
        p = 20 + rand() % 11;
        return p;
    }
    int totalEnergy()
    {
        int t;
        t = 50 * 10 + getP() * getP() * 10;
        return t * b;
    }
    void display()
    {
        cout << "\nType: Zattacker";
        cout << "\nM: 50";
        cout << "\nTotal energy used: " << totalEnergy();
        cout << endl;
    }
};
class Carrier : public Robot
{
private:
    int e;
public:
    Carrier() {}
    int getE()
    {
        srand(time(0));
        e = 50 + rand() % 51;
        return e;
    }
    int totalEnergy()
    {
        int t;
        t = 30 * 10 + 4 * getE() * 10;
        return t * c;
    }
    void display()
    {
        cout << "\nType: Carrier";
        cout << "\nM: 30";
        cout << "\nTotal energy used: " << totalEnergy();
        cout << endl;
    }
};

int main()
{
    Robot **ro, *iq;
    cout << "Enter number of Pedion: ";
    cin >> a;
    cout << "Enter number of Zattacker: ";
    cin >> b;
    cout << "Enter number of Carrier: ";
    cin >> c;
    ro = new Robot*[3];
    ro[0] = new Pedion();
    ro[1] = new Zattacker();
    ro[2] = new Carrier();
    for (int i = 0; i < 3; i++)
    {
        cout << "----------------------\n";
        cout << "\tInformation";
        ro[i]->display();
    }
    int max = -9999;
    for (int i = 0; i < 3; i++)
    {
        if (ro[i]->totalEnergy() > max)
        {
            max = ro[i]->totalEnergy();
            iq = ro[i];
        }
    }
    cout << "----------------------\n";
    cout << "\tInformation of most-used energy robot";
    iq->display();
    cout << "----------------------\n";
    int tong(0);
    for (int i = 0; i < 3; i++)
    {
        tong += ro[i]->totalEnergy();
    }
    cout << "Total energy used of all robot: " << tong;
    for (int i = 0; i < 3; i++)
    {
        delete ro[i];
    }
    delete ro;
    return 0;
}