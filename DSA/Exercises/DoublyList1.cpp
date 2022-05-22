#include<iostream>
using namespace std;

struct Node
{
    char info;
    Node *pre;
    Node *next;
};

struct List
{
    Node *head;
    Node *tail;
};

Node *createNode(char x)
{
    Node *p = new Node;
    if (p == NULL) return NULL;
    else
    {
        p->info = x;
        p->pre = NULL;
        p->next = NULL;
    }
    return p;
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

void emptyList(List &l)
{
    l.head = l.tail = NULL;
}

void createList(List &l, int &n)
{
    char x;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        Node *p = createNode(x);
        addTail(l, p);
    }
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

void findMostAppearance(List &l)
{
    int max(1);
    Node *p;
    for (Node *i = l.head; i != NULL; i = i->next)
    {
        int d(0);
        for (Node *j = l.head; j != NULL; j = j->next)
        {
            if (i->info == j->info) d++;
        }
        if (d > max)
        {
            max = d;
            p = i;
        }
    }
    cout << p->info;
}

void sortByAlpha(List &l)
{
    for (Node *i = l.head; i != NULL; i = i->next)
    {
        for (Node *j = i->next; j != NULL; j = j->next)
        {
            if (int(i->info) > int(j->info))
            {
                char t = i->info;
                i->info = j->info;
                j->info = t;
            }
        }
    }
}

void addNode(List &l, Node *x, int n)
{
    Node *i = l.head;
    if (n % 2 == 0)
    {
        for (int j = 0; j < (n - 2) / 2; j++)
        {
            i = i->next;
        }
        x->next = i->next;
        i->next = x;
        x->pre = i;
    }
    else
    {
        for (int j = 0; j < (n - 1) / 2; j++)
        {
            i = i->next;
        }
        x->next = i->next;
        i->next = x;
        x->pre = i;
    }
}

void deleteHead(List &l)
{
    Node *p;
    if (l.head != NULL)
    {
        p = l.head;
        l.head = l.head->next;
        l.head->pre = NULL;
        delete p;
        if (l.head == NULL) l.tail = NULL;
    }
}

void deleteTail(List &l)
{
    Node *p;
    if (l.head != NULL)
    {
        p = l.tail;
        l.tail = l.tail->pre;
        l.tail->next = NULL;
        delete p;
        if (l.head == NULL) l.tail = NULL;
    }
}

void deleteNodeX(List &l, char x)
{
    Node *p = l.head;
    Node *q = l.head;
    while (p != NULL)
    {
        if (p->info == x)
        {
            if (p == l.head)
            {
                deleteHead(l);
            }
            q->next = p->next;
            p->next->pre = q;
            delete p;
        }
        q = p;
        p = p->next;
    }
}

void printList(List &l)
{
    for (Node *i = l.head; i != NULL; i =i->next)
    {
        cout << i->info << " ";
    }
}

int main()
{
    List l;
    int n;
    emptyList(l);
    cout << "Number of nodes : ";
    cin >> n;
    createList(l, n);
    cout << "Linked list : ";
    printList(l);
    cout << "\nNode appears most is : ";
    findMostAppearance(l);
    if (checkDx(l)) cout << "\nLinked list is symmetric";
    else cout << "\nLinked list is not symmetric";
    sortByAlpha(l);
    cout << "\nLinked list after sorting by Alphabet : ";
    printList(l);
    char t;
    cout << "\nCharacter wants to insert : ";
    cin >> t;
    addNode(l, createNode(t), n);
    cout << "Linked list after inserting " << t << " and in order : ";
    sortByAlpha(l);
    printList(l);
    deleteHead(l);
    deleteTail(l);
    cout << "\nAfter deleting maximum and minimum node : ";
    printList(l);
    return 0;
}