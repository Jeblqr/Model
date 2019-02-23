#include<bits/stdc++.h>
using namespace std;
class NetworkFlow
{
    struct Edge
    {
        int y,next,f;
    }e[10000000];
    int len,last[10000000],dis[10000000];
    
    bool spfa(int s,int t)
    {
        memset(dis,0x3f,sizeof dis);
        dis[s]=0;
        queue<int> que;
        que.push(s);
        while (!que.empty())
        {
            int x=que.front();
            que.pop();
            for (int i=last[x];i;i=e[i].next)
            {
                if (e[i].f&&dis[e[i].y]>dis[x]+1)
                    dis[e[i].y]=dis[x]+1,que.push(e[i].y);
            }
        }
        return dis[t]!=0x3f3f3f3f;
    }
    int dfs(int x,int f,int t)
    {
        if (x==t)
            return f;
        int k=0,used=0;
        for (int i=last[x];i;i=e[i].next)
        {
            if (e[i].f&&dis[e[i].y]==dis[x]+1)
            {
                if (k=dfs(e[i].y,min(f-used,e[i].f),t))
                    used+=k,e[i].f-=k,e[i^1].f+=k;
                if (used==f)
                    break;
            }
        }
        return used;
    }
    public:
        NetworkFlow():len(1){};
        void add(int x,int y,int f)
        {
            e[++len]={y,last[x],f};
            last[x]=len;
            e[++len]={x,last[y],0};
            last[y]=len;
        }
        int flow(int s,int t)
        {
            int flow=0,k=0;
            while (spfa(s,t))
                while (k=dfs(s,0x3f3f3f3f,t))
                    flow+=k;
            return flow;
        }
};
NetworkFlow T;
int main()
{
    int n,m,s,t;
    cin>>n>>m>>s>>t;
    for (int i=1,x,y,f;i<=m;i++)
    {
        cin>>x>>y>>f;
        T.add(x,y,f);
    }
    cout<<T.flow(s,t);
    return 0;
}
