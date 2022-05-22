#include<iostream>
#include<string.h>
using namespace std;
class Candidate
{
private:
    int id;
    string name;
    int dd;
    int mm;
    int yy;
    float math;
    float lite;
    float english;
public:
    Candidate() {}
    void input()
    {
        cin >> id >> name >> dd >> mm >> yy >> math >> lite >> english;
    }
    void display()
    {
        cout << "\n---------------------------";
        cout << "\nID : " << id;
        cout << "\nName : " << name;
        cout << "\nDate of birth : " << dd << "/" << mm << "/" << yy;
        cout << "\nPoint of math : " << math;
        cout << "\nPoint of literature : " << lite;
        cout << "\nPoint of english : " << english;
    }
    float sum()
    {
        return math + lite + english;
    }
};
class TestCandidate
{
private:
    Candidate s[100];
    int numOfCandidate;
public:
    TestCandidate() {}
    void input()
    {
        cout << "Number of candidates : ";
        cin >> numOfCandidate;
        for (int i = 0; i < numOfCandidate; i++)
        {
            s[i].input();
        }
    }
    void test()
    {
        cout << "Information of candidates have total point greater than 15 : ";
        for (int i = 0; i < numOfCandidate; i++)
        {
            if (s[i].sum() > 15)
            {
                s[i].display();
            }
        }
    }
};
int main()
{
    TestCandidate c;
    c.input();
    c.test();
    return 0;
}