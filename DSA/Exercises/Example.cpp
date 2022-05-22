#include<iostream>
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

void CreateEmptyList(List &l)
{
    l.head = l.tail = NULL;
}

Node *CreateNode(int x)
{
    Node *p = new Node;
    p->info = x;
    p->next = NULL;
}

void AddTail(List &l, Node *x)
{
    if(l.head == NULL)
    {
        l.head = l.tail = x;
    }
    else
    {
        l.tail->next = x;
        l.tail = x;
    }
}

void AddHead(List &l, Node *x)
{
    if(l.head == NULL)
    {
        l.head = l.tail = x;
    }
    else
    {
        x->next = l.head;
        l.head = x;
    }
}

void PrintList(List l)
{
    Node *p = l.head;
    while(p != NULL)
    {
        cout << p->info << " ";
        p = p->next;
    }
}
int main()

{
    List l;
    CreateEmptyList(l);  
    AddTail(l,CreateNode(1));
    AddTail(l,CreateNode(2));
    AddTail(l,CreateNode(3));
    AddHead(l,CreateNode(4));
    AddHead(l,CreateNode(5));
    PrintList(l);
    return 0;
}
