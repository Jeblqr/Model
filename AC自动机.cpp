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
using namespace std;

class AC
{
	#define ROOT 0
	struct Node
	{
		int alpha[26];
		inline int &operator[] (int k);
	};
	Node node[1000000];
	int cnt[1000000],fail[1000000],len;
	public:
		void Init();
		void Instead(string s);
		void MakeFail();
		int Query(string s);
};

int& AC::Node::operator[] (int k)
{
	return alpha[k];
}

void AC::Init()
{
	memset(node,0,sizeof node);
	memset(cnt,0,sizeof cnt);
	memset(fail,0,sizeof fail);
	len=0;
}

void AC::Instead(string s)
{
	int p=ROOT;
	for (int i=0;i!=s.size();i++)
	{
		if (node[p][s[i]-'a']==0)
			node[p][s[i]-'a']=++len;
		p=node[p][s[i]-'a'];
	}
	cnt[p]++;
}

void AC::MakeFail()
{
	queue<int> que;
	for (int i=0;i<=25;i++)
		if (node[ROOT][i])
			que.push(node[ROOT][i]);
	while (!que.empty())
	{
		int p=que.front();
		que.pop();
		for (int i=0;i<=25;i++)
		{
			if (node[p][i]!=0)
			{
				fail[node[p][i]]=node[fail[p]][i];
				que.push(node[p][i]);
			}
			else
			{
				node[p][i]=node[fail[p]][i];
			}
		}
	}
}

int AC::Query(string s)
{
	int p=ROOT,ans=0;
	for (int i=0;i!=s.size();i++)
	{
		p=node[p][s[i]-'a'];
		for (int k=p;k!=0&&cnt[k]!=0;k=fail[k])
			ans+=cnt[k],cnt[k]=0;
	}
	return ans;
}

int main()
{
  return 0;
}
