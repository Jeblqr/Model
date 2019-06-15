#include<bits/stdc++.h>
using namespace std;


//----------------------------------------------
class Dinic
{
    struct Node
    {
        int y,next,f,c;
    };
    Node node[1000001];
    queue<int> que;
    bool vis[1000001];
    int dis[1000001],last[1000001],tot;
    bool SPFA_Min();
    bool SPFA_Max();
    int dfs(int x,int flow);
    public:
        Dinic():tot(1) {};
        int s,t,cost,maxflow;
        void add(int x,int y,int f,int c);
        void add(int x,int y,int f);
        void calc(int opt);
        /*
        // if opt == 1 it's mincost
		// if opt == 2 it's maxcost 
        */
};

bool Dinic::SPFA_Min()
{
    memset(vis,0,sizeof vis);
    memset(dis,0x3f,sizeof dis);
    while (!que.empty())
        que.pop();
    vis[s]=1;
    dis[s]=0;
    que.push(s);
    while (!que.empty())
    {
        int x=que.front();
        que.pop();
        vis[x]=0;
        for (int i=last[x];i;i=node[i].next)
        {
            int y=node[i].y;
            if (node[i].f&&dis[y]>dis[x]+node[i].c)
            {
                dis[y]=dis[x]+node[i].c;
                if (!vis[y])
                    vis[y]=1,que.push(y);
            }
        }
    }
    return dis[t]!=0x3f3f3f3f;
}

bool Dinic::SPFA_Max()
{
	{
    memset(vis,0,sizeof vis);
    memset(dis,-1,sizeof dis);
    while (!que.empty())
        que.pop();
    vis[s]=1;
    dis[s]=0;
    que.push(s);
    while (!que.empty())
    {
        int x=que.front();
        que.pop();
        vis[x]=0;
        for (int i=last[x];i;i=node[i].next)
        {
            int y=node[i].y;
            if (node[i].f&&dis[y]<dis[x]+node[i].c)
            {
                dis[y]=dis[x]+node[i].c;
                if (!vis[y])
                    vis[y]=1,que.push(y);
            }
        }
    }
    return dis[t]!=0x3f3f3f3f;
}
}

int Dinic::dfs(int x,int flow)
{
    vis[x]=1;
    if (x==t)
        return flow;
    int used=0,k;
    for (int i=last[x];i;i=node[i].next)
    {
        int y=node[i].y;
        if (!vis[y]&&node[i].f&&dis[y]==dis[x]+node[i].c)
        {
            if (k=dfs(y,min(flow-used,node[i].f)))
            {
                used+=k;
                cost+=node[i].c*k;
                node[i].f-=k,node[i^1].f+=k;
                if (used==flow)
                    break;
            }
        }
    }
    return used;
}

void Dinic::add(int x,int y,int f,int c)
{
    node[++tot]={y,last[x],f,c};
    last[x]=tot;
    node[++tot]={x,last[y],0,-c};
    last[y]=tot;
}

void Dinic::add(int x,int y,int f)
{
    node[++tot]={y,last[x],f,1};
    last[x]=tot;
    node[++tot]={x,last[y],0,-1};
    last[y]=tot;
}

void Dinic::calc(int opt)
{
    maxflow=cost=0;
    if (opt==1)
    {
	    while (SPFA_Min())
	    {
	        vis[t]=1;
	        while (vis[t])
	            memset(vis,0,sizeof vis),maxflow+=dfs(s,0x7f7f7f7f);
	    }
	}
    else
    {
    	while (SPFA_Max())
	    {
	        vis[t]=1;
	        while (vis[t])
	            memset(vis,0,sizeof vis),maxflow+=dfs(s,0x7f7f7f7f);
	    }
	}
}
//----------------------------------------------


Dinic dinic;

int main()
{
    int n,m;
    cin>>n>>m>>dinic.s>>dinic.t;
    for (int i=1,x,y,f,c;i<=m;i++)
        cin>>x>>y>>f>>c,dinic.add(x,y,f,c);
    dinic.calc(1);
    cout<<dinic.maxflow<<' '<<dinic.cost;
    return 0;
}



/*
#include <bits/stdc++.h>
using namespace std;

//----------------------------------------------
class Dinic {
    struct Node {
        int y, next, f, c;
    };
    Node node[1000001];
    queue<int> que;
    bool vis[1000001];
    int dis[1000001], last[1000001], tot;
    bool SPFA_Min();
    bool SPFA_Max();
    int dfs(int x, int flow);

public:
    Dinic() : tot(1){};
    int s, t, cost, maxflow;
    void add(int x, int y, int f, int c);
    void add(int x, int y, int f);
    void calc(int opt);
};

bool Dinic::SPFA_Min() {
    memset(vis, 0, sizeof vis);
    memset(dis, 0x3f, sizeof dis);
    while (!que.empty()) que.pop();
    vis[s] = 1;
    dis[s] = 0;
    que.push(s);
    while (!que.empty()) {
        int x = que.front();
        que.pop();
        vis[x] = 0;
        for (int i = last[x]; i; i = node[i].next) {
            int y = node[i].y;
            if (node[i].f && dis[y] > dis[x] + node[i].c) {
                dis[y] = dis[x] + node[i].c;
                if (!vis[y])
                    vis[y] = 1, que.push(y);
            }
        }
    }
    return dis[t] != 0x3f3f3f3f;
}

bool Dinic::SPFA_Max() {
    {
        memset(vis, 0, sizeof vis);
        memset(dis, -1, sizeof dis);
        while (!que.empty()) que.pop();
        vis[s] = 1;
        dis[s] = 0;
        que.push(s);
        while (!que.empty()) {
            int x = que.front();
            que.pop();
            vis[x] = 0;
            for (int i = last[x]; i; i = node[i].next) {
                int y = node[i].y;
                if (node[i].f && dis[y] < dis[x] + node[i].c) {
                    dis[y] = dis[x] + node[i].c;
                    if (!vis[y])
                        vis[y] = 1, que.push(y);
                }
            }
        }
        return dis[t] != 0x3f3f3f3f;
    }
}

int Dinic::dfs(int x, int flow) {
    vis[x] = 1;
    if (x == t)
        return flow;
    int used = 0, k;
    for (int i = last[x]; i; i = node[i].next) {
        int y = node[i].y;
        if (!vis[y] && node[i].f && dis[y] == dis[x] + node[i].c) {
            if (k = dfs(y, min(flow - used, node[i].f))) {
                used += k;
                cost += node[i].c * k;
                node[i].f -= k, node[i ^ 1].f += k;
                if (used == flow)
                    break;
            }
        }
    }
    return used;
}

void Dinic::add(int x, int y, int f, int c) {
    node[++tot] = { y, last[x], f, c };
    last[x] = tot;
    node[++tot] = { x, last[y], 0, -c };
    last[y] = tot;
}

void Dinic::add(int x, int y, int f) {
    node[++tot] = { y, last[x], f, 1 };
    last[x] = tot;
    node[++tot] = { x, last[y], 0, -1 };
    last[y] = tot;
}

void Dinic::calc(int opt) {
    maxflow = cost = 0;
    if (opt == 1) {
        while (SPFA_Min()) {
            vis[t] = 1;
            while (vis[t]) memset(vis, 0, sizeof vis), maxflow += dfs(s, 0x7f7f7f7f);
        }
    } else {
        while (SPFA_Max()) {
            vis[t] = 1;
            while (vis[t]) memset(vis, 0, sizeof vis), maxflow += dfs(s, 0x7f7f7f7f);
        }
    }
}
//----------------------------------------------

Dinic dinic;

int main() {
    int n, m;
    cin >> n >> m >> dinic.s >> dinic.t;
    for (int i = 1, x, y, f, c; i <= m; i++) cin >> x >> y >> f >> c, dinic.add(x, y, f, c);
    dinic.calc(1);
    cout << dinic.maxflow << ' ' << dinic.cost;
    return 0;
}
*/
