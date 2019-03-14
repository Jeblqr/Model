#include<bits/stdc++.h>
#define N 1000001
using namespace std;


//-----------------------------------------------
class TCS
{
	protected:
		struct Node
		{
			long long x,y,next;
		};
		Node node[N];
		long long last[N],id[N],rid[N],father[N],son[N],deep[N],size[N],top[N],cnt,tot;
		long long a[N*4],lazy[N*4];
	public:
		long long w[N],ROOT,n,mod;
		void add(long long x,long long y);
		void dfs1(long long x);
		void dfs2(long long root,long long x);
		void push(long long root,long long l,long long r);
		void build(long long root,long long l,long long r);
		void update(long long root,long long l,long long r,long long L,long long R,long long k);
		long long query(long long root,long long l,long long r,long long L,long long R);
};

void TCS::add(long long x,long long y)
{
	node[++tot]={x,y,last[x]};
	last[x]=tot;
}

void TCS::dfs1(long long x)
{
	size[x]=1;
	for (long long i=last[x];i;i=node[i].next)
	{
		long long y=node[i].y;
		if (father[x]==y)
			continue;
		deep[y]=deep[x]+1;
		father[y]=x;
		dfs1(y);
		size[x]+=size[y];
		if (size[son[x]]<size[y])
			son[x]=y;
	}
}

void TCS::dfs2(long long root,long long x)
{
	if (x==0)
		return;
	top[x]=root;
	id[x]=++cnt;rid[cnt]=x;
	dfs2(root,son[x]);
	for (long long i=last[x];i;i=node[i].next)
	{
		long long y=node[i].y;
		if (father[x]==y||son[x]==y)
			continue;
		dfs2(y,y);
	} 
}

void TCS::push(long long root,long long l,long long r)
{
	long long mid=(l+r)>>1;
	lazy[root<<1]=(lazy[root<<1]+lazy[root])%mod;
	lazy[root<<1|1]=(lazy[root<<1|1]+lazy[root])%mod;
	a[root<<1]=(a[root<<1]+lazy[root]*(mid-l+1))%mod;
	a[root<<1|1]=(a[root<<1|1]+lazy[root]*(r-mid))%mod;
	lazy[root]=0;
} 

void TCS::build(long long root,long long l,long long r)
{
	if (l==r)
	{
		a[root]=w[rid[l]]%mod;
		return;
	}
	long long mid=(l+r)>>1;
	build(root<<1,l,mid);
	build(root<<1|1,mid+1,r);
	a[root]=(a[root<<1]+a[root<<1|1])%mod;
}

void TCS::update(long long root,long long l,long long r,long long L,long long R,long long k)
{
	if (L<=l&&r<=R)
	{
		lazy[root]+=k;
		a[root]=(a[root]+k*(r-l+1))%mod;
		return;
	}
	long long mid=(l+r)>>1;
	if (lazy[root])
		push(root,l,r);
	if (L<=mid)
		update(root<<1,l,mid,L,R,k);
	if (mid<R)
		update(root<<1|1,mid+1,r,L,R,k);
	a[root]=(a[root<<1]+a[root<<1|1])%mod;
}

long long TCS::query(long long root,long long l,long long r,long long L,long long R)
{
	if (L<=l&&r<=R)
		return a[root]%mod;
	long long mid=(l+r)>>1;
	if (lazy[root])
		push(root,l,r);
	long long res=0;
	if (L<=mid)
		res+=query(root<<1,l,mid,L,R);
	if (mid<R)
		res+=query(root<<1|1,mid+1,r,L,R);
	return res%mod;
}
//-----------------------------------------------

//-----------------------------------------------
class T : public TCS
{
	public:
		void init()
		{
			dfs1(ROOT);
			dfs2(ROOT,ROOT);
			build(1,1,n);
		} 
		long long qRange(long long x,long long y)
		{
			long long ans=0;
			while (top[x]!=top[y])
			{
				if (deep[top[x]]<deep[top[y]])
					swap(x,y);
				ans+=query(1,1,n,id[top[x]],id[x]);
				ans%=mod;
				x=father[top[x]];
			}
			if (deep[x]>deep[y])
				swap(x,y);
			ans+=query(1,1,n,id[x],id[y]);
			ans%=mod;
			return ans;
		}
		long long qSon(long long x)
		{
			return query(1,1,n,id[x],id[x]+size[x]-1)%mod;
		}
		void upRange(long long x,long long y,long long k)
		{
			while (top[x]!=top[y])
			{
 				if (deep[top[x]]<deep[top[y]])
					swap(x,y);
				update(1,1,n,id[top[x]],id[x],k);
				x=father[top[x]];
			}
			if (deep[x]>deep[y])
				swap(x,y);
			update(1,1,n,id[x],id[y],k);
		}
		void upSon(long long x,long long k)
		{
			update(1,1,n,id[x],id[x]+size[x]-1,k);
		}
} T;
//-----------------------------------------------


signed main()
{
	long long n,m,r,mod;
	cin>>n>>m>>r>>mod;
	T.n=n,T.mod=mod,T.ROOT=r;
	for (long long i=1;i<=n;i++)
		cin>>T.w[i];
	for (long long i=1;i<n;i++)
	{
		long long a,b;
		cin>>a>>b;
		T.add(a,b),T.add(b,a);
	}
	T.init();
	while(m--){
        long long k,x,y,z;
        cin>>k;
        if(k==1){
            cin>>x>>y>>z;
            T.upRange(x,y,z);
        }
        else if(k==2){
            cin>>x>>y;
            printf("%d\n",T.qRange(x,y));
        }
        else if(k==3){
			cin>>x>>y;
            T.upSon(x,y);
        }
        else{
        	cin>>x;
        	printf("%d\n",T.qSon(x));
        }
    }
	return 0;
} 
