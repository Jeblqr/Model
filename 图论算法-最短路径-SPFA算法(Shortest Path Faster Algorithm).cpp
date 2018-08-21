#include<iostream>
#include<cstring>
#include<cstdio>
#include<string>
#include<cstdlib>
#include<algorithm>
#include<set>
#include<queue>
#define Max1 1000000
#define Max2 1000000
#define Max3 Max1
using namespace std;


class SPFA
{
    class Pc
    {
	    bool ps[Max3];
	    public:
	    	bool count(int k);
	    	void insert(int k);
	    	void clear();
		    bool erase(int k);
    };
    struct Node
    {
        int x,y,d,next;
    };
	Node node[Max1];
    int last[Max2],len,ans[Max1];
    Pc pd;
    queue<int> que;
    void MakeLine(int x,int y,int d);
    public:
        void scan(int n);
        int calc(int x,int y);
};

bool SPFA::Pc::count(int k){return (ps[k]);}

void SPFA::Pc::insert(int k){ps[k]=1;}

void SPFA::Pc::clear(){memset(ps,0,sizeof ps);}

bool SPFA::Pc::erase(int k){ps[k]=0;}

void SPFA::MakeLine(int x,int y,int d)
{
    len++;
    node[len].x=x,node[len].y=y,node[len].d=d,node[len].next=last[x];
    last[x]=len;
}

int SPFA::calc(int x,int y)
{
    memset(ans,0x7f,sizeof ans);
    ans[x]=0;
    while (que.size())
        que.pop();
    pd.clear();
    que.push(x);
    pd.insert(x);
    while (!que.empty())
    {
        int kx=que.front();
        que.pop();
	pd.erase(kx);
        for (int i=last[kx];i;i=node[i].next)
        {
            int ky=node[i].y;
            if (ans[ky]>ans[kx]+node[i].d)
            {
                ans[ky]=ans[kx]+node[i].d;
                if (!pd.count(ky))
                {
                    pd.insert(ky);
                    que.push(ky);
                }
            }
        }
    }
    return ans[y]==0x7f7f7f7f?-1:ans[y];
}

void SPFA::scan(int n)
{
    int x,y,v;
    for (int i=1;i<=n;i++)
    {
        cin>>x>>y>>v;
        MakeLine(x,y,v);
        MakeLine(y,x,v);
    }
}


SPFA spfa;

int main()
{
    int n,m;
    cin>>n>>m;
    spfa.scan(m);
    cout<<spfa.calc(1,n);
    return 0;
}
