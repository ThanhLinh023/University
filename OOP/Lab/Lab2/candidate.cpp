#include<iostream>
#include<string>
using namespace std;
class Candidate
{
private:
    string id;
    string name;
    string dob;
    int math;
    int lite;
    int english;
public:
    Candidate() {}
    void input()
    {
        cin >> id;
        cin.ignore();
        getline(cin, name);
        cin >> dob;
        cin >> math;
        cin >> lite;
        cin >> english;
    }
    void display()
    {
        cout << "Thong tin hoc sinh:" << endl;
        cout << "Ma: " << id << endl;
        cout << "Ho ten: " << name << endl;
        cout << "Ngay sinh: " << dob << endl;
        cout << "Diem toan: " << math << endl;
        cout << "Diem van: " << lite << endl;
        cout << "Diem anh: " << english << endl;
    }
    int sum()
    {
        return math + lite + english;
    }
};
int main()
{
    Candidate *test;
    int n, d(0);
    cin >> n;
    test = new Candidate[n];
    for (int i = 0; i < n; i++)
    {
        test[i].input();
    }
    for (int i = 0; i < n; i++)
    {
        if (test[i].sum() > 15)
        {
            cout << "-" << endl;
            cout << "STT " << i + 1 << ":" << endl;
            test[i].display();
        }
        else
        {
            d++;
        }
    }
    if (d == n)
    {
        cout << "Khong co thi sinh co tong diem lon hon 15" << endl;
    }
    delete test;
    return 0;
}