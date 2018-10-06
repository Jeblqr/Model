#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#define Max 800000
using namespace std;

//----------------------------------------
class St
{
	struct node
	{
		long long val,tag;
	};
	node Node[Max];
	inline long long L(long long x);
	inline long long R(long long x);
	inline void PushUp(long long root);
	inline void PushDown(long long root,long long l,long long r,long long k);
	inline void PushSum(long long root,long long l,long long r);
	public:
		void build(long long root,long long l,long long r,long long *a);
		void updata(long long root,long long l,long long r,long long i,long long j,long long k);
		long long query(long long root,long long l,long long r,long long i,long long j);
};




inline long long St::L(long long x){return x<<1;}

inline long long St::R(long long x){return L(x)|1;}

void St::PushUp(long long root)
{
	Node[root].val=Node[L(root)].val+Node[R(root)].val;
}

void St::PushDown(long long root,long long l,long long r,long long k)
{
	Node[root].val+=k*(r-l+1);
	Node[root].tag+=k;
}

void St::PushSum(long long root,long long l,long long r)
{
	long long mid=(l+r)/2;
	PushDown(L(root),l,mid,Node[root].tag);
	PushDown(R(root),mid+1,r,Node[root].tag);
	Node[root].tag=0;
}

void St::build(long long root,long long l,long long r,long long *a)
{
	if (l==r)
	{
		Node[root].val=a[l];
		return;
	}	
	long long mid=(l+r)/2;
	build(L(root),l,mid,a);
	build(R(root),mid+1,r,a);
	PushUp(root);
}

void St::updata(long long root,long long l,long long r,long long i,long long j,long long k)
{
	if (i<=l&&r<=j)
	{
		Node[root].val+=k*(r-l+1);
		Node[root].tag+=k;
		return;
	}
	PushSum(root,l,r);
	long long mid=(l+r)/2;
	if (i<=mid)
		updata(L(root),l,mid,i,j,k);
	if (j>mid)
		updata(R(root),mid+1,r,i,j,k);
	PushUp(root);
}

long long St::query(long long root,long long l,long long r,long long i,long long j)
{
	if (i<=l&&r<=j)
		return Node[root].val;
	PushSum(root,l,r);
	long long mid=(l+r)/2;
	long long res=0;
	if (i<=mid)
		res+=query(L(root),l,mid,i,j);
	if (j>mid)
		res+=query(R(root),mid+1,r,i,j);
	return res;
}
//----------------------------------------

St st;

int main()
{
	return 0;
}
