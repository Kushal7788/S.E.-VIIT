#include <string.h>
#include <iostream>
using namespace std;

class treeNode
{
	friend class stack;

  public:
	char exp;
	treeNode *lchild, *rchild;
};

class node
{
	friend class stack;
	treeNode *data;
	node *next;
};

class stack
{
  private:
	node *top;

  public:
	stack()
	{
		top = NULL;
	}

	void push(treeNode *n);
	treeNode *pop();
	void inorder(treeNode *n);
	void preorder(treeNode *n);
	void postorder(treeNode *n);
	bool isempty();
};

void stack::push(treeNode *n)
{
	node *nn = new node;
	nn->data = n;
	nn->next = NULL;
	if (top == NULL)
		top = nn;
	else
	{
		nn->next = top;
		top = nn;
	}
}

treeNode *stack::pop()
{
	if (top == NULL)
		cout << "List Is empty\n";
	else
	{
		node *temp;
		temp = top;
		top = top->next;
		return temp->data;
	}
}
bool stack::isempty()
{
	if (top == NULL)
		return true;
	else
		return false;
}
void stack::inorder(treeNode *root)
{
	stack st;
	treeNode *c = root;
	while (c != NULL || st.isempty() == false)
	{
		while (c != NULL)
		{
			st.push(c);
			c = c->lchild;
		}

		c = st.pop();
		cout << c->exp;
		c = c->rchild;
	}
}

void stack::preorder(treeNode *root)
{
	stack st;
	treeNode *c = root;
	st.push(c);
	while (st.isempty() == false)
	{
		c = st.pop();
		cout << c->exp;
		if (c->rchild != NULL)
			st.push(c->rchild);
		if (c->lchild != NULL)
			st.push(c->lchild);
	}
}
void stack::postorder(treeNode *n)
{
	stack st, t;
	treeNode *c = n;
	st.push(c);
	while (st.isempty() == false)
	{
		c = st.pop();
		t.push(c);
		if (c->lchild != NULL)
			st.push(c->lchild);
		if (c->rchild != NULL)
			st.push(c->rchild);
	}
	while (t.isempty() == false)
	{
		c = t.pop();
		cout << c->exp;
	}
}

int main()
{
	treeNode *tn, *poptn1, *poptn2;

	poptn1 = new treeNode;
	poptn2 = new treeNode;
	stack s;
	char a;
	string st;
	int choice;
	do
	{
		cout << "Enter 1 to enter the string\n";
		cout << "Enter 2 to covert it into tree\n";
		cout << "Enter 3 to display inorder\n";
		cout << "Enter 4 to display postorder\n";
		cout << "Enter 5 to display preorder\n";
		cout << "Enter 6 to exit\n";
		cin >> choice;
		switch (choice)
		{
		case 1:
			cin >> st;
			break;
		case 2:
			int len;
			len = st.size();
			for (int i = 0; i < len; i++)
			{
				tn = new treeNode;
				a = st[i];
				if ((a > 64 && a < 91) || (a > 96 && a < 123))
				{
					tn->exp = a;
					tn->lchild = NULL;
					tn->rchild = NULL;
					s.push(tn);
				}
				else
				{
					tn->exp = a;
					poptn2 = s.pop();
					poptn1 = s.pop();
					tn->lchild = poptn1;
					tn->rchild = poptn2;
					s.push(tn);
				}
			}
			break;
		case 3:
			tn = s.pop();
			s.inorder(tn);
			s.push(tn);
			break;
		case 4:
			tn = s.pop();
			s.postorder(tn);
			s.push(tn);
			break;
		case 5:
			tn = s.pop();
			s.preorder(tn);
			s.push(tn);
			break;
		case 6:
			cout << "Exit\n";
			break;
		default:
			cout << "Invalid Input\n";
			break;
		}
	} while (choice != 6);
	return 0;
}