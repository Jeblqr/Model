#include<bits/stdc++.h>
using namespace std;

void getMu(long long n,long long *mu,long long *primes)
{
    bool prime[1000001];
    long long cnt=0;
    memset(mu,0,sizeof mu);
    memset(prime,1,sizeof prime);
    memset(primes,0,sizeof primes);
    prime[1]=0;
    mu[1]=1;
    for (long long i=2;i<=n;i++)
    {
        if (prime[i])
            primes[++cnt]=i,mu[i]=-1;
        for (long long j=1;j<=cnt&&i*primes[j]<=n;j++)
        {
            prime[i*primes[j]]=0;
            if (i%primes[j]==0)
            {
                mu[i*primes[j]]=0;
                break;
            }
            mu[i*primes[j]]=mu[i]*mu[primes[j]];
        }
    }
}

long long sum[1000001];
long long mu[1000001],primes[1000001];

signed main()
{
    getMu(50000,mu,primes);
    for (long long i=1;i<=50000;i++)
        sum[i]=sum[i-1]+mu[i];
    long long T;
    cin>>T;
    while (T-->0)
    {
        long long a,b,x,ans=0;
        cin>>a>>b>>x;
        if (a>b)
            swap(a,b);
        a/=x,b/=x;
        for (long long l=1,r;l<=a;l=r+1)
        {
            r=min(a/(a/l),b/(b/l));
            ans+=(sum[r]-sum[l-1])*(a/l)*(b/l);
        }
        cout<<ans<<endl;
    }
    return 0;
}
