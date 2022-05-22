//STT: 25 - Vương Thanh Linh - Buổi 3 - Bài 1
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
    for (Node *i = s.top; i != NULL; i = i->next)
    {
        cout << "\t" << i->info << "\n";
    }
}
int main()
{
    Stack s;
    emptyStack(s);
    cout << "-------Options-------";
    cout << "\n1. Check empty stack";
    cout << "\n2. Push";
    cout << "\n3. Pop";
    cout << "\n4. Top";
    cout << "\n5. Print stack";
    cout << "\n-------------------\n";
    int menu;
    while (1)
    {
        cout << "Choose one option: ";
        cin >> menu;
        switch (menu)
        {
            case 1:
                if (isEmpty(s)) cout << "Stack is empty\n";
                else cout << "Stack is not empty\n";     
                break;
            case 2:
                int x;
                cout << "Enter value: ";
                cin >> x;
                push(s, createNode(x));
                break;
            case 3:
                pop(s);
                break;
            case 4:
                cout << "Top: " << top(s)->info << endl;
                break;
            case 5:
                cout << "Stack: ";
                print(s);
                break;
        }
    }
}