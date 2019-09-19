#include<bits/stdc++.h>
using namespace std;
struct Dij
{
	struct Edge
	{
		long long y,next,d;
	}e[10000000];
	long long len,last[1000000],dis[1000000];
	struct Node
	{
		long long x,dis;
		bool operator<(const Node &node) const
		{
			return this->dis>node.dis;
		}
	};
	void operator()(long long s)
	{
		priority_queue<Node> que;
		que.push(Node{s,0});
		memset(dis,0x7f,sizeof dis);
		dis[s]=0;
		while (!que.empty())
		{
			Node t=que.top();
			que.pop();
			if (t.dis>dis[t.x])
				continue;
			long long x=t.x;
			for (long long i=last[x];i;i=e[i].next)
			{
				if (dis[e[i].y]>dis[x]+e[i].d)
					dis[e[i].y]=dis[x]+e[i].d,que.push(Node{e[i].y,dis[e[i].y]});
			}
		}
	}
	void add(long long x,long long y,long long d)
	{
		e[++len]={y,last[x],d};
		last[x]=len;
	}
}T;
int main()
{
	long long n,m,s;
	cin>>n>>m>>s;
	for (long long i=1,x,y,d;i<=m;i++)
		cin>>x>>y>>d,T.add(x,y,d);
	T(s);
	for (long long i=1;i<=n;i++)
		cout<<T.dis[i]<<' ';
	return 0;
}
