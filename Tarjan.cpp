#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
#include<stack>
#define N 1000001
#define M 1000001
using namespace std;

//--------------------------------------------
class Tarjan
{
	struct Node
	{
		int y,next;
	};
	Node node[M];
	int last[N],cntcolor[N],dfn[N],low[N],color[N],tot,colortot,dtot;
	bool vis[N];
	stack<int> st;
	void paint();
	void tarjan(int x);
	public:
		Tarjan();
		void insert(int x,int y);
		int calcAmount(int n);
		
};

void Tarjan::paint()
{
	int x=st.top();
	st.pop();
	vis[x]=false;
	color[x]=colortot;
	cntcolor[colortot]++;
}

void Tarjan::tarjan(int x)
{
	dfn[x]=low[x]=++dtot;
	st.push(x);
	vis[x]=true;
	for (int i=last[x];i;i=node[i].next)
	{
		int y=node[i].y;
		if (!dfn[y])
		{
			tarjan(y);
			low[x]=min(low[x],low[y]);
		}
		else if (vis[y])
		{
			low[x]=min(low[x],low[y]);
		}
	}
	if (dfn[x]==low[x])
	{
		colortot++;
		while (st.top()!=x)
			paint();
		paint();
	}
}

Tarjan::Tarjan():tot(0),colortot(0),dtot(0)
{
	memset(node,0,sizeof node);
	memset(last,0,sizeof last);
	memset(cntcolor,0,sizeof cntcolor);
	memset(dfn,0,sizeof dfn);
	memset(low,0,sizeof low);
	memset(color,0,sizeof color);
} 

void Tarjan::insert(int x,int y)
{
	node[++tot]={y,last[x]};
	last[x]=tot;
}

int Tarjan::calcAmount(int n)
{
	for (int i=1;i<=n;i++)
	{
		if (!dfn[i])
			tarjan(i);
	}
	int ans=0;
	for (int i=1;i<=colortot;i++)
		if (cntcolor[i]>1)
			ans++;
	return ans;
}
//--------------------------------------------

Tarjan tj;
int main()
{
	int n,m;
	cin>>n>>m;
	for (int i=1,x,y;i<=m;i++)
		cin>>x>>y,tj.insert(x,y);
	cout<<tj.calcAmount(n); 
	return 0;
}
