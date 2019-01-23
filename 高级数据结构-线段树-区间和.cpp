#include<iostream>
#include<cstdio>
#define int long long
#define L (root<<1)
#define MID ((l+r)>>1)
#define R (root<<1|1) 
#define lowbit(x) x&-x
using namespace std;

struct Node
{
	int val,tag;
}node[400001];
int a[100001];
void push(int root,int l,int r,int k)
{
	node[root].val+=k*(r-l+1);
	node[root].tag+=k;
}
void push(int root,int l,int r)
{
	push(L,l,MID,node[root].tag);
	push(R,MID+1,r,node[root].tag);
	node[root].tag=0;
}
void build(int root,int l,int r)
{
	node[root].tag=0;
	if (l==r)
	{
		node[root].val=a[l];
		return;
	}
	build(L,l,MID);
	build(R,MID+1,r);
	node[root].val=node[L].val+node[R].val;
}
void add(int root,int l,int r,int a,int b,int k)
{
	if (l>=a&&r<=b)
	{
		node[root].val+=k*(r-l+1);
		node[root].tag+=k;
		return;
	} 
	push(root,l,r);
	if (MID>=a)
		add(L,l,MID,a,b,k);
	if (MID<b)
		add(R,MID+1,r,a,b,k);
	node[root].val=node[L].val+node[R].val;
}
int query(int root,int l,int r,int a,int b)
{
	if (l>=a&&b>=r)
		return node[root].val;
	push(root,l,r);
	int ans=0;
	if (MID>=a)
		ans+=query(L,l,MID,a,b);
	if (MID<b)
		ans+=query(R,MID+1,r,a,b);
	return ans;
}
signed main()
{
	int n,m;
	cin>>n>>m;
	for (int i=1,k;i<=n;i++)
		cin>>a[i];
	build(1,1,n);
	for (int i=1;i<=m;i++)
	{
		char op;
		cin>>op;
		if (op=='C')
		{
			int a,b,c;
			cin>>a>>b>>c;
			add(1,1,n,a,b,c);
		}
		else
		{
			int a,b;
			cin>>a>>b;
			cout<<query(1,1,n,a,b)<<endl;
		}
	}
	return 0;
}
