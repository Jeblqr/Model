#include<iostream>
#include<cstring>
#include<string>
#include<queue>
#include<set>
#include<cstdio>
#include<algorithm>
#define Max 30
using namespace std;

struct hero
{
	int hp,dps;
	double x;
}h[Max];
bool operator<(hero a,hero b){return (a.x<b.x?1:(a.x>b.x?0:(a.hp<b.hp?1:(a.hp>b.hp?0:a.dps>b.dps))));}
	
int q[Max];

int main()
{
	int n;
	cin>>n;
	for (int i=1;i<=n;i++)
		cin>>h[i].dps>>h[i].hp,h[i].x=1.0*h[i].dps/h[i].hp;//第一次没有把h[i].dps乘1.0
	sort(h+1,h+n+1);
	for (int i=1;i<=n;i++)
		q[i]=q[i-1]+h[i].dps;
	long long ans=0;
	while (n)
	{
		ans+=q[n];
		if (!--h[n].hp)
			n--;
	}
	cout<<ans;
	return 0;
}
//第一次没过