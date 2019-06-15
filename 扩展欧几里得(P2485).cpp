#include<bits/stdc++.h>// BSGS can't be learnt
using namespace std;

long long exgcd(long long a,long long b,long long &x,long long &y)// Ax + By = gcd(A,B)
{
    if (b==0)
    {
        x=1,y=0;
        return a;
    }
    long long d=exgcd(b,a%b,x,y);
    long long k=x;
    x=y,y=k-(a/b)*y;
    return d;
}

long long quicklyPower(long long a,long long b,long long p)// A^B mod P
{
    long long ans=1;
    while (b)
    {
        if (b&1)
            ans=(ans*a)%p;
        a=(a*a)%p;
        b>>=1;
    }
    return ans;
} 

long long LCE(long long a,long long b,long long p)// Ax ≡ B (mod P) 
{
    long long x=0,y=0;
    long long gcd=exgcd(a,p,x,y);
    if (b%gcd)
        return -1;
    long long temp=p/gcd;
    while (x<0)
        x+=temp;
    long long ans=((x*b)%temp+temp)%temp;
    return ans;
}

signed main()
{
    long long op,T,a,b,p;
    cin>>T>>op;
    if (op==1)
    {
        while (T--)
        {
            cin>>a>>b>>p;
            cout<<quicklyPower(a,b,p)<<endl;
        }
    } 
    if (op==2)
    {
        while (T--)
        {
            cin>>a>>b>>p;
            long long ans=LCE(a,b,p);
            if (ans==-1)
                cout<<"Orz, I cannot find x!"<<endl;
            else
                cout<<ans<<endl;
        }
    } 
    return 0;
}
