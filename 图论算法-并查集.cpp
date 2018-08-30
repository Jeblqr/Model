#include<bits/stdc++.h>
using namespace std;
int ancestors[11000000],n,m,ans;
void init();
void find_answer();
int find_ancestors(int kid);
void print();
int main()
{
	init();
	find_answer();
	print();
	return 0;
}
void init()
{
	cin>>n>>m;
	for (int i=1;i<=n;i++) 
		ancestors[i]=i;
}
void find_answer()
{
	for (int i=1;i<=m;i++)
	{
		int x,y,fx,fy;
		cin>>x>>y;
		fx=find_ancestors(x);
		fy=find_ancestors(y);
		if (fx!=fy)
			ancestors[fx]=fy;
	}
	for (int i=1;i<=n;i++) 
		if (ancestors[i]==i)
			ans++;
}
int find_ancestors(int kid)
{
	if (ancestors[kid]!=kid) ancestors[kid]=find_ancestors(ancestors[kid]);
	return ancestors[kid];
}
void print()
{
	cout<<ans;
}
