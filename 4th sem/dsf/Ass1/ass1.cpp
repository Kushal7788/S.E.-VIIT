#include<iostream>
#include<string.h>
using namespace std;


class treeNode
{
	friend class stack;
	public:
	char exp;
	treeNode *lchild,*rchild;
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
		top=NULL;
	}
	
	void push(treeNode *n);
	treeNode *pop();
	void inorder(treeNode *n);
        void preorder(treeNode *n);
        void postorder(treeNode *n);
};

void stack::push(treeNode *n)
{
	node *nn= new node;
	nn->data=n;
	nn->next=NULL;
	if(top==NULL)
	top=nn;
	else
	{
            nn->next=top;
            top=nn;
		
	}
}

treeNode* stack::pop()
{
	if(top==NULL)
	cout<<"List Is empty\n";
	else
	{
		node *temp;
		temp=top;
		top=top->next;
		return temp->data; 
	}
}

void stack::inorder(treeNode *n)
{
	if(n)
	{
		inorder(n->lchild);
		cout<<n->exp;
		inorder(n->rchild);
	}
        
}

void stack::preorder(treeNode *n)
{
	if(n)
	{
                cout<<n->exp;
		preorder(n->lchild);
		preorder(n->rchild);
	}
        
}
void stack::postorder(treeNode *n)
{
	if(n)
	{
		postorder(n->lchild);
		postorder(n->rchild);
                cout<<n->exp;
	}
        
}


int main()
{	
	treeNode *tn,*poptn1,*poptn2;
	
	poptn1 = new treeNode;
	poptn2 = new treeNode;
	stack s;
	char a;
	string st;
	int choice;
	do
	{
	cout<<"Enter 1 to enter the string\n";
	cout<<"Enter 2 to covert it into tree\n";
	cout<<"Enter 3 to display inorder\n";
	cout<<"Enter 4 to display postorder\n";
	cout<<"Enter 5 to display preorder\n";
	cout<<"Enter 6 to exit\n";
	cin>>choice;
	switch(choice)
	{
	   case 1:cin>>st;
	   	break;
	case 2:int len;
		len = st.size();
	for (int i=0;i<len;i++)
	{
            tn = new treeNode;
		a=st[i];
		if((a>64&&a<91)||(a>96&&a<123))
		{
			tn->exp=a;
			tn->lchild=NULL;
			tn->rchild=NULL;
			s.push(tn);
			
		}
		else
		{
			tn->exp=a;
			poptn2=s.pop();
			poptn1=s.pop();
			tn->lchild=poptn1;
			tn->rchild=poptn2;
			s.push(tn);
		}	
	}
	break;
	case 3: tn=s.pop();
		s.inorder(tn);
                s.push(tn);
		break;
        case 4: tn=s.pop();
		s.postorder(tn);
                s.push(tn);
		break;
        case 5: tn=s.pop();
		s.preorder(tn);
                s.push(tn);
		break;        
	case 6:cout<<"Exit\n";
		break;
	default:cout<<"Invalid Input\n";
		break;
	}
	}while(choice!=6);
	return 0;
}