#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
#include<functional>
#include<map>
#include<set>
#include<queue>
#include<stack>
#define Max 2100000
using namespace std;

//-----------------------------------------------
class MQ
{
	struct Node
	{
		int val,i;
	};
	deque<Node> que;
	public:
		int ans[Max];
		void GetMax(int m,int a[],int n);
		void GetMin(int m,int a[],int n);
};

void MQ::GetMax(int m,int a[],int n)
{
	while (que.size())
		que.pop_back();
	memset(ans,0,sizeof ans);
	for (int i=1;i<m;i++)
	{
		while (que.size()&&que.back().val<=a[i])
			que.pop_back();
		que.push_back(Node{a[i],i});
	}
	for (int i=m;i<=n;i++)
	{
		while (que.size()&&que.back().val<=a[i])
			que.pop_back();
		que.push_back(Node{a[i],i});
		while (que.size()&&que.front().i<i-m+1)
			que.pop_front();
		ans[i-m+1]=que.front().val;
	}
}

void MQ::GetMin(int m,int a[],int n)
{
	memset(ans,0,sizeof ans);
	while (que.size())
		que.pop_back();
	for (int i=1;i<m;i++)
	{
		while (que.size()&&que.back().val>=a[i])
			que.pop_back();
		que.push_back(Node{a[i],i});
	}
	for (int i=m;i<=n;i++)
	{
		while (que.size()&&que.back().val>=a[i])
			que.pop_back();
		que.push_back(Node{a[i],i});
		while (que.size()&&que.front().i<i-m+1)
			que.pop_front();
		ans[i-m+1]=que.front().val;
	}
}
//-----------------------------------------------

int main()
{
	return 0;
}
