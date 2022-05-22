#include<iostream>
#include<string>
#include<typeinfo>
using namespace std;
class Student
{
private:
    string id;
    string name;
    string address;
    int tc;
    float gpa;
public:
    Student() {}
    virtual void input()
    {
        cout << "Enter student's ID: ";
        cin >> id;
        cin.ignore();
        cout << "Enter student's name: ";
        getline(cin, name);
        cout << "Enter student's address: ";
        getline(cin, address);
        cout << "Enter student's total academic credits: ";
        cin >> tc;
        cout << "Enter student's GPA: ";
        cin >> gpa;
    }
    virtual void display()
    {
        cout << "Student's ID: " << id;
        cout << "\nStudent's name: " << name;
        cout << "\nStudent's address: " << address;
        cout << "\nStudent's total academic credits: " << tc;
        cout << "\nStudent's GPA: " << gpa;
    }
    int getAcaCredit() {return tc;}
    float getGPA() {return gpa;}
    virtual bool canGraduate() {}
};
class College : public Student
{
private:
    float graPoint;
public:
    College() {}
    void input()
    {
        Student::input();
        cout << "Enter student's graduated point: ";
        cin >> graPoint;
    }
    void diplay()
    {
        cout << "Type of training education: College\n";
        Student::display();
        cout << "\nStudent's graduated point: " << graPoint;
    }
    float getGraPoint()
    {
        return graPoint;
    }
    bool canGraduate()
    {
        if (getAcaCredit() >= 120 && getGPA() >= 5.0 && getGraPoint() >= 5.0) return true;
        return false;
    }
};
class Uni : public Student
{
private:
    string nameOfEssay;
    float pointOfEssay;
public:
    Uni() {}
    void input()
    {
        Student::input();
        cout << "Enter student's name of graduated essay: ";
        cin.ignore();
        getline(cin, nameOfEssay);
        cout << "Enter student's point of graduated essay: ";
        cin >> pointOfEssay;
    }
    void display()
    {
        cout << "Type of training education: University\n";
        Student::display();
        cout << "\nStudent's graduated essay name: " << nameOfEssay;
        cout << "\nStudent's graduated essay point: " << pointOfEssay;
    }
    float getPointOfEssay()
    {
        return pointOfEssay;
    }
    bool canGraduate()
    {
        if (getAcaCredit() >= 170 && getGPA() >= 5.0 && getPointOfEssay() >= 5.0) return true;
        return false;
    }
};
int main()
{
    int n;
    cout << "Enter number of student: ";
    cin >> n;
    Student **a;
    a = new Student*[n];
    for (int i = 0; i < n; i++)
    {
        cout << "-------------------------------\n";
        cout << "Enter information of student " << i + 1 << endl;
        string s;
        cout << "Enter type of training education: ";
        cin >> s;
        if (s == "College")
        {
            a[i] = new College();
            a[i]->input();
        }
        if (s == "University")
        {
            a[i] = new Uni();
            a[i]->input();
        }
    }
    int d(0);
    for (int i = 0; i < n; i++)
    {
        if (a[i]->canGraduate()) d++;
    }
    cout << "-------------------------------\n";
    cout << "Number of student can be graduated: " << d;
    int max1 = -999999;
    int max2 = -999999;
    Student *b, *c;
    for (int i = 0; i < n; i++)
    {
        if (typeid(*a[i]) == typeid(College))
        {
            if (a[i]->getGPA() > max2)
            {   
                max2 = a[i]->getGPA();
                b = a[i];
            }
        }
        if (typeid(*a[i]) == typeid(Uni))
        {
            if (a[i]->getGPA() > max1)
            {
                max1 = a[i]->getGPA();
                c = a[i];
            }
        }
    }
    cout << "\n------------------------------\n";
    cout << "\tInformation of university student has highest GPA\n";
    c->display();
    cout << "\n------------------------------\n";
    cout << "\tInformation of college student has highest GPA\n";
    b->display();
    cout << "\n------------------------------\n";
    for (int i = 0; i < n; i++)
    {
        delete a[i];
    }
    delete a;
    return 0;
}