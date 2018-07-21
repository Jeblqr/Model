#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<string>
#include<sstream>
#define Max 110000
using namespace std;

class HAA
{
	string as,bs;
	int a[Max],b[Max];
	public:
		int c[Max];
		HAA();
		void Add();
		void Ride();
		void Sub();
		void ga(int k[]);
		void gb(int k[]);
		void print();
		
};
HAA::HAA()
{
	cin>>as>>bs;
	a[0]=as.size(),b[0]=bs.size();
	as=' '+as;
	bs=' '+bs;
	for (int i=a[0];i>=1;i--)
		a[a[0]-i+1]=as[i]-'0';
	for (int i=b[0];i>=1;i--)
		b[b[0]-i+1]=bs[i]-'0';
}
void HAA::Add()
{
	memset(c,0,sizeof c);
	c[0]=max(a[0],b[0]);
	c[0]++;
	for (int i=1;i<=c[0];i++)
	{
		c[i]+=a[i]+b[i];
		c[i+1]=c[i]/10;
		c[i]%=10;
	}
	while (!c[c[0]]&&c[0])
		c[0]--;
}
void HAA::Ride()
{
	memset(c,0,sizeof c);
	c[0]=a[0]+b[0];
	for (int i=1;i<=a[0];i++)
	{
		int x=0;
		for (int j=1;j<=b[0];j++)
		{
			c[i+j-1]+=a[i]*b[j]+x;
			x=c[i+j-1]/10;
			c[i+j-1]%=10;
		}
		c[i+b[0]]=x;
	}
	while (!c[c[0]]&&c[0])
		c[0]--;
}
void HAA::print()
{
	if (c[0]==0)
	{
		cout<<0;
		return;
	}
	for (int i=c[0];i>=1;i--)
		cout<<c[i];
}

int main()
{
	HAA k;
	k.Add();
	k.print();
	return 0;
}
