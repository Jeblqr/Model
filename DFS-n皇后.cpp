#include<iostream>
#include<iomanip>
#include<cstring>
#include<algorithm>
#include<cstdio>
#include<cmath>
int k,g;
bool map[100][100],bj1[100],bj2[100],bj3[100],bj4[100];
using namespace std;
void init();
void dfs(int i);
void cc();
int main()
{
    init();
    dfs(1);
    cout<<g;
    return 0;
}
void init()
{
    memset(bj1,0,sizeof(bj1));
    memset(bj2,0,sizeof(bj2));
    memset(bj3,0,sizeof(bj3));
    memset(bj4,0,sizeof(bj4));
    memset(map,0,sizeof(map));
    cin>>k;
}
void dfs(int i)
{
    for (int j=1;j<=k;j++)
    {
        if (map[i][j]==0&&bj1[i+j]==0&&bj3[i]==0&&bj4[j]==0&&bj2[i-j+k+1]==0)
        {
        	bj3[i]=1;
            bj4[j]=1;
            map[i][j]=1;
            bj1[i+j]=1;
            bj2[i-j+k+1]=1;
            if (i==k)
            	cc();
            else
            	dfs(i+1);
            map[i][j]=0;
            bj1[i+j]=0;
            bj2[i-j+k+1]=0;
            bj3[i]=0;
            bj4[j]=0;
        }
    }
}
void cc()
{
    g++;
    if (g<=3)
    {
        for (int i=1;i<=k;i++)
            for (int j=1;j<=k;j++)
            {
                if (map[i][j]==1) 
                {
                    cout<<j<<' ';
                    break;
                }
            }
        cout<<endl;
    }
}
