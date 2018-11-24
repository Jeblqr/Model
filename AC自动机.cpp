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


//------------------------------------------------
class AC
{
	const int ROOT;
	struct Node
	{   
		int alpha[26];
		inline int &operator[] (int k);
	};
	Node node[1000000];
	int cnt[1000000],fail[1000000],len;
	
	public:
		AC();
		void Init();
		void Insert(string s);
		void MakeFail();
		int Query(string s);
};

AC::AC():ROOT(0)
{
	Init();
}

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

void AC::Insert(string s)
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
	for (int i=0;i!=26;i++)
		if (node[ROOT][i]!=0)
			que.push(node[ROOT][i]);
	while (!que.empty())
	{
		int p=que.front();que.pop();
		for (int i=0;i!=26;i++)
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
	int ans=0,p=ROOT;
	for (int i=0;i!=s.size();i++)
	{
		p=node[p][s[i]-'a'];
		for (int k=p;k!=0&&cnt[k]!=0;k=fail[k])
		{
			ans+=cnt[k];
			cnt[k]=0;
		}
	}
	return ans;
}
//------------------------------------------------


AC ac;

int main()
{
	/*
	//Example in Luogu P3808
	int n;
	cin>>n;
	for (int i=1;i<=n;i++)
	{
		string s;
		cin>>s;
		ac.Insert(s);
	}
	ac.MakeFail();
	string s;
	cin>>s;
	cout<<ac.Query(s);
	*/
	return 0;
} 
