//STT: 25 - Vương Thanh Linh - 21521082 - IT003.M23.1
//Buổi 2 - Bài 1
#include<iostream>
#include<time.h>
#include<ctime>
#include<cstdlib>
using namespace std;
//Khai báo cấu trúc node
struct Node
{
    int info;
    Node *next;
};
//Khai báo cấu trúc list
struct List
{
    Node *head;
    Node *tail;
};
//Tạo danh sách rỗng
void emptyList(List &l)
{
    l.head = l.tail = NULL;
}
//Câu 2
Node *createNode(int x)
{
    Node *p = new Node;
    if (p == NULL) return NULL;
    p->info = x;
    p->next = NULL;
    return p;
}
//Câu 3
void addHead(List &l, Node *x)
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
//Câu 4
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
//Câu 11
void printList(List &l)
{
    for (Node *i = l.head; i != NULL; i = i->next)
    {
        cout << i->info << " ";
    }
}
//Câu 5
void createList(List &l, int &n)
{
    int x;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        Node *p = createNode(x);
        addHead(l, p);
    }
}
//Câu 6
void autoCreateList(List &l)
{
    srand(time(0));
    int n = 39 + (rand() % 21);
    for (int i = 0; i < n; i++)
    {
        Node *p = createNode(-99 + (rand() % 199));
        addTail(l, p);
    }
}
//Câu 7
void inputFromArr(List &l)
{
    int n, a[100];
    cout << "Number of elements : ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    cout << "Array : ";
    for (int i = 0 ; i < n; i++)
    {
        cout << a[i] << " ";
    }
    for (int i = 0; i < n; i++)
    {
        Node *p = createNode(a[i]);
        addTail(l, p);
    }
    cout << "\nLinked list after input from array : ";
    printList(l);
}
//Câu 8
void addMid(List &l, Node *x, int &n)
{
    Node *p = l.head;
    if (n % 2 == 0)
    {
        for (int i = 0; i < ((n - 2)/ 2); i++)
        {
            p = p->next;
        }
        x->next = p->next;
        p->next = x;
    }
    else
    {
        for (int i = 0; i < ((n - 1)/ 2); i++)
        {
            p = p->next;
        }
        x->next = p->next;
        p->next = x;
    }
    cout << "Linked list after adding value to middle : ";
    printList(l);
}
//Câu 12
void printAddress(List &l, int &n)
{
    for (Node *i = l.head; i != NULL; i = i->next)
    {
        cout << i->info << "<" << &i << "> ";
    }
}
//Câu 13
void printHeadTail(List &l)
{
    if (l.head == NULL && l.tail == NULL)
    {
        cout << "Head : NULL";
        cout << "\nTail : NULL";
    }
    else if (l.head != NULL && l.tail == NULL)
    {
        cout << "Head : " << l.head->info << "<" << &l.head << ">";
        cout << "\nTail : NULL";
    }
    else if (l.head == NULL && l.tail != NULL)
    {
        cout << "Head : NULL";
        cout << "\nTail : " << l.tail->info << "<" << &l.tail << ">";
    }
    else
    {
        cout << "Head : " << l.head->info << "<" << &l.head << ">";
        cout << "\nTail : " << l.tail->info << "<" << &l.tail << ">";
    }
}
//Câu 14
bool checkEmpty(List &l)
{
    if (l.head == NULL && l.tail == NULL) return true;
    if (l.head != NULL || l.tail != NULL) return false;
}
//Câu 15
int nthNode(List &l, int &n)
{
    Node *i = l.head;
    for (int j = 0; j < n - 1; j++)
    {
        i = i->next;
    }
    return i->info;
}
//Câu 16
void search1stNode(List &l, int x)
{
    for (Node *i = l.head; i != NULL; i = i->next)
    {
        if (i->info == x)
        {
            cout << &i;
            break;
        }
        else continue;
    }
}
//Câu 17
void search1Node(List &l, int x)
{
    for (Node *i = l.head; i != NULL; i = i->next)
    {
        if (i->info == x)
        {
            cout << &i << " ";
        }
        else continue;
    }
}
//Câu 18
int sumNode(List &l)
{
    int sum(0);
    for (Node *i = l.head; i != NULL; i = i->next)
    {
        sum += i->info;
    }
    return sum;
}
//Câu 19
int countNode(List &l)
{
    int d(0);
    for (Node *i = l.head; i != NULL; i = i->next)
    {
        d++;
    }
    return d;
}
//Câu 20
int countEvenNode(List &l)
{
    int d(0);
    for (Node *i = l.head; i != NULL; i = i->next)
    {
        if (i->info % 2 == 0) d++;
    }
    return d;
}
int countOddNode(List &l)
{
    int d(0);
    for (Node *i = l.head; i != NULL; i = i->next)
    {
        if (i->info % 2 != 0) d++;
    }
    return d;
}
//Câu 21
int countPositive(List &l)
{
    int d(0);
    for (Node *i = l.head; i != NULL; i = i->next)
    {
        if (i->info > 0) d++;
    }
    return d;
}
int countNegative(List &l)
{
    int d(0);
    for (Node *i = l.head; i != NULL; i = i->next)
    {
        if (i->info < 0) d++;
    }
    return d;
}
//Câu 22
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
//Câu 23, 24
int maxNegative(List &l)
{
    int max(0);
    for (Node *i = l.head; i != NULL; i = i->next)
    {
        if (i->info < 0)
        {
            max = i->info;
            break;
        }
    }
    for (Node *i = l.head; i != NULL; i = i->next)
    {
        if (i->info < 0 && i->info > max)
        {
            max = i->info;
        }
    }
    return max;
}
int minOddNode(List &l)
{
    int min(0);
    for (Node *i = l.head; i != NULL; i = i->next)
    {
        if (i->info % 2 != 0)
        {
            min = i->info;
            break;
        }
    }
    for (Node *i = l.head; i != NULL; i = i->next)
    {
        if (i->info % 2 != 0 && i->info < min)
        {
            min = i->info;
        }
    }
    return min;
}
//Câu 25
void update1Value(List &l, int x, int y)
{
    for (Node *i = l.head; i != NULL; i = i->next)
    {
        if (i->info == x)
        {
            i->info = y;
            break;
        }
    }
}
//Câu 26
void updateAllValue(List &l, int x, int y)
{
    for (Node *i = l.head; i != NULL; i = i->next)
    {
        if (i->info == x)
        {
            i->info = y;
        }
    }
}
//Câu 27
int sumOddEven(List &l)
{
    int sumOdd(0), sumEven(0);
    for (Node *i = l.head; i != NULL; i = i->next)
    {
        if (i->info % 2 == 0) sumEven += i->info;
        else sumOdd += i->info;
    }
    if (sumEven < sumOdd) return 1;
    else if (sumEven > sumOdd) return -1;
    else return 0;
}
//Câu 28
void searchNode(List &l, int x)
{
    for (Node *i = l.head; i != NULL; i = i->next)
    {
        if (i->next->info == x)
        {
            cout << i->info;
        }
    }
}
//Câu 29
void reverseList(List &l)
{
    for (Node *i = l.head; i != NULL; i = i->next)
    {
        for (Node *j = i->next; j != NULL; j = j->next)
        {
            int t = i->info;
            i->info = j->info;
            j->info = t;
        }
    }
}
//Câu 30
void splitList(List &l)
{
    int n = countNode(l);
    Node *i = l.head;
    if (n % 2 != 0)
    {
        cout << "First linked list : ";
        for (int j = 0; j < (n - 1) / 2; j++)
        {
            cout << i->info << " ";
            i = i->next;
        }
        cout << "\nSecond linked list : ";
        for (int j = (n - 1) / 2; j < n; j++)
        {
            cout << i->info << " ";
            i = i->next;
        }
    }
    else 
    {
        cout << "First linked list : ";
        for (int j = 0; j < n / 2; j++)
        {
            cout << i->info << " ";
            i = i->next;
        }
        cout << "\nSecond linked list : ";
        for (int j = n / 2; j < n; j++)
        {
            cout << i->info << " ";
            i = i->next;
        }
    }
}
//Câu 31
void splitListX(List &l, int x)
{
    int n = countNode(l);
    Node *p = l.head;
    int d(0);
    while (p->next->info != x)
    {
        d++;
        p = p->next;
    }
    Node *i = l.head;
    cout << "First linked list : ";
    for (int j = 0; j <= d + 1; j++)
    {
        cout << i->info << " ";
        i = i->next;
    }
    cout << "\nSecond linked list : ";
    for (int j = d + 2; j < n; j++)
    {
        cout << i->info << " ";
        i = i->next;
    }
}
//Câu 32
void deleteHead(List &l)
{
    Node *p;
    if (l.head == NULL) return;
    else
    {
        p = l.head;
        l.head = p->next;
        delete p;
    }
}
//Câu 33
void deleteTail(List &l)
{
    Node *p, *q;
    p = l.head;
    q = NULL;
    while (p->next != NULL)
    {
        q = p;
        p = p->next;
    }
    delete p;
    q->next = NULL;
    return;
}
//Câu 34
void delete1stNode(List &l, int x)
{
    Node *p = l.head;
    Node *q = l.head;
    while (p != NULL)
    {
        if (p->info == x)
        {
            if (p == l.head)
            {
                p = l.head;
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
}
//Câu 35
List link2List(List &l1, List &l2)
{
    List newList;
    newList.head = l1.head;
    l1.tail->next  = l2.head;
    newList.tail = l2.tail;
    return newList;
}
//Câu 37
void deleteList(List &l)
{
    Node *p;
    while (l.head != NULL)
    {
        p = l.head;
        l.head = p->next;
        delete p;
    }
    l.tail = NULL;
}
//Câu 38
void IncreaseList(List &l)
{
    for (Node *i = l.head; i != NULL; i = i->next)
    {
        for (Node *j = i->next; j != NULL; j = j->next)
        {
            if (i->info > j->info)
            {
                int t = i->info;
                i->info = j->info;
                j->info = t;
            }
        }
    }
    cout << "Linked list after sorting increase : ";
    printList(l);
}
void DecreaseList(List &l)
{
    for (Node *i = l.head; i != NULL; i = i->next)
    {
        for (Node *j = i->next; j != NULL; j = j->next)
        {
            if (i->info < j->info)
            {
                int t = i->info;
                i->info = j->info;
                j->info = t;
            }
        }
    }
    cout << "Linked list after sorting decrease : ";
    printList(l);
}

int main()
{
    List l;
    emptyList(l);
    int num;
    cout << "Number of nodes : ";
    cin >> num;
    createList(l, num);
    cout << "Linked list : ";
    printList(l);
    cout << "\n-------------Options-------------\n";
    cout << "1. Input list normally and add head/tail";
    cout << "\n2. Input list automatically";
    cout << "\n3. Input list from an array";
    cout << "\n4. Insert a node into middle position";
    cout << "\n5. Print inputted list";
    cout << "\n6. Print value and address of nodes";
    cout << "\n7. Print value and address of head and tail of list";
    cout << "\n8. Check empty list";
    cout << "\n9. Return node nth in list";
    cout << "\n10. Search first node has X value";
    cout << "\n11. Search all nodes have X value";
    cout << "\n12. Sum of all nodes";
    cout << "\n13. Length of list";
    cout << "\n14. Number of even and odd nodes";
    cout << "\n15. Number of positive and negative nodes";
    cout << "\n16. Maximum and minimum node";
    cout << "\n17. Maximum negative node and minimum odd node ";
    cout << "\n18. Update new value Y to one node has value X";
    cout << "\n19. Update new value Y to all nodes has value X";
    cout << "\n20. Sum of even and odd node";
    cout << "\n21. Find node before node has value X";
    cout << "\n22. Reverse list";
    cout << "\n23. Split list in middle position";
    cout << "\n24. Split list at node X";
    cout << "\n25. Delete head of list";
    cout << "\n26. Delete tail of list";
    cout << "\n27. Delete first node has value X";
    cout << "\n28. Link 2 lists into 1 list";
    cout << "\n29. Delete all nodes";
    cout << "\n30. Sort list";
    cout << "\n---------------------------------\n";
    int menu;
    int t = 35;
    while (t--)
    {
        cout << "\nChoose one option : ";
        cin >> menu;
        if (menu > 0 && menu < 36)
        {
            switch(menu)
            {
                case 1:
                {
                    int head, tail;
                    cout << "\nInsert value of head/tail want to add : ";
                    cin >> head >> tail;
                    addHead(l, createNode(head));
                    addTail(l, createNode(tail));
                    cout << "Linked list after adding head/tail : ";
                    printList(l);
                    break; 
                }
                case 2:
                {
                    List b;
                    emptyList(b);
                    autoCreateList(b);
                    cout << "Linked list after automatically input : ";
                    printList(b);
                    break; 
                }
                case 3:
                {
                    List c; 
                    emptyList(c);
                    inputFromArr(c);
                    break; 
                }
                case 4:
                {
                    int n;
                    cout << "Value want to insert to middle : ";
                    cin >> n;
                    addMid(l, createNode(n), num);
                    break; 
                }
                case 5:
                {
                    cout << "Linked list : ";
                    printList(l);
                    break; 
                }
                case 6:
                {
                    cout << "Linked list and address : ";
                    printAddress(l, num);
                    break; 
                }
                case 7:
                {
                    printHeadTail(l);
                    break; 
                }
                case 8:
                {
                    if (checkEmpty(l)) cout << "Empty list";
                    else cout << "Not empty list";
                    break; 
                }
                case 9:
                {
                    int n;
                    cout << "Position of node want to return : ";
                    cin >> n;
                    cout << nthNode(l, n);
                    break; 
                }
                case 10:
                {
                    int x;
                    cout << "Value of node want to search : ";
                    cin >> x;
                    search1stNode(l, x);
                    break; 
                }
                case 11:
                {
                    int x;
                    cout << "Value of node want to search : ";
                    cin >> x;
                    searchNode(l, x);
                    break; 
                }
                case 12:
                {
                    cout << "Sum of all node in list : " << sumNode(l);
                    break; 
                }
                case 13:
                {
                    cout << "Number of nodes in list : " << countNode(l);
                    break; 
                }
                case 14:
                {
                    cout << "Number of even nodes is " << countEvenNode(l);
                    cout << " and number of odd nodes is " << countOddNode(l);
                    break; 
                }
                case 15:
                {
                    cout << "Number of negative nodes is " << countNegative(l);
                    cout << " and number of positive nodes is " << countPositive(l);
                    break; 
                }
                case 16:
                {
                    cout << "Maximum node is " << findMax(l);
                    cout << " and minimum node is " << findMin(l);
                    break; 
                }
                case 17:
                {
                    cout << "Maximum negative node is " << maxNegative(l);
                    cout << " and minium odd node is " << minOddNode(l);
                    break; 
                }
                case 18:
                {
                    int x, y;
                    cout << "Insert node wants to update and new value ";
                    cin >> x >> y;
                    update1Value(l, x, y);
                    cout << "Linked list after update : ";
                    printList(l);
                    break; 
                }
                case 19:
                {
                    int x, y;
                    cout << "Insert node wants to update and new value ";
                    cin >> x >> y;
                    updateAllValue(l, x, y);
                    cout << "Linked list after update : ";
                    printList(l);
                    break; 
                }
                case 20:
                {
                    if (sumOddEven(l) == 0) cout << "Sum of even nodes equals to sum of odd nodes";
                    if (sumOddEven(l) == 1) cout << "Sum of even nodes less than to sum of odd nodes";
                    if (sumOddEven(l) == -1) cout << "Sum of even nodes greater than sum of odd nodes";
                    break; 
                }
                case 21:
                {
                    int x;
                    cout << "Value : ";
                    cin >> x;
                    cout << "Node stands before " << x << " is : ";
                    searchNode(l, x);
                    break; 
                }
                case 22:
                {
                    reverseList(l);
                    cout << "Reversed list : ";
                    printList(l);
                    break; 
                }
                case 23:
                {
                    splitList(l);
                    break; 
                }
                case 24:
                {
                    int x;
                    cout << "Value of node want to split : ";
                    cin >> x;
                    splitListX(l, x);
                    break; 
                }
                case 25:
                {
                    deleteHead(l);
                    cout << "Linked list after deleting head : ";
                    printList(l);
                    break; 
                }
                case 26:
                {
                    deleteTail(l);
                    cout << "Linked list after deleting tail : ";
                    printList(l);
                    break; 
                }
                case 27:
                {
                    int x;
                    cout << "Value of node wants to delete : ";
                    cin >> x;
                    delete1stNode(l, x);
                    cout << "Linked list after deleting " << x << " is : ";
                    printList(l);
                    break; 
                }
                case 28:
                {
                    List a, b;
                    emptyList(a);
                    emptyList(b);
                    int num1, num2;
                    cout << "Number of nodes of 2 list want to link : ";
                    cin >> num1 >> num2;
                    createList(a, num1);
                    createList(b, num2);
                    cout << "First linked list : ";
                    printList(a);
                    cout << "\nSecond linked list : ";
                    printList(b);
                    cout << "\nLink list after linking 2 list : ";
                    List t = link2List(a, b);
                    printList(t);
                    break; 
                }
                case 29:
                {
                    deleteList(l);
                    if (checkEmpty(l)) cout << "Empty list";
                    else cout << "Not empty list";
                    break; 
                }
                case 30:
                {
                    IncreaseList(l);
                    cout << endl;
                    DecreaseList(l);
                    break; 
                }
            }
        }
        else cout << "Please, choose again.\n";
    }
    return 0;
}