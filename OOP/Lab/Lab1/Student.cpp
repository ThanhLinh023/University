#include<iostream>
#include<string.h>
using namespace std;
class student
{
private:
    string name;
    float math;
    float lite;
public:
    void input()
    {
        getline(cin, name);
        cin >> math;
        cin >> lite;
        while (math < 0 || math > 10 || lite < 0 || lite > 10)
        {
            cin >> math;
            cin >> lite;
        }
    }
    float gpa()
    {
        return (math + lite) / 2;
    }
    void display()
    {
        cout << "Thong tin hoc sinh:\n";
        cout << "Ho ten: " << name;
        cout << "\nDiem toan: " << math;
        cout << "\nDiem van: " << lite;
        cout << "\nDiem trung binh: " << gpa();
    }
};
int main()
{
    student a;
    a.input();
    a.display();
    return 0;
}