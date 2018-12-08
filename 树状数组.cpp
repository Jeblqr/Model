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
#define N 100000000
using namespace std;


//--------------------------------
template <typename T> class BIT
{
    T *tree;
    unsigned long long n;
    BIT();
    inline unsigned long long lowbit(unsigned long long x);
    public:
        BIT(unsigned long long x);
        void Clear();
        void Add(unsigned long long k,T x);
        T Query(unsigned long long k);
};
  
template <typename T> inline unsigned long long BIT<T>::lowbit(unsigned long long x)
{
    return x&(-x);
}
  
template <typename T> BIT<T>::BIT(unsigned long long x):n(x)
{
    tree=(int*) malloc(sizeof(T) * x);
    memset(tree,0,sizeof(T) * n);
}
  
template <typename T> void BIT<T>::Clear()
{
    memset(tree,0,sizeof(T) * n);
}
  
template <typename T> void BIT<T>::Add(unsigned long long k,T x)
{
    for (unsigned long long i=k;i<=n;i+=lowbit(i))
        tree[i]+=x;
}
  
template <typename T> T BIT<T>::Query(unsigned long long k)
{
    T ans=0;
    for (unsigned long long i=k;i>0;i-=lowbit(i))
        ans+=tree[i];
    return ans;
}
//----------------------------------------


BIT<int> bit(N);
int main()
{
	return 0;
}
