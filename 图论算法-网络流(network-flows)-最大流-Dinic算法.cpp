#include<iostream>
#include<cstring>
#include<cstdio>
#include<string>
#include<cstdlib>
#include<algorithm>
#include<set>
#include<queue>
#include<vector>
#include<map>
#define Max 1100000
using namespace std;


class NetworkFlows
{
	struct Node
	{
		int y,v,next;
	}node[Max];	
	int dist[Max];
	int len,last[Max],s,t,n,m,mf;
	int find(int x,int lf);
	void build(int x,int y,int v);
	public:
		void init();
		void dinic();
		bool fdinic();
		void print();
};

void NetworkFlows::build(int x,int y,int v)
{
	len++;
	node[len].y=y,node[len].v=v,node[len].next=last[x],last[x]=len;
}

void NetworkFlows::init()
{
	memset(node,0,sizeof node);
	int x,y,v;
	len=1;
	cin>>n>>m>>s>>t;
	for (int i=1;i<=m;i++)
		cin>>x>>y>>v,build(x,y,v),build(y,x,0);
}

bool NetworkFlows::fdinic()
{
	memset(dist,0x7f,sizeof dist);
	queue<int> que;
	dist[s]=0;
	que.push(s);
	while (que.size())
	{
		int x=que.front();
		que.pop();
		for (int i=last[x];i;i=node[i].next)
		{
			int y=node[i].y;
			if (node[i].v&&dist[y]>dist[x]+1)
				dist[y]=dist[x]+1,que.push(y);
		}
	}
	return dist[t]!=0x7f7f7f7f;
}

int NetworkFlows::find(int x,int lf)
{
	if (x==t)
		return lf;
	int rlf=0;
	for (int i=last[x];i;i=node[i].next)
	{
		int y=node[i].y;
		if (node[i].v&&dist[y]==dist[x]+1)
			if (rlf=find(y,min(lf,node[i].v)))
			{
				node[i].v-=rlf,node[i^1].v+=rlf;
				return rlf;
			}	
	}
}

void NetworkFlows::print()
{
	cout<<mf<<endl;
}

void NetworkFlows::dinic()
{
	mf=0;
	int lowf=0;
	while (fdinic())
		while (lowf=find(s,1<<26))
			mf+=lowf;
}


NetworkFlows f;

int main()
{
	f.init();
	f.dinic();
	f.print();
	return 0;
}
