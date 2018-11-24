#include<bits/stdc++.h>
using namespace std;

class FHQ_Treap
{
	int ROOT,seed,len;
	struct Node
	{
		int val,d,size,x,y;
	};
	Node node[1000000];
	FHQ_Treap():seed(233333){};
	int Rand();
	int New(int val);
	void Update(int x);
	void SplitByValue(int root,int k,int &x,int &y);
	void SplitByRank(int root,int k,int &x,int &y);
	int Merge(int x,int y);
	public:
		void Insert(int val);
		void Delete(int val);
		int Rank(int val);
		int Find_K_Th(int k);
		int Find_K_Th(int root,int k);
		int Pre(int val);
		int Nxt(int val);
		int Add(int l,int r,int delta);
};

int FHQ_Treap::Rand()
{
	return (seed=(seed*seed%2147483647+1476)%2147483647);
}

int FHQ_Treap::New(int val)
{
	len++;
	node[len]=Node{val,Rand(),1,0,0};
	return len;
}

void FHQ_Treap::Update(int x)
{
	node[x].size=node[node[x].x].size+node[node[x].y].size+1;
}

void FHQ_Treap::SplitByValue(int root,int k,int &x,int &y)
{
	if (root==0)
	{
		x=y=0;
		return ;
	}
	if (node[root].val<=k)
	{
		x=root;
		SplitByValue(node[root].y,k,node[root].y,y);
	}
	else
	{
		y=root;
		SplitByValue(node[root].x,k,x,node[root].x);
	}
	Update(root);
}

void FHQ_Treap::SplitByRank(int root,int k,int &x,int &y)
{
	if (root==0)
	{
		x=y=0;
		return ;
	}
	if (node[root].size<k)
	{
		x=root;
		SplitByRank(node[root].y,k,node[root].y,y);
	}
	else
	{
		y=root;
		SplitByRank(node[root].x,k,x,node[root].x);
	}
	Update(root);
}

int FHQ_Treap::Merge(int x,int y)
{
	if (x==0||y==0)
		return x+y;
	if (node[x].d<node[y].d)
	{
		node[x].y=Merge(node[x].y,y);
		Update(x);
		return x;
	}
	else
	{
		node[y].x=Merge(x,node[y].x);
		Update(y);
		return y;
	}
}

void FHQ_Treap::Insert(int val)
{
	int x,y;
	SplitByValue(ROOT,val,x,y);
	Merge(Merge(x,New(val)),y);
}

void FHQ_Treap::Delete(int val)
{
	int x,y,z;
	SplitByValue(ROOT,val,x,z);
	SplitByValue(x,val-1,x,y);
	y=Merge(node[y].x,node[y].y);
	ROOT=Merge(Merge(x,y),z);
}

int FHQ_Treap::Rank(int val)
{
	int x,y;
	SplitByValue(ROOT,val-1,x,y);
	int rank=node[x].size;
	Merge(x,y);
	return rank;
}

int FHQ_Treap::Find_K_Th(int k)
{
	return node[Rank(k)].val;
}

int FHQ_Treap::Find_K_Th(int root,int k);

int main()
{
	return 0;
}
