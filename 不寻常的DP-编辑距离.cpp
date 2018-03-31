#include<bits/stdc++.h>
using namespace std;
int n,m,f[10000][10000];
string a,b;
int main()
{
	cin>>a>>b;
	n=a.length();
	m=b.length();
	for (int i=1;i<=n;i++) f[i][0]=i;
	for (int i=1;i<=m;i++) f[0][i]=i;
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++)
			if (a[i-1]==b[j-1])
				f[i][j]=f[i-1][j-1];
			else
				f[i][j]=min(min(f[i-1][j-1]+1,f[i-1][j]+1),f[i][j-1]+1);
	cout<<f[n][m];
	return 0;
}
