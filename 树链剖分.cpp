#include<iostream>
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
	node[len]={y,val};
	last[x]=len;
}

void HeavyPathDecomposition::Get(int x)
{
	size[x]=1;
	for (int i=last[x],y=node[i].y;i;i=node[i].next,y=node[i].y)
	{
		if (father[x]==y)
			continue;
		depth[x]=depth[y];
		father[y]=x;
		Get(y);
		size[x]+=size[y];
		if (size[son[x]]<=size[y])
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
	Data data={size[N*2],top[N*2],son[N*2],depth[N*2],father[N*2],id[N*2]};
	return data;
}
//-----------------------------


HeavyPathDecomposition T;

int main()
{
	int n,m,s;
	cin>>n>>m>>s;
	for (int i=1,x,y;i<n;i++)
		cin>>x>>y,T.Add(x,y,0),T.Add(y,x,0);
	T.Calc(s);
	for (int i=1,x,y;i<=m;i++)
	{
		cin>>x>>y;
		while (T.GetData(x).top!=T.GetData(y).top)
		{
			if (T.GetData(x).depth>=(T.GetData(y).depth))
				x=T.GetData(x).father;
			else
			 	y=T.GetData(y).father;
		}
		cout<<(T.GetData(x).depth<T.GetData(y).depth?x:y)<<endl;
	}
	return 0;
}
