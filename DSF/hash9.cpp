#include<iostream>
#include<cstring>
using namespace std;
class keyval
{
	friend class hashing;
	char word[30];
	char meaning[100];
};
class hashing
{
	int *flag,size,constant,no,*ref;
	keyval *a;
	public:
		hashing()
		{
			constant=0;
			no=0;
		}
		int hashfn(char a[])
		{
			int c,sum=0,mod;
			c=strlen(a);
			for(int i=0;i<c;i++)
			{
				sum=sum+a[i];
			}
			mod=sum%size;
			return mod;
		}
		void create()
		{
			cout<<"Enter the size"<<endl;
			cin>>size;
			a=new keyval[size];
			flag=new int[size];
			ref=new int[size];
			constant=1;
			for(int i=0;i<size;i++)
			{
				flag[i]=0;
				ref[i]=-1;
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
		void insert(char in[], char g[100])
		{
		
			int rem,sie=30;
			cout<<"Enter the word"<<endl;
			cin>>in;
			cout<<"Enter its meaning"<<endl;
			cin>>g;
			
			rem=hashfn(in);
			if(flag[rem]==0)
			{
			strcpy(a[rem].word,in);
			strcpy(a[rem].meaning,g);
				flag[rem]=1;
				no++;
			}
			else if(flag[rem]==1 && rem<size-1)
			{
				int i=0,trem;
				
				while(ref[rem]!=-1)
				{
					rem=ref[rem];
				}
				trem=rem;
				while(flag[trem]!=0 && i<size)
				{
				
				trem=hashfn(in)+i;
				i++;	
				}
				strcpy(a[trem].word,in);
			strcpy(a[trem].meaning,g);
				flag[trem]=1;
				if(rem!=trem)
				{
				ref[rem]=trem;
			}
				no++;
			
	}
	else if(flag[rem]==1 && rem==size-1)
	{
		int i=0,trem,j=0;
				
				while(ref[rem]!=-1)
				{
					rem=j;
					j++;
				}
				trem=rem;
				while(flag[trem]!=0 && i<size)
				{
				
				trem=hashfn(in)+i;
				i++;	
				}
				strcpy(a[trem].word,in);
			strcpy(a[trem].meaning,g);
				flag[rem]=1;
				if(rem!=trem)
				{
				ref[rem]=trem;
			}
				no++;
	}
}
		void make()
		{
			int data;
			char s1[30],mean[100];
			
			if(constant==0)
			{
				cout<<"Hash table not created"<<endl;
			}
			else
			{
			if(no!=size)
			{
			insert(s1,mean);
		}
		else
		{
			cout<<"Overflow"<<endl;
		}
	}
		
	}
		int search(char key[])
		{
			
			int finder,i=0;
			finder=hashfn(key);
			while(i<=size)
			{
			if(strcmp(a[finder].word,key)==0)
			{
				return finder;
			}
			else
			{
					finder=hashfn(key)+i;
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
				cout<<"Word:"<<a[i].word<<endl;
				cout<<"Meaning: "<<a[i].meaning<<endl;
				cout<<ref[i]<<endl;
		}
			}
		}
	}
	}
	void find()
		{
			char key[30];
			int loc;
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
			cout<<"Enter word to search"<<endl;
			cin>>key;
			loc=search(key);
			if(loc==-1)
			{
				cout<<"Word not present"<<endl;
			}
			else
			{
			cout<<"Location no "<<loc<<" is"<<endl;
				cout<<"Word:"<<a[loc].word<<endl;
				cout<<"Meaning: "<<a[loc].meaning<<endl;
				cout<<ref[loc]<<endl;
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
			char key[30];
			int loc,nkey;
			{
			 if(empty()==1)
			{
				cout<<"Hash table empty"<<endl;
			}
			else
			{
			cout<<"Enter word to be deleted"<<endl;
			cin>>key;
			loc=search(key);
			if(loc==-1)
			{
				cout<<"Word not present"<<endl;
			}
			else
			{
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
cout<<"4.Enter 4 for  finding key of an entry"<<endl;
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
		h.find();		
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
