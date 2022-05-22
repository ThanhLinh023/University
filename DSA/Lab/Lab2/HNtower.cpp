//STT: 25 - Vương Thanh Linh - Buổi 3 - Bài 3
#include<iostream>
using namespace std;
struct Node
{
    int info;
    Node *next;
};
struct Stack
{
    Node *top;
};
void emptyStack(Stack &s)
{
    s.top = NULL;
}
bool isEmpty(Stack &s)
{
    if (s.top == NULL) return true;
    return false;
}
Node *createNode(int x)
{
    Node *p = new Node;
    if (p == NULL)
    {
        return NULL;
    }
    p->info = x;
    p->next = NULL;
    return p;
}
void push(Stack &s, Node *x)
{
    if (s.top == NULL)
    {
        s.top = x;
    }
    else
    {
        x->next = s.top;
        s.top = x;
    }
}
void pop(Stack &s)
{
    Node *p;
    if (s.top != NULL)
    {
        p = s.top;
        s.top = s.top->next;
        delete p;
    }
    else return;
}
Node *top(Stack &s)
{
    if (s.top != NULL) return s.top;
    else return NULL;
}
void print(Stack &s)
{
    cout << "STACK = <";
    for (Node *i = s.top; i != NULL; i = i->next)
    {
        cout << "\t" << i->info;
    }
    cout << "\t>";
}
int main()
{
    //6,1,4,6,2,3,6
    Stack a, b, c;
    emptyStack(a);
    emptyStack(b);
    emptyStack(c);
    push(a, createNode(1));
    push(a, createNode(2));
    push(a, createNode(3));
    cout << "-----------Options---------";
    cout << "\n\t0. Creating Tower.";
    cout << "\n\t1. A -> B";
    cout << "\n\t2. B -> A";
    cout << "\n\t3. B -> C";
    cout << "\n\t4. C -> B";
    cout << "\n\t5. C -> A";
    cout << "\n\t6. A -> C";
    cout << "\n--------------------------\n";
    int menu, d(0);
    while (1)
    {
        cout << "===================================\n";
        cout << "A Tower\n";
        print(a);
        cout << "\n===================================\n";
        cout << "B Tower\n";
        print(b);
        cout << "\n===================================\n";
        cout << "C Tower\n";
        print(c);
        cout << "\n===================================\n";
        cout << "\n\tMove times: " << d;
        cout << "\n\tPlease input: ";
        cin >> menu;
        switch (menu)
        {
            case 1:
                push(b, createNode(a.top->info));
                pop(a);
                d++;
                break;
            case 2:
                push(a,createNode(b.top->info));
                pop(b);
                d++;
                break;
            case 3:
                push(c,createNode(b.top->info));
                pop(b);
                d++;
                break;
            case 4:
                push(b,createNode(c.top->info));
                pop(c);
                d++;
                break;
            case 5:
                push(a,createNode(c.top->info));
                pop(c);
                d++;
                break;
            case 6:
                push(c,createNode(a.top->info));
                pop(a);
                d++;
                break;
        }
    }
    return 0;
}