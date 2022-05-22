#include<iostream>
using namespace std;
class Student
{
public:
    char Name[20];
    float math;
    float lite;
    float gpa()
    {
        return (math + lite) / 2;
    }
    void input()
    {
        cout << "Enter the name of the student : ";
        cin >> Name;
        cout << "Enter the grades of the student in math : ";
        cin >> math;
        cout << "Enter the grades of the student in lite : ";
        cin >> lite;
    }
    void display()
    {
        cout << "GPA of " << Name << " is " << gpa();
    }
};
int main()
{
    Student a;
    a.input();
    a.display();
    return 0;
}