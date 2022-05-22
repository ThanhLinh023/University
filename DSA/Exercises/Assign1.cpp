#include <iostream>
#include <math.h>
using namespace std;
struct Node
{
    int info;
    Node *next;
};

struct List
{
    Node *head;
    Node *tail;
};

Node *createNode(int x)
{
    Node *p = new Node;
    p->info = x;
    p->next = NULL;
    return p;
}

void emptyList(List &l)
{
    l.head = l.tail = NULL;
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
        l.tail = x;
    }
}

void createList(List &l, int &n)
{
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        Node *p = createNode(x);
        addTail(l, p);
    }
}

void printList(List &l)
{
    for (Node *i = l.head; i != NULL; i = i->next)
    {
        cout << i->info << " ";
    }
}

bool CheckIncr(int m)
{
    int n = m;
    int a[100] = {};
    int i(0), d(0);
    while (n > 0)
    {
        a[i] = n % 10;
        n /= 10;
        i++;
    }
    for (int j = 0; j < i - 1; j++)
    {
        if (a[j] <= a[j + 1])
            d++;
    }
    if (d == 0)
        return true;
    return false;
}

int countIncr(List &l)
{
    int d(0);
    Node *p = l.head;
    while (p != NULL)
    {
        if (CheckIncr(p->info))
            d++;
        p = p->next;
    }
    return d;
}

void printOdd(List &l)
{
    Node *p = l.head;
    int i = 1;
    while (p != NULL)
    {
        if (i % 2 != 0)
            cout << p->info << " ";
        p = p->next;
        i++;
    }
}

int count(List &l, int x)
{
    int c(0);
    for (Node *i = l.head; i != NULL; i = i->next)
    {
        if (i->info == x)
            c++;
    }
    return c;
}

void print1times(List &l)
{
    for (Node *i = l.head; i != NULL; i = i->next)
    {
        if (count(l, i->info) == 1)
            cout << i->info << " ";
    }
}

int findMax(List &l)
{
    int max = l.head->info;
    for (Node *i = l.head; i != NULL; i = i->next)
    {
        if (i->info > max)
            max = i->info;
    }
    return max;
}

int findMin(List &l)
{
    int min = l.head->info;
    for (Node *i = l.head; i != NULL; i = i->next)
    {
        if (i->info < min)
            min = i->info;
    }
    return min;
}

bool checkEven(List &l)
{
    int d(0);
    Node *p = l.head;
    while (p != NULL)
    {
        if (p->info % 2 != 0)
            d++;
        p = p->next;
    }
    if (d == 0)
        return true;
    return false;
}

bool checkDx(List &l)
{
    int d(0);
    Node *p = l.head;
    Node *q = l.tail;
    while (p != NULL && q != NULL)
    {
        if (p->info != q->info)
            d++;
        p = p->next;
        q = q->next;
    }
    if (d == 0)
        return true;
    return false;
}

void sort(List l)
{
    for (Node *p = l.head; p != NULL; p = p->next)
    {
        for (Node *q = p->next; q != NULL; q = q->next)
        {
            if (p->info >= q->info)
            {
                int t = p->info;
                p->info = q->info;
                q->info = t;
            }
        }
    }
    printList(l);
}

void deleteNode(List &l, int x)
{
    Node *p = l.head;
    Node *q = l.head;
    while (p != NULL)
    {
        if (p->info == x)
        {
            if (p == l.head)
            {
                l.head = p->next;
                delete p;
                break;
            }
            q->next = p->next;
            delete p;
            break;
        }
        q = p;
        p = p->next;
    }
    printList(l);
}

int main()
{
    List l;
    emptyList(l);
    int n;
    cout << "Number of nodes in linked list : ";
    cin >> n;
    createList(l, n);
    int menu;
    int t = 9;
    cout << "\n------------Options------------\n";
    cout << "1. Print linked list.\n";
    cout << "2. Count number of nodes has increasing info.\n";
    cout << "3. Info of node in odd position.\n";
    cout << "4. Node appears once.\n";
    cout << "5. Maximum/minimum info node.\n";
    cout << "6. Check even linked list.\n";
    cout << "7. Check symmetric linked list.\n";
    cout << "8. Soft linked list.\n";
    cout << "9. Delete 1 node in linked list.\n";
    cout << "--------------------------------\n";
    while (t--)
    {
        cout << "\nChoose one option : ";
        cin >> menu;
        if (menu >= 1 && menu <= 9)
        {
            switch (menu)
            {
            case 1:
            {
                cout << "1. Linked list : ";
                printList(l);
                break;
            }
            case 2:
            {
                cout << "2. Number of nodes has increasing info : " << countIncr(l);
                break;
            }
            case 3:
            {
                cout << "3. Info of node in odd position : ";
                printOdd(l);
                break;
            }
            case 4:
            {
                cout << "4. Node appears once : ";
                print1times(l);
                break;
            }
            case 5:
            {
                cout << "5. Maximum info node is " << findMax(l);
                cout << " and minimum info node is " << findMin(l);
                break;
            }
            case 6:
            {
                if (checkEven(l))
                {
                    cout << "6. Linked list includes all even node";
                }
                else
                {
                    cout << "6. Linked list does not include all even node";
                }
                break;
            }
            case 7:
            {
                if (checkDx(l))
                {
                    cout << "7. Linked list is symmetric";
                }
                else
                {
                    cout << "7. Linked list is not symmetric";
                }
                break;
            }
            case 8:
            {
                cout << "8. Linked list after sorted : ";
                sort(l);
                break;
            }
            case 9:
            {
                int x;
                cout << "Value of x : ";
                cin >> x;
                cout << "9.Linked list after deleting node " << x << " : ";
                deleteNode(l, x);
                break;
            }
            }
        }
        else
            cout << "Please, choose again.\n";
    }
    return 0;
}