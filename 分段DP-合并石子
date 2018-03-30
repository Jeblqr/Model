#include<bits/stdc++.h>
using namespace std;
int n,a[100000],f[10000][10000],s[1000000];
int main()
{
	cin>>n;
	for (int i=1;i<=n;i++)
		cin>>a[i];
	s[1]=a[1];
	for (int i=2;i<=n;i++)
		s[i]=s[i-1]+a[i];
	memset(f,127/3,sizeof(f));
	for (int i=1;i<=n;i++)
		f[i][i]=0;
	for (int i=2;i<=n;i++)
		for (int l=1;l<=n-i+1;l++)
		{
			int r=i+l-1;
			for (int k=l;k<=r-1;k++)
				f[l][r]=min(f[l][r],f[l][k]+f[k+1][r]+s[r]-s[l-1]);
		}
	cout<<f[1][n];
	return 0;
}
