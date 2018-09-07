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
		int y,v,w,next;
	}node[Max];
	struct Mem
	{
		int x,v;
		bool operator< (const Mem &a) const
		{
			return this->v>a.v;
		}
	};
	struct Pre
	{
		int x,i;
	}pre[Max];
	bool pd[Max];
	int dist[Max];
	int len,last[Max],s,t,n,m,mf,co;
	bool find();
	void build(int x,int y,int v,int w);
	public:
		void init();
		void EK();
		void print();
};

void NetworkFlows::build(int x,int y,int v,int w)
{
	len++;
	node[len].y=y,node[len].v=v,node[len].w=w,node[len].next=last[x],last[x]=len;
}

void NetworkFlows::init()
{
	memset(node,0,sizeof node);
	int x,y,v,w;
	len=1;
	cin>>n>>m>>s>>t;
	for (int i=1;i<=m;i++)
		cin>>x>>y>>v>>w,build(x,y,v,w),build(y,x,0,-w);
}

bool NetworkFlows::find()
{
	memset(dist,0x7f,sizeof dist);
	dist[s]=0;
	priority_queue<Mem> que;
	que.push(Mem{s,0});
	while (que.size())
	{
		Mem mem=que.top();
		int x=mem.x;
		int v=mem.v;
		que.pop();
		if (v!=dist[x])
			continue;
		for (int i=last[x];i;i=node[i].next)
		{
			int y=node[i].y,w=node[i].w;
			if (dist[y]>dist[x]+w&&node[i].v)
			{
				dist[y]=dist[x]+w;
				que.push(Mem{y,dist[y]});
				pre[y]=Pre{x,i};
			}
		}
	}
	return dist[t]!=0x7f7f7f7f;
}

void NetworkFlows::print()
{
	cout<<mf<<' '<<co<<endl;
}

void NetworkFlows::EK()
{
	while (find())
	{
		int minn=0x7fffffff;
		for (int i=t;i!=s;i=pre[i].x)
			minn=min(minn,node[pre[i].i].v);
		for (int i=t;i!=s;i=pre[i].x)
			node[pre[i].i].v-=minn,node[pre[i].i^1].v+=minn;
		mf+=minn;
		co+=minn*dist[t];
	}
}


NetworkFlows f;

int main()
{
	f.init();
	f.EK();
	f.print();
	return 0;
}
