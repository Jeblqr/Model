#include<bits/stdc++.h>
using namespace std;

int n;
double ansx,ansy,ans=100000000,del=0.998;

struct Node
{
    double x,y,d;
}node[1000000];

double calc(double x,double y)
{
    double sum=0;
    for (int i=1;i<=n;i++)
    {
        double delta_x=x-node[i].x,delta_y=y-node[i].y;
        sum+=sqrt(delta_x*delta_x+delta_y*delta_y)*node[i].d;
    }
    return sum;
}

void SA()
{
    double T=200;
    while (T>1e-15)
    {
        double x=ansx+(rand()*2-RAND_MAX)*T,y=ansy+(rand()*2-RAND_MAX)*T;
        double delta=calc(x,y)-calc(ansx,ansy);
        if (delta<0)
            ansx=x,ansy=y;
        else
            if (rand()<exp(-delta/T)*RAND_MAX)
                ansx=x,ansy=y;
        T*=del;
    }
}

int main()
{
    srand(time(0));
    cin>>n;
    double x,y,d;
    for (int i=1;i<=n;i++)
        cin>>x>>y>>d,node[i]={x,y,d},ansx+=x,ansy+=y;;
    ansx/=n,ansy/=n;
    //while (1)
    {
        SA();
        cout<<fixed<<setprecision(3)<<ansx<<' '<<ansy<<endl;
    }
    
    return 0;
}
