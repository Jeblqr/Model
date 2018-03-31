#include<bits/stdc++.h>
using namespace std;
int f,v,k,a[1000][1000],b[1000][1000],c[1000][1000],d[1000];
int main() 
{
	cin>>f>>v;
	for (int i=1;i<=f;i++)
		for (int j=1;j<=v;j++) 
			cin>>a[i][j];
	memset(b,128,sizeof(b));
	for (int i=1;i<=v-f+1;i++) 
		b[1][i]=a[1][i];
	for (int i=1;i<=f;i++)
		for (int j=1;j<=v-f+i;j++)
			for (k=1;k<=j-1;k++)
			{
				if (b[i-1][k]+a[i][j]>b[i][j])
				{
					b[i][j]=b[i-1][k]+a[i][j];
					c[i][j]=k;
				}
			}
	int dmax=-2147483647;
	for (int i=f;i<=v;i++)
	{
		if (b[f][i]>dmax)
		{
			dmax=b[f][i];
			k=i;
		}
	}
	cout<<dmax<<endl;
	for (int i=1;i<=f;i++)
	{
		d[i]=k;
		k=c[f-i+1][k];
	}
	for (int i=f;i>=2;i--)
		cout<<d[i]<<' ';
	cout<<d[1]<<endl;
	return 0;
}
