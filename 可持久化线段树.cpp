#include<bits/stdc++.h>
using namespace std;


//------------------------------------------------
class PersistentSegmentTree
{
	#define MaxN 100000
	#define MaxM 10000
	struct SegmentTree
	{
		int l,r;
		int dat;
	};
	SegmentTree tree[4*MaxN];
	int tot,root[MaxM];
	PersistentSegmentTree(){};
	void pushUp(int now,int l,int r);// written by yourself
	int build(int l,int r,int *a);
	int insert(int now,int l,int r,int x,int val);
};

int PersistentSegmentTree::build(int l,int r,int *a)
{
	int p=++tot;
	if (l==r)
	{
		tree[p].dat=a[l];
		return p;
	}
	int mid=(l+r)/2;
	tree[p].l=build(l,mid,a);
	tree[p].r=build(mid+1,r,a);
	pushUp(p,tree[p].l,tree[p].r);
	return p;
	// in main()
	// T.root[0]=build(1,n,a);
}

int PersistentSegmentTree::insert(int now,int l,int r,int x,int val)
{
	int p=++tot;
	tree[p]=tree[now];
	if (l==r)
	{
		tree[p].dat=val;
		return p;
	}
	int mid=(l+r)/2;
	if (x<=mid)
		tree[p].l=insert(tree[now].l,l,mid,x,val);
	else
		tree[p].r=insert(tree[now].r,mid+1,r,x,val);
	pushUp(p,tree[p].l,tree[p].r);
	return p;
	// in main()
	// root[i]=insert(root[i-1],1,n,x,val)
}
//------------------------------------------------

class T: private PersistentSegmentTree
{
	void pushUp(int now,int l,int r)
	{
		tree[now].dat=max(tree[l].dat,tree[r].dat);
	}
};

int main()
{
	return 0;
}
