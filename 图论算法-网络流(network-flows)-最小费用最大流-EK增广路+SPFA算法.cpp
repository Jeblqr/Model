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
	struct prev
	{
		int x,i;
	}pre[Max];
	bool pd[Max];
	int spfa[Max];
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
	memset(pd,0,sizeof pd);
	memset(pre,0,sizeof pre);
	memset(spfa,0x3f,sizeof spfa);
	queue<int> que;
	que.push(s);
	pd[s]=1;
	spfa[s]=0;
	while (!que.empty())
	{
		int x=que.front();
		que.pop();
		pd[x]=0;
		for (int i=last[x];i;i=node[i].next)
		{
			int y=node[i].y;
			if (spfa[y]>spfa[x]+node[i].w&&node[i].v)
			{
				spfa[y]=spfa[x]+node[i].w;
				pre[y].i=i,pre[y].x=x;
				if (!pd[y])
					pd[y]=1,que.push(y);
			}
		}
	}
	return spfa[t]!=0x3f3f3f3f;
}

void NetworkFlows::print()
{
	cout<<mf<<' '<<co<<endl;
}

void NetworkFlows::EK()
{
	mf=0,co=0;
	while (find())
	{
		int minn=1<<26;
		for (int i=t;i!=s;i=pre[i].x)
			minn=min(minn,node[pre[i].i].v);
		for (int i=t;i!=s;i=pre[i].x)
			node[pre[i].i].v-=minn,node[pre[i].i^1].v+=minn;
		mf+=minn;
		co+=minn*spfa[t];
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
