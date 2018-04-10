#include<bits/stdc++.h>
using namespace std;
struct node
{
    int x,y,c;
}a[1000000];
int fa[1100000],n,m,ans,t;
bool cmp(node x,node y);
void init();
void find_answer();
int find_fa(int x);
void print();
int main()
{
    init();
    find_answer();
    print();
    return 0;
}

bool cmp(node x,node y)
{
    return (x.c<y.c);
}
int find_fa(int x)
{
    if (fa[x]!=x) fa[x]=find_fa(fa[x]);
    return fa[x];
}
void init()
{
	cin>>n>>m;
    for (int i=1;i<=n;i++)
        fa[i]=i;
    for (int i=1;i<=m;i++)
        cin>>a[i].x>>a[i].y>>a[i].c;
    sort(a+1,a+m+1,cmp);
}
void find_answer()
{
	for (int i=1;i<=m;i++)
    {
        int fx=find_fa(a[i].x);
        int fy=find_fa(a[i].y);
        if (fx!=fy)
        { 
            fa[fx]=fy;
            ans+=a[i].c;
            t++;
            if (t==n-1) break;
        }
    }
}
void print()
{
	cout<<ans;
}
