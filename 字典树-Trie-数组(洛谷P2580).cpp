#include<bits/stdc++.h>;
using namespace std;
int n,m,trie[1000000][27],ts=0;
bool sum[1000000];
void in(string str)
{
    int p=0;
    for (int i=0;i!=str.size();i++)
    {
        if (trie[p][str[i]-'a']==0)
            trie[p][str[i]-'a']=++ts;
        p=trie[p][str[i]-'a'];
    }
}
string cx(string str)
{
    int p=0;
    for (int i=0;i!=str.size();i++)
    {
        if (trie[p][str[i]-'a']==0)
            return "WRONG";
        p=trie[p][str[i]-'a'];
    }
    if (sum[p]==1) return "REPEAT";
    sum[p]=1;
    return "OK";
}
int main()
{
    string str;
    cin>>n;
    for (int i=1;i<=n;i++)
    {
        cin>>str;
        in(str);
    }
    cin>>m;
    for (int i=1;i<=m;i++)
    {
        cin>>str;
        cout<<cx(str)<<endl;
    }
    return 0;
}
