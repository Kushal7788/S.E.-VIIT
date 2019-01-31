#include <string.h>
#include <iostream>
using namespace std;

class treeNode
{
    friend class bst;

  public:
    int data;
    treeNode *lchild, *rchild;
    bool lthread, rthread;
};

class bst
{
  private:
    treeNode *head;

  public:
    bst()
    {
        head = NULL;
    }
    void create(int d);
    void inorder(treeNode *root);
    void preorder(treeNode *root);
    treeNode *root();
};

void bst::create(int d)
{
    treeNode *n = new treeNode;
    n->data = d;
    n->lchild = n->rchild = NULL;
    n->lthread = n->rthread = true;

    if (head == NULL)
        head = n;
    else
    {
        treeNode *parent = head;
        treeNode *child = parent;
        while (child != NULL)
        {
            parent = child;
            if (d > parent->data)
                child = parent->rchild;
            if (d < parent->data)
                child = parent->lchild;
        }
        if (d > parent->data)
            parent->rchild = n;
        else
            parent->lchild = n;
    }
}
treeNode *bst::root()
{
    return head;
}
void bst::inorder(treeNode *root)
{
    if (root != NULL)
    {
        inorder(root->lchild);
        cout << root->data;
        inorder(root->rchild);
    }
}
void bst::preorder(treeNode *root)
{
    if (root != NULL)
    {
        cout << root->data;
        preorder(root->lchild);
        preorder(root->rchild);
    }
}

int main()
{
    bst ob;
    treeNode *root;
    int ch;
    do
    {
        cout << "Enter 1 to add the element to the tree\n";
        cout << "Enter 2 to display inorder\n";
        cout << "Enter 3 to display preorder\n";
        cout << "Enter 5 to exit\n";
        cin >> ch;
        switch (ch)
        {
        case 1:
            int d;
            cout << "Enter data to be entered\n";
            cin >> d;
            ob.create(d);
            break;
        case 2:
            root = ob.root();
            cout << "The tree is as follow\n";
            ob.inorder(root);
            break;
        case 3:
            root = ob.root();
            cout << "The tree is as follow\n";
            ob.preorder(root);
            break;
        case 5:
            cout << "Exit\n";
            break;
        default:
            cout << "Invalid input\n";
            break;
        }
    } while (ch != 5);

    return 0;
}
