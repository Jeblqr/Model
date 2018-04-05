#include<cstdlib>
#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
class side
{
	public:
		int x,y,d,next;
};
side a[1100000];
int len,last[1100000],list[1100000],h=1,t=2,bj[1100000],ans[1100000],n,m;
void init();
void read();
void set(int x,int y,int d);
void SPFA();
void print();
int main()
{
	init();
	read();
	SPFA();
	print();
	return 0;
}
void init()
{
	memset(ans,0x3f,sizeof(ans));
	bj[1]=1;
	list[1]=1;
	ans[1]=0;
}
void read()
{
	cin>>n>>m;
	for (int i=1;i<=m;i++)
	{
		int x,y,d;
		cin>>x>>y>>d;
		set(x,y,d);
		set(y,x,d);
	}
}
void set(int x,int y,int d)
{
	len++;
	a[len].x=x;
	a[len].y=y;
	a[len].d=d;
	a[len].next=last[x];
	last[x]=len;
}
void SPFA()
{
	while (h!=t)
	{
		int x=list[h];
		for (int i=last[x];i;i=a[i].next)
		{
			int y=a[i].y;
			if (ans[x]+a[i].d<ans[y])
			{
				if (bj[y]==0)
				{
					bj[y]=1;
					list[t]=y;
					t++;
					if (t==n+1)
						t=1;
				}
				ans[y]=ans[x]+a[i].d;
			}
		}
		h++;
		if (h==n+1) h=1;
		bj[x]=0;
	}
}
void print()
{
	cout<<ans[n];
}
