#include <iostream>
#include <ctime>
#include <time.h>
#include <cstdlib>
#include <math.h>
using namespace std;
class Blood
{
protected:
    int type;
    bool Rh;
public:
    bool Rhesus[8];
    Blood() {}
    void setType(int a)
    {
        type = a;
    }
    void setRh(bool rh)
    {
        Rh = rh;
    }
    int getType() { return type; }
    bool getRh() { return Rh; }
    virtual bool checkFamily(Blood *dad, Blood *mom) {}
    int getIndexRh()
    {
        if (type == 1)
        {
            if (Rh == false)
            {
                return 1;
            }
            else
                return 0;
        }
        if (type == 2)
        {
            if (Rh == false)
            {
                return 3;
            }
            else
                return 2;
        }
        if (type == 3)
        {
            if (Rh == false)
            {
                return 5;
            }
            else
                return 4;
        }
        if (type == 4)
        {
            if (Rh == false)
            {
                return 7;
            }
            else
                return 6;
        }
    }
};
class A : public Blood
{
public:
    A() {}
    A(bool rh)
    {
        Rh = rh;
        if (Rh)
        {
            Rhesus[0] = true;
            Rhesus[1] = true;
            Rhesus[2] = false;
            Rhesus[3] = false;
            Rhesus[4] = false;
            Rhesus[5] = false;
            Rhesus[6] = true;
            Rhesus[7] = true;
        }
        else
        {
            Rhesus[0] = false;
            Rhesus[1] = true;
            Rhesus[2] = false;
            Rhesus[3] = false;
            Rhesus[4] = false;
            Rhesus[5] = false;
            Rhesus[6] = false;
            Rhesus[7] = true;
        }
    }
    bool checkFamily(Blood *dad, Blood *mom)
    {
        if (dad->getType() == 1)
            return true;
        if (dad->getType() == 2 && mom->getType() == 1 || dad->getType() == 2 && mom->getType() == 3)
            return true;
        if (dad->getType() == 3)
            return true;
        if (dad->getType() == 4 && mom->getType() == 1 || dad->getType() == 4 && mom->getType() == 3)
            return true;
        return false;
    }
};
class B : public Blood
{
public:
    B() {}
    B(bool rh)
    {
        Rh = rh;
        if (Rh)
        {
            Rhesus[0] = false;
            Rhesus[1] = false;
            Rhesus[2] = true;
            Rhesus[3] = true;
            Rhesus[4] = false;
            Rhesus[5] = false;
            Rhesus[6] = true;
            Rhesus[7] = true;
        }
        else
        {
            Rhesus[0] = false;
            Rhesus[1] = false;
            Rhesus[2] = false;
            Rhesus[3] = true;
            Rhesus[4] = false;
            Rhesus[5] = false;
            Rhesus[6] = false;
            Rhesus[7] = true;
        }
    }
    bool checkFamily(Blood *dad, Blood *mom)
    {
        if (dad->getType() == 1 && mom->getType() == 2 || dad->getType() == 1 && mom->getType() == 3)
            return true;
        if (dad->getType() == 2 || dad->getType() == 3)
            return true;
        if (dad->getType() == 4 && mom->getType() == 2 || dad->getType() == 4 && mom->getType() == 3)
            return true;
        return false;
    }
};
class AB : public Blood
{
public:
    AB() {}
    AB(bool rh)
    {
        Rh = rh;
        if (Rh)
        {
            Rhesus[0] = true;
            Rhesus[1] = true;
            Rhesus[2] = true;
            Rhesus[3] = true;
            Rhesus[4] = true;
            Rhesus[5] = true;
            Rhesus[6] = true;
            Rhesus[7] = true;
        }
        else
        {
            Rhesus[0] = false;
            Rhesus[1] = true;
            Rhesus[2] = false;
            Rhesus[3] = true;
            Rhesus[4] = false;
            Rhesus[5] = true;
            Rhesus[6] = false;
            Rhesus[7] = false;
        }
    }
    bool checkFamily(Blood *dad, Blood *mom)
    {
        if (dad->getType() == 1 && mom->getType() == 2 || dad->getType() == 1 && mom->getType() == 3)
            return true;
        if (dad->getType() == 2 && mom->getType() == 1 || dad->getType() == 2 && mom->getType() == 3)
            return true;
        if (dad->getType() == 3 && mom->getType() == 1 || dad->getType() == 3 && mom->getType() == 2 || dad->getType() == 3 && mom->getType() == 3)
            return true;
        return false;
    }
};
class O : public Blood
{
public:
    O() {}
    O(bool rh)
    {
        Rh = rh;
        if (Rh)
        {
            Rhesus[0] = false;
            Rhesus[1] = false;
            Rhesus[2] = false;
            Rhesus[3] = false;
            Rhesus[4] = false;
            Rhesus[5] = false;
            Rhesus[6] = true;
            Rhesus[7] = true;
        }
        else
        {
            Rhesus[0] = false;
            Rhesus[1] = false;
            Rhesus[2] = false;
            Rhesus[3] = false;
            Rhesus[4] = false;
            Rhesus[5] = false;
            Rhesus[6] = false;
            Rhesus[7] = true;
        }
    }
    bool checkFamily(Blood *dad, Blood *mom)
    {
        if (dad->getType() == 1 && mom->getType() == 1 || dad->getType() == 1 && mom->getType() == 2 || dad->getType() == 1 && mom->getType() == 4)
            return true;
        if (dad->getType() == 2 && mom->getType() == 1 || dad->getType() == 2 && mom->getType() == 2 || dad->getType() == 2 && mom->getType() == 4)
            return true;
        if (dad->getType() == 4 && mom->getType() == 1 || dad->getType() == 4 && mom->getType() == 2 || dad->getType() == 4 && mom->getType() == 4)
            return true;
        return false;
    }
};
int main()
{
    Blood **a;
    srand(time(0));
    cout << "Create list of people randomly.\n";
    cout << "Choose type of blood - 1.A - 2.B - 3.AB - 4.O\n";
    cout << "Choose type of rhesus - 1.Rh+ - 0. Rh-\n";
    int n;
    n = rand() % 25;
    a = new Blood *[n];
    int t, k;
    for (int i = 0; i < n; i++)
    {
        t = rand() % 4 + 1;
        k = rand() % 3;
        if (t == 1)
        {
            a[i] = new A(k);
            a[i]->setType(1);
        }
        if (t == 2)
        {
            a[i] = new B(k);
            a[i]->setType(2);
        }
        if (t == 3)
        {
            a[i] = new AB(k);
            a[i]->setType(3);
        }
        if (t == 4)
        {
            a[i] = new O(k);
            a[i]->setType(4);
        }
    }
    cout << "----------------------Information------------------------\n";
    cout << "---------------------------------------------------------\n";
    for (int i = 0; i < n; i++)
    {
        cout << "|\tPeople " << i << "\t|";
        if (a[i]->getType() == 1 && a[i]->getRh() == true)
            cout << "\tBlood: A - Rh+\t\t|\n";
        if (a[i]->getType() == 1 && a[i]->getRh() == false)
            cout << "\tBlood: A - Rh-\t\t|\n";
        if (a[i]->getType() == 2 && a[i]->getRh() == true)
            cout << "\tBlood: B - Rh+\t\t|\n";
        if (a[i]->getType() == 2 && a[i]->getRh() == false)
            cout << "\tBlood: B - Rh-\t\t|\n";
        if (a[i]->getType() == 3 && a[i]->getRh() == true)
            cout << "\tBlood: AB - Rh+\t\t|\n";
        if (a[i]->getType() == 3 && a[i]->getRh() == false)
            cout << "\tBlood: AB - Rh-\t\t|\n";
        if (a[i]->getType() == 4 && a[i]->getRh() == true)
            cout << "\tBlood: O - Rh+\t\t|\n";
        if (a[i]->getType() == 4 && a[i]->getRh() == false)
            cout << "\tBlood: O - Rh-\t\t|\n";
        cout << "---------------------------------------------------------\n";
    }
    int t1, t2, t3;
    t1 = rand() % (n - 3) + 1;
    t2 = t1 + 2;
    t3 = abs(t1 - t2) / 2;
    cout << "- Dad's number: " << t1;
    cout << "\n- Mom's number: " << t2;
    cout << "\n- Child's number: " << t3;
    cout << endl;
    if (a[t3]->checkFamily(a[t1], a[t2]))
    {
        cout << "-> They are family.\n";
    }
    else
        cout << "Oops, ask the mom and the neighbor!!!!\n";
    int p = (t1 + t2 + t3) / 3;
    cout << "Patient's number: " << p;
    cout << "\n---------------------------------------------------------\n";
    for (int i = 0; i < n; i++)
    {
        if (i != p)
        {
            if (a[p]->Rhesus[a[i]->getIndexRh()])
            {
                cout << "|\tPeople " << i << "\t|";
                if (a[i]->getType() == 1 && a[i]->getRh() == true)
                    cout << "\tBlood: A - Rh+\t\t|\n";
                if (a[i]->getType() == 1 && a[i]->getRh() == false)
                    cout << "\tBlood: A - Rh-\t\t|\n";
                if (a[i]->getType() == 2 && a[i]->getRh() == true)
                    cout << "\tBlood: B - Rh+\t\t|\n";
                if (a[i]->getType() == 2 && a[i]->getRh() == false)
                    cout << "\tBlood: B - Rh-\t\t|\n";
                if (a[i]->getType() == 3 && a[i]->getRh() == true)
                    cout << "\tBlood: AB - Rh+\t\t|\n";
                if (a[i]->getType() == 3 && a[i]->getRh() == false)
                    cout << "\tBlood: AB - Rh-\t\t|\n";
                if (a[i]->getType() == 4 && a[i]->getRh() == true)
                    cout << "\tBlood: O - Rh+\t\t|\n";
                if (a[i]->getType() == 4 && a[i]->getRh() == false)
                    cout << "\tBlood: O - Rh-\t\t|\n";
                cout << "---------------------------------------------------------\n";
            }
        }
    }
    cout << "Above people can give blood to the patient.";
    return 0;
}
