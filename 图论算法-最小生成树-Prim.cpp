#include <iostream>
#include <cstring>
#include <cstdio>
#include <string>
#include <cstdlib>
#include <algorithm>
#include <set>
#include <queue>
#include <vector>
#include <map>
#define Max 1200
using namespace std;


class Prim
{
    int edge[Max][Max],n,m,k2[Max];
    bool k1[Max];
    public:
        void init();
        int GetAns();
};

void Prim::init()
{
    memset(edge,0x7f,sizeof edge);
    memset(k1,0,sizeof k1);
    memset(k2,0,sizeof k2);
    cin>>n>>m;
    int x,y,c;
    for (int i=1;i<=m;i++)
    {
        cin>>x>>y>>c;
        if (edge[x][y]>c)
            edge[x][y]=edge[y][x]=c;
    }
    for (int i=1;i<=n;i++)
        k2[i]=edge[1][i];
    k1[1]=1;
}

int Prim::GetAns()
{
    int k=1,ans=0;
    while (k<n)
    {
        k++;
        int minn=1<<26,p=0;
        for (int i=1;i<=n;i++)
            if (!k1[i]&&k2[i]<minn)
                minn=k2[i],p=i;
        ans+=minn;
        for (int i=1;i<=n;i++)
            if (!k1[i]&&k2[i]>edge[p][i])
                k2[i]=edge[p][i];
        k1[p]=1;
    }
    return ans;
}


Prim prim;

int main()
{
	return 0;
}
