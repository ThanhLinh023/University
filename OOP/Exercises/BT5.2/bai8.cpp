#include<iostream>
#include<queue>
using namespace std;
class Queue
{
private:
    queue<int> q;
public:
    Queue() {}
    void push(int n)
    {
        q.push(n);
    }
    void pop()
    {
        q.pop();
    }
    int front()
    {
        return q.front();
    }
    int back()
    {
        return q.back();
    }
    bool isEmpty()
    {
        if (q.empty()) return true;
        return false;
    }
    int size()
    {
        return q.size();
    }
};
int main()
{
    Queue k;
    int x;
    cout << "Enter queue, enter -1 if you want to quit.\n";
    while (1)
    {
        cin >> x;
        k.push(x);
        if (x == -1) break;
    }
    cout << "The queue is: ";
    while (!k.isEmpty())
    {
        cout << k.front() << " ";
        k.pop();
    }
    return 0;
}