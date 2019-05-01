#include<iostream>
#include<cstring>
using namespace std;
class keyval
{
	friend class hashing;
	char name[30];
	int phoneno;
};
class hashing
{
	int *flag,size,constant,no;
	keyval *a;
	public:
		hashing()
		{
			constant=0;
			no=0;
		}
		int hashfn(int d,int b)
		{
			int c;
			c=d%b;
			return c;
		}
		void create()
		{
			cout<<"Enter the size of table you want"<<endl;
			cin>>size;
			a=new keyval[size];
			flag=new int[size];
			constant=1;
			for(int i=0;i<size;i++)
			{
				flag[i]=0;
			}
		}
		int empty()
		{
			int a;
			for(int i=0;i<size;i++)
			{
				if(flag[i]==0)
				{
					a=1;
				}
				else
				{
					a=0;
					break;
				}
			}
			if(a==1)
			{
				return 1;
			}
			else if(a==0)
			{
				return 0;
			}
		}
		void insert(int data, char g[])
		{
		
			int rem,trem,tempp;
			char temp[30];
			cout<<"Enter the name"<<endl;
			cin>>g;
			cout<<"Enter the phone no"<<endl;
			cin>>data;
			
			rem=hashfn(data,size);
			trem=hashfn(a[rem].phoneno,size);
			if(flag[rem]==0)
			{
			strcpy(a[rem].name,g);
			a[rem].phoneno=data;
				flag[rem]=1;
				no++;
			}
			else if(flag[rem]==1 && rem==trem )
			{
				int i=0;

				while(flag[rem]!=0)
				{
				rem=hashfn(data+i,size);
				i++;	
				}
				if(search(data)==-1)
				{
			strcpy(a[rem].name,g);
			a[rem].phoneno=data;
				flag[rem]=1;
				no++;
			}
			}
			else if(flag[rem]==1 && rem!=trem)
			{
				int i=1;
			strcpy(temp,a[rem].name);
			tempp=a[rem].phoneno;
			strcpy(a[rem].name,g);
			a[rem].phoneno=data;
				flag[rem]=1;
				no++;
				trem=hashfn(tempp,size);
					while(flag[trem]!=0)
				{
				trem=hashfn(tempp+i,size);
				i++;	
				}
			strcpy(a[trem].name,temp);
			a[trem].phoneno=tempp;
				flag[trem]=1;
			}
}
		void make()
		{
			int data;
			char s1[20],rep;
			
			if(constant==0)
			{
				cout<<"Hash table not created"<<endl;
			}
			else
			{
			if(no!=size)
			{
			insert(data,s1);
		}
		else
		{
			cout<<"Overflow"<<endl;
		}
	}
		
	}
		int search(int key)
		{
			
			int finder,i=0;
			finder=hashfn(key,size);
			while(i<=size)
			{
			if(a[finder].phoneno==key)
			{
				return 1;
			}
			else
			{
					finder=hashfn(key+i,size);
					i++;
				}
			}
			return (-1);
		}
		void display()
		{
			if(constant==0)
			{
				cout<<"Hash table not created"<<endl;
			}
			else
			{
			 if(empty()==1)
			{
				cout<<"Hash table empty"<<endl;
			}
			else
			{
			cout<<"Hash table is"<<endl;
				for(int i=0;i<size;i++)
			{
				if(flag[i]==1)
				{
					cout<<"Location no "<<i<<" is"<<endl;
				cout<<"Name:"<<a[i].name<<endl;
				cout<<"Phone no: "<<a[i].phoneno<<endl;
		}
			}
		}
	}
	}
		void update()
		{
			int key,loc,nkey;
			if(constant==0)
			{
				cout<<"Hash table not created"<<endl;
			}
			
			else
			{
			 if(empty()==1)
			{
				cout<<"Hash table empty"<<endl;
			}
			else
			{
			cout<<"Enter old phone no"<<endl;
			cin>>key;
			loc=search(key);
			if(loc==-1)
			{
				cout<<"Phone no not present"<<endl;
			}
			else
			{
				cout<<"Enter new phone"<<endl;
				cin>>nkey;
				a[loc].phoneno=nkey;
			}
	}
}
}
	void remove()
	{
		if(constant==0)
			{
				cout<<"Hash table not created"<<endl;
			}
			else
			{
			int key,loc,nkey;
			{
			 if(empty()==1)
			{
				cout<<"Hash table empty"<<endl;
			}
			else
			{
			cout<<"Enter phone no to be deleted"<<endl;
			cin>>key;
			loc=search(key);
			if(loc==-1)
			{
				cout<<"Phone no not present"<<endl;
			}
			else
			{
				a[loc].phoneno=0;
				flag[loc]=0;
		}
	}
}
}
}
};
int main()
{
cout<<"WELCOME TO HASH TABLES"<<endl;
int ch;
char repeat;
hashing h;
do
{
cout<<"1.Enter 1 for creating the table"<<endl;
cout<<"2.Enter 2 for inserting values.ONLY UNIQUE KEYS ALLOWED"<<endl;
cout<<"3.Enter 3 for displaying the table"<<endl;
cout<<"4.Enter 4 for  updating key of an entry"<<endl;
cout<<"5.Enter 5 for deleting an entry"<<endl;
cout<<"Enter your choice"<<endl;
cin>>ch;
switch(ch)
{
	case 1:
     	h.create();
		 break;	
	case 2:
    	h.make();
		break;
	case 3:
		h.display();
		break;
	case 4:
		h.update();		
		break;
	case 5:

		h.remove();
		break;
	default:
		cout<<"Invalid choice"<<endl;
		break;
		
	}
	cout<<"Do you want to repeat any other operation"<<endl;
	cin>>repeat;	
}
while(repeat=='y' ||repeat=='Y');
	return 0;
}
