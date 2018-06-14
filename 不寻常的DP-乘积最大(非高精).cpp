#include<bits/stdc++.h>
using namespace std;
int r,n,a[1000][1000],f[10000][10000];
long long s;
int main()
{
	cin>>n>>r;
	cin>>s;
	for (int i=n;i>=1;i--)
		a[i][i]=s%10,s/=10;
	for (int i=1;i<=n;i++)
		for (int j=i+1;j<=n;j++)
			a[i][j]=a[i][j-1]*10+a[j][j];
	for (int i=1;i<=n;i++)
		f[i][0]=a[1][i];
	for (int k=1;k<=r;k++)
		for (int i=k+1;i<=n;i++)
			for (int j=k;j<i;j++)
				f[i][k]=max(f[i][k],f[j][k-1]*a[j+1][i]);
	cout<<f[n][r];
	return 0;
}
