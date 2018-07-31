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
	struct prev
	{
		int x,i;
	}pre[Max];
	bool pd[Max];
	int len,last[Max],s,t,n,m;
	bool find();
	void build(int x,int y,int v);
	public:
		void init();
		int EK();
};

void NetworkFlows::build(int x,int y,int v)
{
	len++;
	node[len].y=y,node[len].v=v,node[len].next=last[x],last[x]=len;
}

void NetworkFlows::init()
{
	int x,y,d;
	len=1;
	cin>>n>>m>>s>>t;
	for (int i=1;i<=m;i++)
		cin>>x>>y>>d,build(x,y,d),build(y,x,0);
}

bool NetworkFlows::find()
{
	memset(pd,0,sizeof pd);
	memset(pre,0,sizeof pre);
	queue<int> que;
	que.push(s);
	pd[s]=1;
	while (!que.empty())
	{
		int x=que.front();
		que.pop();
		for (int i=last[x];i;i=node[i].next)
		{
			int y=node[i].y;
			if (!pd[y]&&node[i].v)
			{
				pd[y]=1;
				pre[y].x=x;
				pre[y].i=i;
				que.push(y);
				if (y==t)
					return 1;
			}
		}
	}
	return 0;
}

int NetworkFlows::EK()
{
	int ans=0;
	while (find())
	{
		int minn=1<<26;
		for (int i=t;i!=s;i=pre[i].x)
			minn=min(minn,node[pre[i].i].v);
		for (int i=t;i!=s;i=pre[i].x)
			node[pre[i].i].v-=minn,node[pre[i].i^1].v+=minn;
		ans+=minn;
	}
	return ans;
}


NetworkFlows f;

int main()
{
	f.init();
	cout<<f.EK()<<endl;
	return 0;
}
