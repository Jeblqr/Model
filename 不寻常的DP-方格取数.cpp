#include<bits/stdc++.h>
#define max(a,b,c,d) max(max(a,b),max(c,d))
using namespace std;
int n,f[100][100][100][100],a[1000][1000],x,y,z;
int main()
{
	cin>>n>>x>>y>>z;
	while (x&&y&&z)
	{
		a[x][y]=z;
		cin>>x>>y>>z;
	}
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++)
			for (int h=1;h<=n;h++)
				for (int k=1;k<=n;k++)
				{
					f[i][j][h][k]=max(f[i-1][j][h-1][k],f[i][j-1][h][k-1],f[i][j-1][h-1][k],f[i-1][j][h][k-1])+a[i][j];
					if (i!=h&&j!=k) f[i][j][h][k]+=a[h][k];
				}
	cout<<f[n][n][n][n];
	return 0;
}
