#include<iostream>
using namespace std;
struct Room
{
    int number;
    char type;
    int status;
};

struct Node
{
    Room data;
    Node *next;
};

struct List
{
    Node *head;
    Node *tail;
};

Node *createNode(Room x)
{
    Node *p = new Node;
    cin >> x.number >> x.type >> x.status;
    p->data = x;
    p->next = NULL;
    return p;
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

void emptyList(List &l)
{
    l.head = l.tail = NULL;
}

void createList(List &l, int &n)
{
    for (int i = 0; i < n; i++)
    {
        Room x;
        Node *p = createNode(x);
        addTail(l, p);
    }
}

void printList(List &l)
{
    for (Node *i = l.head; i != NULL; i = i->next)
    {
        if (i->data.type != 'A' && i->data.type != 'B' && i->data.status != 0 && i->data.status != 1)
        {
            continue;
        }
        cout << "\n-----Information-----";
        cout << "\nRoom number : " << i->data.number;
        cout << "\nRoom type : ";
        if (i->data.type == 'A') cout << "Single room";
        else cout << "Double room";
        cout << "\nRoom status : ";
        if (i->data.status == 0) cout << "Available";
        else cout << "Unavailable";    
    }
}

int typeA(List &l)
{
    int dA(0);
    for (Node *i = l.head; i != NULL; i = i->next)
    {
        if (i->data.type == 'A') dA++;
    }
    return dA;
}

int typeB(List &l)
{
    int dB(0);
    for (Node *i = l.head; i != NULL; i = i->next)
    {
        if (i->data.type == 'B') dB++;
    }
    return dB;
}

int type1(List &l)
{
    int d1(0);
    for (Node *i = l.head; i != NULL; i = i->next)
    {
        if (i->data.status == 1 && i->data.type == 'A') d1++;
    }
    return d1;
}

int type0(List &l)
{
    int d0(0);
    for (Node *i = l.head; i != NULL; i = i->next)
    {
        if (i->data.status == 0 && i->data.type == 'B') d0++;
    }
    return d0;
}

void deleteRoom(List &l, int x)
{
    Node *p = l.head;
    Node *q = l.head;
    while (p != NULL)
    {
        if (p->data.number == x)
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
        p = p->next;
        q = q->next;
    }
    printList(l);
}

int main()
{
    List l;
    emptyList(l);
    int n, x;
    cout << "Number of room : ";
    cin >> n;
    createList(l, n);
    printList(l);
    cout << "\n------Statistic-------";
    cout << "\nSingle room : " << typeA(l);
    cout << "\nAvailable : " << typeA(l) - type1(l);
    cout << "\nUnavailable : " << type1(l);
    cout << "\n--------------------\n";
    cout << "Double room : " << typeB(l);
    cout << "\nAvailable : " << type0(l);
    cout << "\nUnvailable : " << typeB(l) - type0(l);
    cout << "\n------------------";
    cout << "\nRevenue per day : " << (type1(l) * 200) + (typeB(l) - type0(l)) * 350 << " dong";
    cout << "\n------------------";
    cout << "\nEnter room number need deleting : ";
    cin >> x;
    cout << "\nAfter deleting : ";
    deleteRoom(l, x);
    return 0;
}