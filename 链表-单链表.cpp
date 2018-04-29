#include<iostream>
using namespace std;
class node
{
	public:
		int date;
		node *next;
	node();
}*head,*p,*q,*tail;
node::node()
{
	date=0;
	next=NULL;
}
void init()
{
	head=q=p=tail=new node;
	cout<<"creat "<<p<<endl;
}
void creat_list(int n)
{
	p=new node;
	tail=p;
	q->next=p;
	p->date=n;
	q=p;
	cout<<"creat "<<p<<endl;
}
void print()
{
	node *t=head;
	while (t->next!=NULL)
	{
		t=t->next;
		cout<<t->date<<' ';
	}
	cout<<endl;
}
void remove_list()
{
	node *t=head;
	while (t->next!=NULL)
	{
		p=t;
		t=t->next;
		delete p;
		cout<<"delete "<<p<<endl;
	}
	p=t;
	t=t->next;
	delete p;
	cout<<"delete "<<p<<endl;
}
int main()
{
	init(); 
	int n;
	cin>>n;
	for (int i=1;i<=n;i++)
	{
		int l;
		cin>>l;
		creat_list(l);
	}
	print();
	cin.get();
	cin.get();
	remove_list();
	cin.get();
	cin.get();
	return 0;
}
