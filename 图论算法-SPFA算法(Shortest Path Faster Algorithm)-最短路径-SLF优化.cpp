#include<iostream>
#include<cstring>
#include<cstdio>
#include<string>
#include<cstdlib>
#include<algorithm>
#include<set>
#include<queue>
#define Max1 110000
#define Max2 510000
#define Max3 Max1
using namespace std;


class SPFA
{
	class pc
	{
		bool ps[Max3];
		public:
			bool count(int k);
			void insert(int k);
			void clear();
			bool erase(int k);
	};
    struct node
    {
        int x,y,v,next;
    };
	node a[Max1];
    int n;
    int last[Max2];
    int len;
    int ans[Max1];
    pc pd;
    set<pair<int,int> > p;
    deque<int> que;
    void MakeLine(int x,int y,int v);
    void IsInIt(int x,int y,int sum);
    public:
        void scan(int n);
        int calc(int x,int y);
};

bool SPFA::pc::count(int k){return (ps[k]);}

void SPFA::pc::insert(int k){ps[k]=1;}

void SPFA::pc::clear(){memset(ps,0,sizeof ps);}

bool SPFA::pc::erase(int k){ps[k]=0;}

void SPFA::MakeLine(int x,int y,int v)
{
	if (p.count(make_pair(x,y)))
	{
		for (int i=1;i<=len;i++)
			if (a[i].x==x&&a[i].y==y)
				if (a[i].v>v)
				{
					a[i].v=v;
					break;
				}
		return;
	} 
    len++;
    a[len].x=x,a[len].y=y,a[len].v=v,a[len].next=last[x];
    last[x]=len;
    p.insert(make_pair(x,y));
}

void SPFA::IsInIt(int x,int y,int sum)
{
    if (ans[y]<=ans[x]+sum)
        return;
    ans[y]=ans[x]+sum;
    if (pd.count(y))
        return;
    if (y>x)
        que.push_back(y);
    else
        que.push_front(y);
    pd.insert(y);
}

int SPFA::calc(int x,int y)
{
    memset(ans,0x7f,sizeof ans);
    ans[x]=0;
    que.clear();
    pd.clear();
    que.push_back(x);
    pd.insert(x);
    while (!que.empty())
    {
        int kx=que.front();
        que.pop_front();
		pd.erase(kx);
        for (int i=last[kx];i;i=a[i].next)
            IsInIt(kx,a[i].y,a[i].v); 
    }
    return ans[y];
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
