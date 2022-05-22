#include<iostream>
#include<string.h>
using namespace std;
struct Employee
{
    char ID[50];
    char name[100];
    int year;
    int numOfPro;
};

struct Node
{
    Employee info;
    Node *next;
    Node *pre;
};

struct List
{
    Node *head;
    Node *tail;
};

Node *createNode(Employee x)
{
    Node *p = new Node;
    cin >> x.ID;
    cin >> x.name;
    cin >> x.year;
    cin >> x.numOfPro;
    p->info = x;
    p->next = NULL;
    p->pre = NULL;
    return p;
}

void emptyList(List &l)
{
    l.head = l.tail = NULL;
}

void addHead(List &l, Node *x)
{
    if (l.head == NULL)
    {
        l.head = l.tail = x;
    }
    else
    {
        x->next = l.head;
        l.head->pre = x;
        l.head = x;
    }
}

void addTail(List &l, Node *x)
{
    if (l.head == NULL)
    {
        l.head = l.tail = x;
    }
    else
    {
        l.tail->next = x;
        x->pre = l.tail;
        l.tail = x;
    }
}

void createList(List &l, int &n)
{
    Employee x;
    for (int i = 0; i < n; i++)
    {
        Node *p = createNode(x);
        addTail(l, p);
    }
}

void printList(List &l)
{
    for (Node *i = l.head; i != NULL; i = i->next)
    {
        cout << "\n------Information------\n";
        cout << "Employee's ID : " << i->info.ID;
        cout << "\nEmployee's name : " << i->info.name;
        cout << "\nYear of birth : " << i->info.year;
        cout << "\nNumber of products : " << i->info.numOfPro;
    }
}

void maxPro(List &l)
{
    Node *p = new Node;
    int max = l.head->info.numOfPro;
    for (Node *i = l.head; i != NULL; i = i->next)
    {
        if (i->info.numOfPro > max)
        {
            max = i->info.numOfPro;
            p = i;
        }
    }
    cout << "\n-------------------------------------------";
    cout << "\nInformation of employee has most number of products : ";
    cout << "\nEmployee's ID : " << p->info.ID;
    cout << "\nEmployee's name : " << p->info.name;
    cout << "\nYear of birth : " << p->info.year;
    cout << "\nNumber of products : " << p->info.numOfPro;
    cout << "\n-------------------------------------------";
}

void analisByAge(List &l)
{
    int d0(0), d1(0), d2(0);
    for (Node *i = l.head; i != NULL; i = i->next)
    {
        int age = 2022 - i->info.year;
        if (age > 0 && age < 30) d0++;
        else if (age >= 30 && age <= 50) d1++;
        else d2++;
    }
    cout << "\nNumber of employees under 30 years old is " << d0;
    cout << "\nNumber of employees between aged 30 and 50 is " << d1;
    cout << "\nNumber of employees greater than aged 50 is " << d2;
    cout << "\n-------------------------------------------";
}

void sortByPro(List &l)
{
    for (Node *i = l.head; i != NULL; i = i->next)
    {
        for (Node *j = i->next; j != NULL; j = j->next)
        {
            if (i->info.numOfPro < j->info.numOfPro)
            {
                int t = i->info.numOfPro;
                i->info.numOfPro = j->info.numOfPro;
                j->info.numOfPro = t;
            }
        }
    }
    cout << "\nList after sorting by number of products : ";
    printList(l);
}

int main()
{
    List l;
    int n;
    emptyList(l);
    cout << "Number of employees : ";
    cin >> n;
    createList(l, n);
    printList(l);
    maxPro(l);
    analisByAge(l);
    sortByPro(l);
    return 0;
}