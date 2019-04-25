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
#define N 1100000
using namespace std;


//--------------------------------------------
class Dinic
{
    struct Node
    {
        int y,next,flow,cost;
    };
    struct Data
    {
    	int maxflow,cost;
    };
    Node node[N];
    Data data;
    bool vis[N];
    int dis[N];
    int len,last[N];
    bool SPFA(int s,int t);
    int DFS(int x,int flow,int t);
    public:
    	Dinic();
    	void Add(int x,int y,int flow,int cost);
        Data Calc(int s,int t);
};

bool Dinic::SPFA(int s,int t)
{
    queue<int> que;
    memset(vis,0,sizeof vis);
    memset(dis,0x3f,sizeof dis);
    que.push(s);
    vis[s]=1;
    dis[s]=0;
    while (!que.empty())
    {
        int x=que.front();
        que.pop();
        vis[x]=0;
        for (int i=last[x],y=node[i].y;i;i=node[i].next,y=node[i].y)
        {
            if (node[i^1].flow>0&&dis[y]>dis[x]-node[i].cost)
            {
                dis[y]=dis[x]-node[i].cost;
                if (vis[y]==0)
                    vis[y]=1,que.push(y);
            }
        }
    }
    return dis[t]!=0x3f3f3f3f;
}

int Dinic::DFS(int x,int flow,int t)
{
    vis[x]=1;
    if (x==t)	
        return flow;
    int used=0;
    for (int i=last[x],y=node[i].y;i;i=node[i].next,y=node[i].y)
    {
        if (vis[y]==0&&node[i].flow!=0&&dis[y]==dis[x]-node[i].cost)
        {
            int k=DFS(y,min(flow-used,node[i].flow),t);
            if (k!=0)
            {
                data.cost+=k*node[i].cost;
                used+=k;
                node[i].flow-=k,node[i^1].flow+=k;
            }
            if (flow==used)
                break;
        }
    }
    return used;
}

Dinic::Dinic():len(1)
{
}

void Dinic::Add(int x,int y,int flow,int cost)
{
    len++;
    node[len]={y,last[x],flow,cost};
    last[x]=len;
    len++;
    node[len]={x,last[y],0,-cost};
    last[y]=len;
}

Dinic::Data Dinic::Calc(int s,int t)
{
    data={};
    while (SPFA(t,s)==1)
    {
        vis[t]=1;
        while (vis[t]==1)
        {
            memset(vis,0,sizeof vis);
            data.maxflow+=DFS(s,0x3f3f3f3f,t);
        }
    }
    return data;
}
//-----------------------------------------


Dinic dinic;

int main()
{
    return 0;
}
