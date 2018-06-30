#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
#include<queue>
#include<set>
using namespace std;
int last[1000000],len,x,y,d,n,m;
deque<int> que;
set<int> bj;
double ans[1000000];
class node
{
	public:
		int x,y,d,next;
}a[1000000];
inline void setting(int x,int y,int d)
{
	len++;
	a[len].x=x,a[len].y=y,a[len].d=d;
	a[len].next=last[x];
	last[x]=len;
}
void init()
{
	cin>>n>>m;
	for (int i=1;i<=m;i++)
	{
		cin>>x>>y>>d;
		setting(x,y,d);
		setting(y,x,d);
	}
	memset(ans,0x7f,sizeof ans);	
}
int SPFA(int x,int y)
{
	ans[1]=0;
	bj.insert(x);
	que.push_back(x);
	while (!que.empty())
	{
		int k=que.front();
		que.pop_front();
		for (int i=last[k];i;i=a[i].next)
		{
			if (ans[a[i].y]>ans[k]+a[i].d)
			{
				ans[a[i].y]=ans[k]+a[i].d;
				if (!bj.count(a[i].y))
				{
					bj.insert(a[i].y);
					que.push_back(a[i].y);
				}
			}
		}
		bj.erase(k);
	}
	return ans[y];
}
void SPFA()
{
	init();
	cout<<SPFA(1,n);
}
int main()
{
	SPFA();
	return 0;
}
