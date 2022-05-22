#include<iostream>
using namespace std;
struct Node
{
    int info;
    Node *left;
    Node *right;
};
typedef Node *Tree;
void emptyTree(Tree &t)
{
    t == NULL;
}
Node *createNode(int x)
{
    Node *p = new Node;
    p->info = x;
    p->left = p->right = NULL;
    return p;
}
void NLR(Tree &t)
{
    if (t != NULL)
    {
        cout << t->info << " ";
        NLR(t->left);
        NLR(t->right);
    }
}
void LNR(Tree &t)
{
    if (t != NULL)
    {   
        LNR(t->left);
        cout << t->info << "";
        LNR(t->right);
    }
}
void LRN(Tree &t)
{
    if (t != NULL)
    {
        LNR(t->left);
        LNR(t->right);
        cout << t->info << " ";
    }
}
int insertNode(Tree &t, int x)
{
    if (t)
    {
        if (t->info == x)
        {
            return 0;
        }
        if (t->info > x)
        {
            return insertNode(t->left, x);
        }
        else
        {
            return insertNode(t->right, x);
        }
    }
    t = new Node;
    t->info = x;
    t->left = t->right = NULL;
    return 1;
}
int main()
{
    Tree t;
    emptyTree(t);
    insertNode(t, 9);
    insertNode(t, 5);
    insertNode(t, 14);
    insertNode(t, 4);
    insertNode(t, 8);
    insertNode(t, 3);
    insertNode(t, 6);
    insertNode(t, 12);
    insertNode(t, 13);
    NLR(t);
    cout << endl;
    LNR(t);
    cout << endl;
    LRN(t);
    return 0;
}