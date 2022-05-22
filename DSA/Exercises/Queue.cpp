#include <iostream>
#include <string>
using namespace std;
struct CNode
{
    char info;
    CNode* next;
};
struct CList
{
    CNode* head;
    CNode* tail;
    void emptyCList(CList& l)
    {
        l.head = l.tail = NULL;
    }
    CNode* createCNode(char x)
    {
        CNode* p = new CNode;
        if (p == NULL)
            return NULL;
        p->info = x;
        p->next = NULL;
        return p;
    }
    void enQueue(CList& l, CNode* x)
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
    void deQueue(CList& l)
    {
        CNode* p;
        if (l.head != NULL)
        {
            p = l.head;
            l.head = l.head->next;
            delete p;
            if (l.head == NULL)
                l.tail = NULL;
        }
    }
    bool isEmpty(CList& l)
    {
        if (l.head == NULL)
            return true;
        else
            return false;
    }
    void Palindrome(CList& L, string& x)
    {
        int i = 0;
        CNode* p;
        while (i < x.length())
        {
            p = createCNode(x[i]);
            enQueue(L, p);
            i++;
        }
        i = 0;
        while (i < x.length())
        {
            deQueue(L);
            i++;
        }
        if (L.head == L.tail)
            cout << "Palindrome" << endl;
        else
            cout << "Not palindrome" << endl;
    }
};

struct Person
{
    string name;
    int sex;
};
struct StNode
{
    Person info;
    StNode* next;
};
struct StList
{
    StNode* head;
    StNode* tail;
    void emptyList(StList& l)
    {
        l.head = l.tail = NULL;
    }
    StNode* createNode(Person& x)
    {
        StNode* p = new StNode;
        cin.ignore();
        cout << "Enter name: ";
        getline(cin, x.name);
        cout << "Enter sex, male(0), female(1): ";
        cin >> x.sex;
        p->info = x;
        p->next = NULL;
        return p;
    }
    void createQueue(StList& l, int& n)
    {
        for (int i = 0; i < n; i++)
        {
            Person x;
            StNode* p = createNode(x);
            enQueue(l, p);
        }
    }
    void enQueue(StList& l, StNode* x)
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
    void deQueue(StList& l)
    {
        StNode* p;
        if (l.head != NULL)
        {
            p = l.head;
            l.head = l.head->next;
            delete p;
            if (l.head == NULL)
                l.tail = NULL;
        }
    }
    bool isEmpty(StList& l)
    {
        if (l.head == NULL)
            return true;
        else
            return false;
    }
    void Demerging(StList& l)
    {
        StList nam, nu;
        nam.emptyList(nam);
        nu.emptyList(nu);
        StNode* p = l.head;
        while (p)
        {
            if (p->info.sex == 1)
            {
                nu.enQueue(nu, p);
            }
            else if (p->info.sex == 0)
            {
                nam.enQueue(nam, p);
            }
            p = p->next;
        }
        cout << "Female list's information:";
        nu.printQueue(nu);
        cout << "\n-----------------";
        cout << "\nMale list's information:";
        nam.printQueue(nam);
        cout << "\n-----------------";
    }
    void printQueue(StList l)
    {
        StNode* i = l.head;
        if (i == NULL)
            return;
        while (i != l.tail->next)
        {
            cout << "\n-----------------";
            cout << "\nName : " << i->info.name;
            cout << "\nSex : ";
            if (i->info.sex == 0) {
                cout << "Male";
            }
            else if (i->info.sex == 1) {
                cout << "Female";
            }
            i = i->next;
        }
    }
};

int main()
{
    CList l;
    StList p;
    p.emptyList(p);
    string s;
    int n;
    l.emptyCList(l);
    cout << "Enter string : ";
    cin.ignore();
    getline(cin, s);
    l.Palindrome(l, s);
    cout << "Number of people : ";
    cin >> n;
    p.createQueue(p, n);
    p.Demerging(p);
    return 0;
}