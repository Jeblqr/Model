#include<bits/stdc++.h>
using namespace std;
int a[10000],b[10000],c[10000];
void init()
{
	string s;
	cin>>s;
	a[0]=s.length();
	for (int i=1;i<=a[0];i++) 
		a[i]=s[a[0]-i]-'0';
	cin>>s;
	b[0]=s.length();
	for (int i=1;i<=b[0];i++) 
		b[i]=s[b[0]-i]-'0';
}
void add()
{
	int i=1,x=0;
	while (a[0]>=i||b[0]>=i)
	{
		c[i]=a[i]+b[i]+x;
		x=c[i]/10;
		c[i]%=10;
		i++;
	}
	c[i]=x;
	while (c[i]==0) i--;
	c[0]=i;
}
int main()
{
	init();
	add();
	for (int i=c[0];i>=1;i--)
		cout<<c[i];
	return 0;
}
