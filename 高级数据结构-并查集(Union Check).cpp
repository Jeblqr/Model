#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
#include<functional>
#include<map>
#include<set>
#include<queue>
#include<stack>
using namespace std;

class UnionFind
{
	struct Node
	{
		int x,y;
	}node[1100000];
	int n,m;
	void init();
	int find(int k);
	public:
		int fa[1100000];
		void set(int n);
		void build(int x,int y);
		int get();
		bool check(int x,int y);
};

void UnionFind::set(int n)
{
	this->n=n;
}

void UnionFind::init()
{
	for (int i=1;i<=n;i++)
		fa[i]=i;
}

int UnionFind::find(int k)
{
	if (fa[k]!=k)
		fa[k]=find(fa[k]);
	return fa[k];
}

void UnionFind::build(int x,int y)
{
	m++;
	node[m]=Node{x,y};
}

int UnionFind::get()
{
	init();
	int ans=0,t=0;
	for (int i=1;i<=m;i++)
	{
		int fx=find(node[i].x),fy=find(node[i].y);
		if (fx!=fy)
			fa[fx]=fy;
	}
	return ans;
}

bool UnionFind::check(int x,int y)
{
	return find(x)==find(y);
}


UnionFind uf;

int main()
{
	return 0;
}
