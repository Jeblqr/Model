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

//---------------------------------------
class Kruskal
{
	struct Node
	{
		int x,y,v;
		bool operator<(const Node &x) const
		{
			return this->v<x.v;
		}
	}node[1100000];
	int n,m,fa[1100000];
	void init();
	int find(int k);
	public:
		void set(int n);
		void build(int x,int y,int v);
		int get();
};

void Kruskal::set(int n)
{
	this->n=n;
}

void Kruskal::init()
{
	for (int i=1;i<=n;i++)
		fa[i]=i;
	sort(node+1,node+m+1);
}

int Kruskal::find(int k)
{
	if (fa[k]!=k)
		fa[k]=find(fa[k]);
	return fa[k];
}

void Kruskal::build(int x,int y,int v)
{
	m++;
	node[m]=Node{x,y,v};
}

int Kruskal::get()
{
	init();
	int ans=0,t=0;
	for (int i=1;i<=m;i++)
	{
		int fx=find(node[i].x),fy=find(node[i].y);
		if (fx!=fy)
		{
			fa[fx]=fy,ans+=node[i].v;
			t++;
			if (t==n-1)
				break;
		}
	}
	return ans;
}
//---------------------------------------

Kruskal kl;

int main()
{
	return 0;
}


