#include<iostream>
using namespace std;
class Employee
{
public:
    char id[8];
    char name[20];
    char depart[20];
    int basicIncome;
    int bonus;
    void input()
    {
        cout << "Id : ";
        cin >> id;
        cout << "Name : ";
        cin >> name;
        cout << "Department : ";
        cin >> depart;
        cout << "Basic income : ";
        cin >> basicIncome;
        cout << "Bonus : ";
        cin >> bonus;
    }
    void display()
    {
        cout << "Id : " << id << endl;
        cout << "Name : " << name << endl;
        cout << "Department : " << depart << endl;
        cout << "Basic income : " << basicIncome << endl;
        cout << "Bonus : " << bonus << endl;
        cout << "Salary : " << basicIncome +  bonus << endl;
        cout << "-----------------------------------------" << endl;
    }
};
void cauA(Employee comp[], int &n)
{
    for (int i = 0; i < n; i++)
    {
        cout << comp[i].id << " " << comp[i].name << " " << comp[i].basicIncome + comp[i].bonus << endl;
    }
}

void cauB(Employee comp[], int n)
{
    for (int i = 0; i < n; i++)
    {
        if (comp[i].basicIncome < 5000000)
        {
            cout << comp[i].id << " " << comp[i].name;
        }
    }
}

int cauC(Employee comp[], int n)
{
    int count(0);
    for (int i = 0; i < n; i++)
    {
        if (comp[i].bonus >= 1200000)
        {
            count++;
        }
    }
    return count;
}

void cauD(Employee comp[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << "Number : " << i << endl;
        cout << "Id : " << comp[i].id << endl;
        cout << "Name : " << comp[i].name << endl;
        cout << "Department : " << comp[i].depart << endl;
        cout << "Basic income : " << comp[i].basicIncome << endl;
        cout << "Bonus : " << comp[i].bonus << endl;
        cout << "Salary : " << comp[i].basicIncome + comp[i].bonus << endl;
        cout << "-----------------------------------------" << endl;
    }
}
int main()
{
    int n;
    cout << "Number of employees : ";
    cin >> n;
    Employee e[100];
    for(int i = 0; i < n; i++)
    {
        e[i].input();
    }
    cauA(e, n);
    cout << endl;
    cauB(e, n);
    cout << endl;
    cout << cauC(e, n);
    cout << endl;
    cauD(e, n);
    return 0;
}