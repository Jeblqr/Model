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
void ride()
{
	
	for (int i=1;i<=a[0];i++)
	{
		int x=0;
		for (int j=1;j<=b[0];j++)
		{
			c[i+j-1]=a[i]*b[j]+x+c[i+j-1];
			x=c[i+j-1]/10;
			c[i+j-1]%=10;
		}
		c[i+b[0]]=x;
	}
	int g=a[0]+b[0];
	while (c[g]==0&&g>1)
		g--;
	c[0]=g;
}
int main()
{
	init();
	ride();
	for (int i=c[0];i>=1;i--)
		cout<<c[i];
	return 0;
}
