#include<iostream>
#include<cstdio>
#define N 500005
using namespace std;


//-----------------------------
class HeavyPathDecomposition
{
	struct Node
	{
		int y,val,next;
	};
	struct Data
	{
		int size,top,son,depth,father,id;
	};
	Node node[N*2];
	int len,fa[N],last[N],rank[N],size[N],top[N],son[N],depth[N],father[N],id[N],cnt;
	void Get(int x);
	void Decomposition(int top,int x);
	public:
		void Add(int x,int y,int val); 
		HeavyPathDecomposition():len(0),cnt(0){};
		void Calc(int ROOT);
		Data GetData(int k) const;
};

void HeavyPathDecomposition::Add(int x,int y,int val)
{
	len++;
	node[len]={y,val,last[x]};
	last[x]=len;
}

void HeavyPathDecomposition::Get(int x)
{
	size[x]=1;
	for (int i=last[x],y=node[i].y;i;i=node[i].next,y=node[i].y)
	{
		if (father[x]==y)
			continue;
		depth[y]=depth[x]+1;
		father[y]=x;
		Get(y);
		size[x]+=size[y];
		if (son[x]==0||size[son[x]]<=size[y])
			son[x]=y;
	}
}

void HeavyPathDecomposition::Decomposition(int root,int x)
{
	if (x==0)
		return;
	cnt++;
	top[x]=root;
	id[x]=cnt;
	rank[cnt]=x;
	Decomposition(root,son[x]);
	for (int i=last[x],y=node[i].y;i;i=node[i].next,y=node[i].y)
	{
		if (son[x]!=y&&father[x]!=y)
			Decomposition(y,y);
	}
}

void HeavyPathDecomposition::Calc(int ROOT)
{
	Get(ROOT);
	Decomposition(ROOT,ROOT);
}

HeavyPathDecomposition::Data HeavyPathDecomposition::GetData(int k) const
{
	Data data={size[k],top[k],son[k],depth[k],father[k],id[k]};
	return data;
}
//-----------------------------


HeavyPathDecomposition T;

int main()
{
	auto in=[]()
	{
		int f=0,p=1;
		char c;
		c=getchar();
		while (c<'0'||c>'9')
		{
			if (c=='-')
				p=-1;
			c=getchar();
		}
		while (c>='0'&&c<='9')
		{
			f=f*10+c-'0';
			c=getchar();
		}
		return f*p;
	};
	int n,m,s;
	n=in();
	m=in();
	s=in();
	for (int i=1,x,y;i<n;i++)
		x=in(),y=in(),T.Add(x,y,0),T.Add(y,x,0);
	T.Calc(s);
	for (int i=1,x,y;i<=m;i++)
	{
		x=in();
		y=in();
		while (T.GetData(x).top!=T.GetData(y).top)
		{
			if (T.GetData(T.GetData(x).top).depth>=T.GetData(T.GetData(y).top).depth)
				x=T.GetData(T.GetData(x).top).father;
			else
			 	y=T.GetData(T.GetData(y).top).father;
		}
		cout<<(T.GetData(x).depth<T.GetData(y).depth?x:y)<<endl;
	}
	return 0;
}
