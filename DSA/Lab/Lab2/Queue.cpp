//STT: 25 - Vương Thanh Linh - Buổi 3 - Bài 2
#include<iostream>
using namespace std;
struct Node
{
    int info;
    Node *next;
};
struct Queue
{
    Node *front;
    Node *rear;
};
void emptyQueue(Queue &q)
{
    q.front = q.rear = NULL;
}
bool isEmpty(Queue &q)
{
    if (q.front == NULL) return true;
    return false;
}
Node *createNode(int x)
{
    Node *p = new Node;
    if (p == NULL) return NULL;
    p->info = x;
    p->next = NULL;
    return p;
}
void enQueue(Queue &q, Node *x)
{
    if (q.front == NULL)
    {
        q.front = q.rear = x;
    }
    else
    {
        q.rear->next = x;
        q.rear = x;
    }
}
void deQueue(Queue &q)
{
    Node *p;
    if (q.front != NULL)
    {
        p = q.front;
        q.front = q.front->next;
        delete p;
        if (q.front == NULL) q.rear == NULL;
    }
}
Node *front(Queue &q)
{
    if (q.front != NULL) return q.front;
    return NULL;
}
Node *rear(Queue &q)
{
    if (q.rear != NULL) return q.rear;
    return NULL;
}
void print(Queue &q)
{
    for (Node *i = q.front; i != NULL; i = i->next)
    {
        cout << i->info << " ";
    }
}
int main()
{
    Queue q;
    emptyQueue(q);
    cout << "--------Options-------";
    cout << "\n1. Check empty queue";
    cout << "\n2. Enqueue";
    cout << "\n3. Dequeue";
    cout << "\n4. Front and rear";
    cout << "\n5. Print queue";
    cout << "\n--------------------\n";
    int menu;
    while (1)
    {
        cout << "Choose one option: ";
        cin >> menu;
        switch (menu)
        {
            case 1:
                if (isEmpty(q)) cout << "Queue is empty\n";
                else cout << "Queue is not empty\n";
                break;
            case 2:
                int x;
                cout << "Enter value: ";
                cin >> x;
                enQueue(q, createNode(x));
                break;
            case 3:
                deQueue(q);
                break;
            case 4:
                cout << "Front: " << front(q)->info;
                cout << "\nRear: " << rear(q)->info << endl;
                break;
            case 5:
                cout << "Queue: ";
                print(q);
                cout << endl;
                break;
        }
    }
    return 0;
}