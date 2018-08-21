#include<iostream>
#include<cstring>
#include<cstdio>
#include<string>
#include<cstdlib>
#include<algorithm>
#include<set>
#include<cmath>
#include<iomanip>
#include<queue>
#include<vector>
#include<map>
#define Max1 3000000
#define Max2 3000000
using namespace std;

class Dijkstra
{
    
    int last[Max1],len,ans[Max1];
    class pc
    {
        bool ps[Max1];
        public:
            void clear();
            bool count(int k);
            void insert(int k);
            void erase(int k);
    };
    struct Node
    {
        int y,d,next;
    };
    struct edge
    {
        int x,d;
        bool operator< (const edge &k) const;
    };
    pc pd;
    Node node[Max2];
    priority_queue<edge,vector<edge> > que;
    void Make(int x,int y,int d);
    void Add(int x,int y,int d);
    public:
        void Scan(int n);
        int Calc(int x,int y);
};

void Dijkstra::pc::clear(){memset(ps,0,sizeof ps);}

bool Dijkstra::pc::count(int k) {return ps[k];}

void Dijkstra::pc::insert(int k) {ps[k]=1;}

void Dijkstra::pc::erase(int k) {ps[k]=0;}

bool Dijkstra::edge::operator< (const edge &k) const {return d>k.d;}

void Dijkstra::Make(int x,int y,int d)
{
    len++;
    node[len].y=y;
    node[len].d=d;
    node[len].next=last[x];
    last[x]=len;
}

void Dijkstra::Add(int x,int y,int d)
{
    Make(x,y,d);
    Make(y,x,d);
}

void Dijkstra::Scan(int n)
{
    int x,y,d;
    len=0;
    for (int i=1;i<=n;i++)
    {
        cin>>x>>y>>d;
        Add(x,y,d);
    }
}

int Dijkstra::Calc(int x,int y)
{
    memset(ans,0x7f,sizeof ans);
    ans[x]=0;
    while (que.size())
        que.pop();
    que.push(edge{x,0});
    pd.clear();
    while (que.size())
    {
        int kx=que.top().x;
        que.pop();
        pd.erase(kx);
        for (int i=last[kx];i;i=node[i].next)
        {
            int ky=node[i].y,kd=node[i].d;
            if (ans[ky]>ans[kx]+kd)
            {
                ans[ky]=ans[kx]+kd;
                if (!pd.count(ky))
                {
                    pd.insert(ky);
                    que.push(edge{ky,ans[ky]});
                }
            }
        }
    }
    return ans[y]==0x7f7f7f7f?-1:ans[y];
}


Dijkstra dij;

int main()
{
    int n,m;
    cin>>n>>m;
    dij.Scan(m);
    cout<<dij.Calc(1,n);
    return 0;
}
