#include<iostream>
#include<list>
using namespace std;
class List
{
private:
    list<double> l;
    unsigned int sz;
public:
    void createEmpty()
    {
        l.empty();
    }
    void add(double x)
    {
        l.push_back(x);
    }
    void delete1st(double x)
    {
        list<double>::iterator it;
        for (it = l.begin(); it != l.end(); it++)
        {
            if (*it == x)
            {
                l.erase(it);
                break;
            }
        }
    }
    void deleteX(double x)
    {
        l.remove(x);
    }
    void swap(unsigned int x, double y)
    {
        if (x > 0 && x < l.size())
        {
            list<double>::iterator it = l.begin();
            advance(it, x);
            *it = y;
        }
    }
    void printList()
    {
        cout << "[";
        while(!l.empty())
        {
            double i = l.front();
            if (i == l.back())
            {
                break;
            }
            cout << i << ",";
            l.pop_front();
        }
        cout << l.back() << "]";
    }
};
int main()
{
    List l;
    int n;
    while (1)
    {
        cin >> n;
        if (n == -1)
        {
            l.printList();
        }
        if (n == 0)
        {
            double x;
            cin >> x;
            l.add(x);
        }
        if (n == 1)
        {
            double y;
            cin >> y;
            l.delete1st(y);
        }
        if (n == 2)
        {
            double z;
            cin >> z;
            l.deleteX(z);
        }
        if (n == 3)
        {
            double f, g;
            cin >> f >> g;
            l.swap(f, g);
        }
    }
    return 0;
}