#include <iostream>
#include <string.h>
#include<string>
using namespace std;

struct fNode
{
    float info;
    fNode *next;
};
struct fList
{
    fNode *head;
    fNode *tail;
    void emptyList(fList &St)
    {
        St.head = St.tail = NULL;
    }
    fNode *createNode(float x)
    {
        fNode *p = new fNode;
        if (p == NULL)
            return NULL;
        p->info = x;
        p->next = NULL;
        return p;
    }
    void push(fList &St, fNode *x)
    {
        if (St.head == NULL)
        {
            St.head = St.tail = x;
        }
        else
        {
            x->next = St.head;
            St.head = x;
        }
    }
    void pop(fList &St)
    {
        fNode *p;
        if (St.head != NULL)
        {
            p = St.head;
            St.head = St.head->next;
            delete p;
            if (St.head == NULL)
                St.tail = NULL;
        }
    }
    bool isEmpty(fList &St)
    {
        if (St.head = NULL)
            return true;
        else
            return false;
    }
    fNode *top(fList &St)
    {
        if (St.head != NULL)
            return St.head;
        else
            return NULL;
    }
    void reverseFloatArr(fList &St, int &n, float a[])
    {
        for (int i = 0; i < n; i++)
        {
            push(St, createNode(a[i]));
        }
        printStack(St);
    }
    void printStack(fList &l)
    {
        for (fNode *i = l.head; i != NULL; i = i->next)
        {
            cout << i->info << " ";
        }
    }
};

struct sNode
{
    string info;
    sNode *next;
};
struct sList
{
    sNode *head;
    sNode *tail;
    void emptyList(sList &St)
    {
        St.head = St.tail = NULL;
    }
    sNode *createNode(string x)
    {
        sNode *p = new sNode;
        if (p == NULL) return NULL;
        p->info = x;
        p->next = NULL;
        return p;
    }
    void push(sList &St, sNode *x)
    {
        if (St.head == NULL)
        {
            St.head = St.tail = x;
        }
        else
        {
            x->next = St.head;
            St.head = x;
        }
    }
    void pop(sList &St)
    {
        sNode *p;
        if (St.head != NULL)
        {
            p = St.head;
            St.head = St.head->next;
            delete p;
            if (St.head == NULL) St.tail == NULL;
        }
    }
    bool isEmpty(sList &St)
    {
        if (St.head == NULL) return true;
        return false;
    }
    sNode *top(sList &St)
    {
        if (St.head != NULL) return St.head;
        else return NULL;
    }
    void printStack(sList &St)
    {
        for (sNode *i = St.head; i != NULL; i = i->next)
        {
            cout << i->info << " ";
        }
    }
    void reverseWord(sList &St, string &s)
    {
        string t = "";
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == ' ')
            {
                push(St, createNode(t));
                t = "";
            }
            else
            {
                t += s[i];
            }
        }
        push(St, createNode(t));
        printStack(St);
    }   
};

struct iNode
{
    int info;
    iNode *next;
};
struct iList
{
    iNode *head;
    iNode *tail;
    void emptyList(iList &l)
    {
        l.head = l.tail = NULL;
    }
    iNode *createNode(int x)
    {
        iNode *p = new iNode;
        if (p == NULL)
            return NULL;
        p->info = x;
        p->next = NULL;
        return p;
    }
    void push(iList &l, iNode *x)
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
    void pop(iList &l)
    {
        iNode *p;
        if (l.head != NULL)
        {
            p = l.head;
            l.head = l.head->next;
            delete p;
            if (l.head == NULL)
                l.tail = NULL;
        }
    }
    bool isEmpty(iList &l)
    {
        if (l.head = NULL)
            return true;
        else
            return false;
    }
    iNode *top(iList &l)
    {
        if (l.head != NULL)
            return l.head;
        else
            return NULL;
    }
    void printStack(iList &St)
    {
        for (iNode *i = St.head; i != NULL; i = i->next)
        {
            cout << i->info;
        }
    }
    void decToBin(iList &St, int &n)
    {
        while (n != 0)
        {
            push(St, createNode(n % 2));
            n /= 2;
        }
        printStack(St);
    }
};

struct cNode
{
    char info;
    cNode *next;
};
struct cList
{
    cNode *head;
    cNode *tail;
    void emptyList(cList &St)
    {
        St.head = St.tail = NULL;
    }
    cNode *createNode(char x)
    {
        cNode *p = new cNode;
        if (p == NULL) return NULL;
        p->info = x;
        p->next = NULL;
        return p;
    }
    void push(cList &St, cNode *x)
    {
        if (St.head == NULL)
        {
            St.head = St.tail = x;
        }
        else
        {
            x->next = St.head;
            St.head = x;
        }
    }
    void pop(cList &St)
    {
        cNode *p;
        if (St.head != NULL)
        {
            p = St.head;
            St.head = St.head->next;
            delete p;
            if (St.head == NULL) St.tail = NULL;
        }
    }
    bool isEmpty(cList &St)
    {
        if (St.head == NULL) return true;
        else return false;
    }
    cNode *top(cList &St)
    {
        if (St.head != NULL) return St.head;
        else return NULL;
    }
    void BracketMatching(cList &St, string &x)
    {
        for (int i = 0; i < x.size(); i++)
        {
            if (x[i] == '(')
            {
                push(St, createNode(x[i]));
            }
            else if (x[i] == ')')
            {
                pop(St);
            }
        }
        if (isEmpty(St) == false)
        {
            cout << "\nNot Matching";
        }
        else
        {
            cout << "\nMatching";
        }
    }
    void BalancingAct(cList &St, string x)
    {
        for (int i = 0; i < x.size(); i++)
        {
            if (x[i] == '(' || x[i] == '{' || x[i] == '[')
            {
                push(St, createNode(x[i]));
            }
            else if (x[i] == ')' || x[i] == '}' || x[i] == ']')
            {
                pop(St);
            }
        }
        if (isEmpty(St) == false)
        {
            cout << "\nNot Balancing";
        }
        else
        {
            cout << "\nBalancing";
        }
    }
};

int main()
{
    fList a;
    a.emptyList(a);
    sList b;
    b.emptyList(b);
    iList c;
    c.emptyList(c);
    cList d;
    d.emptyList(d);
    cList e;
    e.emptyList(e);
    float arr[100];
    int num, n;
    string word, q1, q2; 
    cout << "Number element of array : ";
    cin >> num;
    cout << "Enter array : ";
    for (int i = 0; i < num; i++)
    {
        cin >> arr[i];
    }
    cout << "Enter string : ";
    cin.ignore();
    getline(cin, word);
    cout << "Enter number : ";
    cin >> n;
    cout << "Enter string : ";
    cin.ignore();
    getline(cin, q1);
    cout << "Enter string : ";
    getline(cin, q2);
    cout << "Array after reversing : ";
    a.reverseFloatArr(a, num, arr);
    cout << "\nString after reversing : ";
    b.reverseWord(b, word);
    cout << endl;
    cout << n << " after converting to binary : ";
    c.decToBin(c, n);
    d.BracketMatching(d, q1);
    e.BalancingAct(e, q2);
    return 0;
}