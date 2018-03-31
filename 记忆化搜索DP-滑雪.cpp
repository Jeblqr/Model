#include<bits/stdc++.h>
using namespace std;
int dx[]={0,-1,0,1,0},dy[]={0,0,-1,0,1},a[1000][1000],f[1000][1000],n,m;
int search(int x,int y);
int main() 
{
	cin>>n>>m;
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++)
			cin>>a[i][j];
	int t=-1;
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++)
			t=max(t,search(i,j));
	cout<<t;
	return 0;
}
int search(int x,int y)
{
	int t=1;
	if (f[x][y]>0) return f[x][y];
	for (int i=1;i<=4;i++)
	{
		int ddx=x+dx[i],ddy=y+dy[i];
		if (ddx>=1&&ddx<=n&&ddy>=1&&ddy<=m&&a[ddx][ddy]>a[x][y])
		{
			t=max(t,search(ddx,ddy)+1);
		}
	}
	f[x][y]=t;
	return t;
}
