#include<iostream>
#include<time.h>
#include<ctime>
#include<cstdlib>
using namespace std;
struct Node
{
    int data;
    Node *left;
    Node *right;
};
struct Tree
{
    Node *root;
};
void createTree(Tree &t)
{
    t.root = NULL;
}
Node *createNode(int x)
{
    Node *p = new Node;
    p->data = x;
    p->left = p->right = NULL;
    return p;
}
void addNode(Tree &t, Node *x)
{
    if (t.root == NULL)
    {
        t.root = x;
    }
    else
    {
        Node *i = t.root;
        Node *pos = NULL;
        while (i != NULL)
        {
            pos = i;
            if (x->data < i->data)
            {
                i = i->left;
            }
            else if (x->data > i->data)
            {
                i = i->right;
            }
        }
        if (x->data > pos->data)
        {
            pos->right = x;
        }
        if (x->data < pos->data)
        {
            pos->left = x;
        }
    }
}
void printNode(Node *x)
{
    if (x !=  NULL)
    {
        cout << "<L: ";
        if (x->left == NULL)
        {
            cout << "NULL" << "> \t (";
        }
        else cout << &x->left << "> \t (";
        cout << x->data << "~" << &x << ") \t <R: ";
        if (x->right == NULL)
        {
            cout << "NULL>\n";
        }
        else cout << &x->right << ">\n";
    }
}
void createTreeByHand(Tree &t)
{
    int n;
    cout << "Nhap n (nhap -1 de dung nhap)\n";
    while (1)
    {
        cout << "Nhap n = ";
        cin >> n;
        Node *p = createNode(n);
        addNode(t, p);
        if (n == -1) break;
    }
}
void NLR(Node *t)
{
    if (t != NULL)
    {
        printNode(t);
        NLR(t->left);
        NLR(t->right);
    }
}
void LNR(Node *t)
{
    if (t != NULL)
    {
        LNR(t->left);
        printNode(t);
        LNR(t->right);
    }
}
void LRN(Node *t)
{
    if (t != NULL)
    {
        LRN(t->left);
        LRN(t->right);
        printNode(t);
    }
}
Tree autoCreateTree()
{
    Tree t;
    createTree(t);
    int n;
    n = 10 + rand() % 11;
    for (int i = 0; i < n; i++)
    {
        int k;
        k = -385 + rand() % 1717;
        addNode(t, createNode(k));
    }
    return t;
}
void countNode(Node *t, int &d)
{
    if (t != NULL)
    {
        countNode(t->left, d);
        d++;
        countNode(t->right, d);
    }
}
void countLeaf(Node *t, int &d)
{
    if (t != NULL)
    {
        countLeaf(t->left, d);
        if (t->left == NULL && t->right == NULL)
        {
            d++;
        }
        countLeaf(t->right, d);
    }
}
Node *findX(Tree &t, int x)
{
    Node *i = t.root;
    while (i != NULL)
    {
        if (i->data == x) return i;
        if (i->data > x)
        {
            i = i->left;
        }
        else if (i->data < x)
        {
            i = i->right;
        }
    }
    return NULL;
}
void branchNode(Tree &t, Node *i)
{
    NLR(findX(t, i->data));
}
void countNodeLessThanX(Node *t, int &d, int x)
{
    if (t != NULL)
    {
        countNodeLessThanX(t->left, d, x);
        if (t->data < x) d++;
        countNodeLessThanX(t->right, d, x);
    }
}
void countNodeGreaterThanX(Node *t, int &d, int x)
{
    if (t != NULL)
    {
        countNodeGreaterThanX(t->left, d, x);
        if (t->data > x) d++;
        countNodeGreaterThanX(t->right, d, x);
    }
}
void countNodeXY(Node *t, int &d, int &x, int &y)
{
    if (t != NULL)
    {
        countNodeXY(t->left, d, x, y);
        if (t->data > x && t->data < y) d++;
        countNodeXY(t->right, d, x, y);
    }
}
int is12Greater13(int &x, int &y)
{
    if (x > y) return 0;
    else if (x < y) return 1;
    else return -1;
}
void countOddEvent(Node *t, int &d1, int &d2)
{
    if (t != NULL)
    {
        countOddEvent(t->left, d1, d2);
        if (t->data % 2 == 0) d1++;
        else d2++; 
        countOddEvent(t->right, d1, d2);
    }
}
void sumAllNode(Node *t, int &sum)
{
    if (t != NULL)
    {
        sumAllNode(t->left, sum);
        sum += t->data;
        sumAllNode(t->right, sum);
    }
}
void sumEvenNode(Node *t, int &sum)
{
    if (t != NULL)
    {
        sumEvenNode(t->left, sum);
        if (t->data % 2 == 0) sum += t->data;;
        sumEvenNode(t->right, sum);
    }
}
void sumOddNode(Node *t, int &sum)
{
    if (t != NULL)
    {
        sumOddNode(t->left, sum);
        if (t->data % 2 != 0) sum += t->data;;
        sumOddNode(t->right, sum);
    }
}
void findMax(Node *t, int &max)
{
    if (t != NULL)
    {
        findMax(t->left, max);
        if (t->data > max) max = t->data;
        findMax(t->right, max);
    }
}
void findMin(Node *t, int &min)
{
    if (t != NULL)
    {
        findMin(t->left, min);
        if (t->data < min) min = t->data;
         findMin(t->right, min);
    }
}
int main()
{
    Tree main;
    int x1;
    int demNode(0), demLa(0), nhoX(0), lonX(0), trongXY(0), demChan(0), demLe(0);
    int sumNode(0), sumChan(0), sumLe(0);
    int max = -999999;
    int min = 999999;
    cout << "--------------Menu--------------\n";
    cout << "1. Nhap gia tri cho cay bang thu cong\n";
    cout << "2. Ham tao cay tu dong\n";
    cout << "3. Duyet theo NLR\n";
    cout << "4. Duyet theo LNR\n";
    cout << "5. Duyet theo LRN\n";
    cout << "6. Tim kiem node X\n";
    cout << "7. Dem toan bo node cua cay\n";
    cout << "8. Dem toan bo node la cua cay\n";
    cout << "9. In ra node nhanh (NLR) tu mot node\n";
    cout << "10. Dem so node nho hon X\n";
    cout << "11. Dem so node lon hon X\n";
    cout << "12. Dem so node nho hon X va Y\n";
    cout << "13. So sanh gia tri o cau 10 va 11\n";
    cout << "14. Dem so node chan le va so sanh\n";
    cout << "15. Tong cac node trong cay\n";
    cout << "16. Tong cac node chan\n";
    cout << "17. Tong cac node le\n";
    cout << "18. So sanh 2 tong chan le\n";
    cout << "19. Node lon nhat va nho nhat\n";
    cout << "--------------------------------\n";
    int k;
    while (1)
    {
        cout << "\tChon 1 lua chon: ";
        cin >> k;
        switch(k)
        {
            case 1:
            {
                Tree a1;
                createTree(a1);
                createTreeByHand(a1);
                cout << "\n--------------------------------";
                cout << endl;
                break;
            }
            case 2:
            {
                main = autoCreateTree();
                cout << "Da tu dong tao cay";
                cout << "\n--------------------------------";
                cout << endl;
                break;
            }
            case 3:
            {
                cout << "Duyet theo NLR:\n";
                NLR(main.root);
                cout << "--------------------------------";
                cout << endl;
                break;
            }
            case 4:
            {
                cout << "Duyet theo LNR:\n";
                LNR(main.root);
                cout << "--------------------------------";
                cout << endl;
                break;
            }
            case 5:
            {
                cout << "Duyet theo LRN:\n";
                LRN(main.root);
                cout << "--------------------------------";
                cout << endl;
                break;
            }
            case 6:
            {
                int x;
                x = rand() % 501 + 300;
                cout << "X can tim: " << x;
                cout << endl;
                if (findX(main, x) != NULL)
                {
                    cout << x << " co trong cay";
                }
                else cout << x << " khong co trong cay";
                cout << "\n--------------------------------";
                cout << endl;
                break;
            }
            case 7:
            {
                countNode(main.root, demNode);
                cout << "So luong node la: " << demNode;
                cout << "\n--------------------------------";
                cout << endl;
                break;
            }
            case 8:
            {
                countLeaf(main.root, demLa);
                cout << "So luong la trong cay la: " << demLa;
                cout << "\n--------------------------------";
                cout << endl;
                break;
            }
            case 9:
            {
                int t;
                cout << "Nhap gia tri node can in nhanh: ";
                cin >> t;
                branchNode(main, createNode(t));
                cout << "\n--------------------------------";
                cout << endl;
                break;
            }
            case 10:
            {
                cout << "Nhap vao x: ";
                cin >> x1;
                countNodeLessThanX(main.root, nhoX, x1);
                cout << "So luong node nho hon " << x1 << " la: " << nhoX;
                cout << "\n--------------------------------";
                cout << endl;
                break;
            }
            case 11:
            {
                cout << "Nhap vao x: " << x1;
                countNodeGreaterThanX(main.root, lonX, x1);
                cout << "\nSo luong node lon hon " << x1 << " la: " << lonX;
                cout << "\n--------------------------------";
                cout << endl;
                break;
            }
            case 12:
            {
                int x2, y1;
                cout << "Nhap vao x va y: ";
                cin >> x2 >> y1;
                countNodeXY(main.root, trongXY, x2, y1);
                cout << "So luong node lon hon " << x2 << " va nho hon " << y1 << " la: " << trongXY;
                cout << "\n--------------------------------";
                cout << endl;
                break;
            }
            case 13:
            {
                if (is12Greater13(nhoX, lonX) == 0)
                {
                    cout << "So luong node nho hon " << x1 << " lon hon so luong";
                    cout << " node lon hon " << x1;
                }
                else if (is12Greater13(nhoX, lonX) == 1)
                {
                    cout << "So luong node nho hon " << x1 << " nho hon so luong";
                    cout << " node lon hon " << x1;
                }
                else
                {
                    cout << "So luong node nho hon " << x1 << " bang so luong";
                    cout << " node lon hon " << x1;
                }
                cout << "\n--------------------------------";
                cout << endl;
                break;
            }
            case 14:
            {
                countOddEvent(main.root, demChan, demLe);
                cout << "So luong node chan la: " << demChan;
                cout << "\nSo luong node le la: " << demLe;
                cout << endl;
                if (is12Greater13(demChan, demLe) == 0)
                {
                    cout << "So luong node chan lon hon so luong node le";
                }
                else if (is12Greater13(nhoX, lonX) == 1)
                {
                    cout << "So luong node chan nho hon so luong node le";
                }
                else
                {
                    cout << "So luong node chan bang so luong node le";
                }
                cout << "\n--------------------------------";
                cout << endl;
                break;
            }
            case 15:
            {
                sumAllNode(main.root, sumNode);
                cout << "Tong cac node trong cay: " << sumNode; 
                cout << "\n--------------------------------";
                cout << endl;
                break;
            }
            case 16:
            {
                sumEvenNode(main.root, sumChan);
                cout << "Tong cac node chan trong cay: " << sumChan;
                cout << "\n--------------------------------";
                cout << endl;
                break;
            }
            case 17:
            {
                sumOddNode(main.root, sumLe);
                cout << "Tong cac node le trong cay: " << sumLe;
                cout << "\n--------------------------------";
                cout << endl;
                break;
            }
            case 18:
            {
                if (is12Greater13(sumChan, sumLe) == 0)
                {
                    cout << "Tong cac node chan lon hon tong cac node le";
                }
                else if (is12Greater13(nhoX, lonX) == 1)
                {
                    cout << "Tong cac node chan nho hon tong cac node le";
                }
                else
                {
                    cout << "Tong cac node chan bang tong cac node le";
                }
                cout << "\n--------------------------------";
                cout << endl;
                break;
            }
            case 19:
            {
                findMax(main.root, max);
                findMin(main.root, min);
                cout << "Node co gia tri lon nhat la: " << max;
                cout << "\nNode co gia tri nho nhat la: " << min;
                cout << "\n--------------------------------";
                cout << endl;
                break;
            }
        }
    }
    return 0;
}