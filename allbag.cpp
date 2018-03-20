#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,m,f[1000],c[1000],w[1000],g[1000];
	cin>>m>>n;
	for (int i=1;i<=n;i++) 
	{
		cin>>w[i]>>c[i]>>g[i];
		if (g[i]==0) g[i]=10000;
	}
	for (int i=1;i<=n;i++)
		for (int j=m;j>=w[i];j--)
			for (int k=1;k<=g[i];k++)
				if (j-w[i]*k>=0&&f[j]<f[j-w[i]*k]+c[i]*k) f[j]=f[j-w[i]*k]+c[i]*k;
	cout<<f[m];
	return 0;
}
