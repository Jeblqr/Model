#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <sstream>
#include <string>
#include<set>
#include<cstdlib>
#define Max1 110000
#define Max2 110
using namespace std;

bool z[Max1][Max2];
int n,m,k;
//long long ans=92233720367;
//int zs[Max1];

/*void dg(int h,int g,int zz,int y)
{

    if (g==k)
    {
        int k=0;
        for (int i=h;i<=n;i++)
            k+=zs[i];
        ans=min(ans,zz+k);
        return;
    }
    if (h>n)
        return;
    
    if ((!z[h][1])&&(!z[h][2]))
    {
        int i=0,gg=0;
        for(int ii=m;ii>=3;ii--)
            if (z[h][ii])
            {
                h=ii;
                break;
            }
            else
                gg++;
        for (int ii=3;ii<h;ii++)
            if (!z[h][ii])
                i++;
        dg(h+1,g+1,zz+i,gg);
        dg(h+1,g,zz+i+y+2,gg);
		return; 
    }
    int i=0,gg=0;
    for(int ii=m;ii>=1;ii--)
        if (z[h][ii])
        {
            h=ii;
            break;
        }
        else
            gg++;
    for (int ii=1;ii<h;ii++)
        if (!z[h][ii])
            i++;
    dg(h+1,g,zz+i+y,gg);    
}

int main()
{
    cin>>n>>m>>k;
    for (int i=1;i<=n;i++)
    {
        for (int j=1;j<=m;j++)
        {
            cin>>z[i][j];
            if (z[i][j]==0)
                zs[i]++;
        } 
    }
    dg(1,0,0,0);
    cout<<ans;
	return 0;
}*/

int main()
{
    cin>>n>>m>>k;
    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++)
            cin>>z[i][j];
    
	return 0;
}

//不会啊。。。