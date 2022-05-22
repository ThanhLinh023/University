//STT: 25 - Vương Thanh Linh - 21521082 - IT003.M23.1
//Buổi 2 - Bài 2
#include<iostream>
#include<string>
#include<time.h>
#include<ctime>
#include<cstdlib>
using namespace std;
//Khai báo cấu trúc sinh viên
struct Student
{
    int ID;
    string name;
    float gpa;
};
//Khai báo cấu trúc node
struct Node
{
    Student info;
    Node *next;
};
//Khai bao cấu trúc list
struct List
{
    Node *head;
    Node *tail;
};
//Khởi tạo node
Node *createNode(Student x)
{
    Node *p = new Node;
    cout << "Enter ID: ";
    cin >> x.ID;
    cin.ignore();
    cout << "Enter name: ";
    getline(cin, x.name);
    cout << "Enter GPA: ";
    cin >> x.gpa;
    p->info = x;
    p->next = NULL;
    return p;
}
//Tạo danh sách rỗng
void emptyList(List &l)
{
    l.head = l.tail = NULL;
}
//Câu 4
void addHead(List &l, Node *x)
{
    if (l.head == NULL)
    {
        l.head = l.tail = x;
    }
    else
    {
        x->next = l.head;
        l.head = x;
    }
}
//Câu 5
void addTail(List &l, Node *x)
{
    if (l.head == NULL)
    {
        l.head = l.tail = x;
    }
    else
    {
        l.tail->next = x;
        l.tail = x;
    }
}
//Câu 6
void createList(List &l, int &n)
{
    Student x;
    for (int i = 0; i < n; i++)
    {
        Node *p = createNode(x);
        addTail(l, p);
    }
}
//Câu 7
void autoName(string &s)
{
    string first[] = {"Nguyen", "Tran", "Le", "Pham"};
    string mid [] = {"Van", "Thi", "Hoang"};
    string name[] = {"Anh", "An", "Tien", "Hoang", "Manh", "Minh"};
    s = first[rand() % 4] + " " + mid[rand() % 3] + " " + name[rand() % 6];
}
Node *autoInfo(Student x)
{
    Node *p = new Node;
    x.ID = rand() % 901;
    autoName(x.name);
    x.gpa = (rand() % 10) + ((rand() % 11) * 1.0) / 10;
    p->info = x;
    p->next = NULL;
    return p;
}
void autoCreatList(List &l, int &n)
{
    Student x;
    for (int i = 0; i < n; i++)
    {
        addTail(l, autoInfo(x));
    }
}
//Câu 8
void printList(List &l)
{
    for (Node *i = l.head; i != NULL; i = i->next)
    {
        cout << "\n--------Information--------";
        cout << "\nStudent's ID : " << i->info.ID;
        cout << "\nStudent's Name : " << i->info.name;
        cout << "\nStudent's GPA : " << i->info.gpa;
    }
}
//Câu 9
void findByID(List &l, int a)
{
    for (Node *i = l.head; i != NULL; i = i->next)
    {
        if (i->info.ID == a)
        {
            cout << "\n--------Information--------";
            cout << "\nStudent's ID : " << i->info.ID;
            cout << "\nStudent's Name : " << i->info.name;
            cout << "\nStudent's GPA : " << i->info.gpa;
        }
    }
}
//Câu 10
void findByName(List &l, string s)
{
    for (Node *i = l.head; i != NULL; i = i->next)
    {
        if (i->info.name == s)
        {
            cout << "\n--------Information--------";
            cout << "\nStudent's ID : " << i->info.ID;
            cout << "\nStudent's Name : " << i->info.name;
            cout << "\nStudent's GPA : " << i->info.gpa;
        }
    }
}
//Câu 11
void findByGPA(List &l, float a)
{
    for (Node *i = l.head; i != NULL; i = i->next)
    {
        if (i->info.gpa == a)
        {
            cout << "\n--------Information--------";
            cout << "\nStudent's ID : " << i->info.ID;
            cout << "\nStudent's Name : " << i->info.name;
            cout << "\nStudent's GPA : " << i->info.gpa;
        }
    }
}
//Câu 12
void findMaxGPA(List &l)
{
    Node *p;
    float max = l.head->info.gpa;
    for (Node *i = l.head; i != NULL; i = i->next)
    {
        if (i->info.gpa > max)
        {
            max = i->info.gpa;
            p = i;
        }
    }
    cout << "\n--------Information--------";
    cout << "\nStudent's ID : " << p->info.ID;
    cout << "\nStudent's Name : " << p->info.name;
    cout << "\nStudent's GPA : " << p->info.gpa;
}
//Câu 13
void findMinGPA(List &l)
{
    Node *p;
    float min = l.head->info.gpa;
    for (Node *i = l.head; i != NULL; i = i->next)
    {
        if (i->info.gpa < min)
        {
            min = i->info.gpa;
            p = i;
        }
    }
    cout << "\n--------Information--------";
    cout << "\nStudent's ID : " << p->info.ID;
    cout << "\nStudent's Name : " << p->info.name;
    cout << "\nStudent's GPA : " << p->info.gpa;
}
//Câu 15
void deleteID(List &l, int a)
{
    Node *p = l.head;
    Node *q = l.head;
    while (p != NULL)
    {
        if (p->info.ID == a)
        {
            if (p == l.head)
            {
                p = l.head;
                l.head = p->next;
                delete p;
            }
            q->next = p->next;
            delete p;
        }
        q = p;
        p = p->next;
    }
}
//Câu 14
void print10MaxGPA(List &l)
{
    for (Node *i = l.head; i != NULL; i = i->next)
    {
        for (Node *j = i->next; j != NULL; j = j->next)
        {
            if (i->info.gpa < j->info.gpa)
            {
                float t = i->info.gpa;
                i->info.gpa = j->info.gpa;
                j->info.gpa = t;
            }
        }
    }
    int d(0);
    for (Node *i = l.head; i != NULL; i = i->next)
    {
        cout << "\n--------Information--------";
        cout << "\nStudent's ID : " << i->info.ID;
        cout << "\nStudent's Name : " << i->info.name;
        cout << "\nStudent's GPA : " << i->info.gpa;
        d++;
        if (d == 10) break;
    }
}
int main()
{
    List l;
    int n, menu;
    emptyList(l);
    cout << "\n--------Options--------";
    cout << "\n1. Create list normally";
    cout << "\n2. Create list automatically";
    cout << "\n3. Add student's information to head and tail";
    cout << "\n4. Print list of students' information";
    cout << "\n5. Find student's information by ID";
    cout << "\n6. Find student's information by name";
    cout << "\n7. Find student's information by gpa";
    cout << "\n8. Find student has maximum gpa";
    cout << "\n9. Find student has minimum gpa";
    cout << "\n10. Find 10 student have maximum gpa";
    cout << "\n11. Delete student by ID";
    int t = 15;
    while (t--)
    {
        cout << "\nChoose one option : ";
        cin >> menu;
        if (menu > 0 && menu <= 11)
        {
            switch(menu)
            {
                case 1:
                {
                    cout << "Number of students : ";
                    cin >> n;
                    createList(l, n);
                    break;
                }
                case 2:
                {
                    List k;
                    emptyList(k);
                    int a;
                    cout << "Number of students : ";
                    cin >> a;
                    autoCreatList(k, a);
                    printList(k);
                    break;
                }
                case 3:
                {
                    cout << "Information of student to add to head and tail : ";
                    Student a, b;
                    addHead(l, createNode(a));
                    addTail(l, createNode(b));
                    cout << "After add : ";
                    printList(l);
                    break;
                }
                case 4:
                {
                    printList(l);
                    break;
                }
                case 5:
                {
                    int a;
                    cout << "Insert student's ID : ";
                    cin >> a;
                    findByID(l, a); 
                    break;
                }
                case 6:
                {
                    string s;
                    cout << "Insert student's name : ";
                    cin >> s;
                    findByName(l, s);
                    break;
                }
                case 7:
                {
                    float a;
                    cout << "Insert a GPA : ";
                    cin >> a;
                    findByGPA(l, a);
                    break;
                }
                case 8:
                {
                    findMaxGPA(l);
                    break;
                }
                case 9:
                {
                    findMinGPA(l);
                    break;
                }
                case 10:
                {
                    print10MaxGPA(l);
                    break;
                }
                case 11:
                {
                    int a;
                    cout << "Insert ID want to delete : ";
                    cin >> a;
                    deleteID(l, a);
                    cout << "After deleting student has ID " << a << " : ";
                    printList(l);
                    break;
                }
            }
        }
        else cout << "\nPlease, choose again";
    }
    return 0;
}