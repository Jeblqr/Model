#include<bits/stdc++.h>
using namespace std;
int a[10000],b[10000],c[10000];
void init()
{
	string s1,s2;
	cin>>s1>>s2;
	if ((s1.length()==s2.length()&&s1<s2)||s1.length()<s2.length())
		swap(s1,s2),cout<<'-';
	a[0]=s1.length();
	b[0]=s2.length();
	for (int i=1;i<=a[0];i++) 
		a[a[0]-i+1]=s1[i-1]-'0';
	for (int i=1;i<=b[0];i++) 
		b[b[0]-i+1]=s2[i-1]-'0';
}
void sub()
{
	int i=1;
	while (i<=a[0])
	{
		if (a[i]<b[i])
		{
			a[i]+=10;
			a[i+1]--;
		}
		c[i]=a[i]-b[i];
		i++;
	}
	for (;;i--) 
		if (a[i]!=0||i==1)
			break;
	c[0]=i;
}
int main()
{
	init();
	sub();
	if (c[0]==0) cout<<0;
	else
	{
		for (int i=c[0];i>=1;i--)
			cout<<c[i];
	}
	return 0;
}
