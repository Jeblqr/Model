#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <sstream>
#include <string>
#include<set>
#include<cstdlib>
#define Max 1100000
using namespace std;

/*int n;
string s,l;
set<string> dic;
bool bj;

void sou(string s)
{
    if (dic.count(s))
    {
        cout<<"YES";
        //cin.get();
        //cin.get();
        exit(0);
    }
    for (int i=0;i<=s.size();i++)
    {
        if (dic.count(s.substr(0,i)))
            sou(s.substr(i,s.size()));
    }
}

int main()
{
    bj=0;
    cin>>s;
    cin>>n;
    for (int i=1;i<=n;i++)
        cin>>l,dic.insert(l);
    sou(s);
    cout<<"NO";
    //cin.get();
    //cin.get();
	return 0;
}*/



int trie[Max][60],len;
bool tbj[Max];
int calc(char c)
{
    if (c>='A'&&c<='Z')
        return c-'A';
    return c-'a'+28;
}
void insert(string s)
{
    int p=0;
    for (int i=0;i!=s.size();i++)
    {
        int x=calc(s[i]);
        if (!trie[p][x])
            trie[p][x]=++len;
        p=trie[p][x];
    }
    tbj[p]=1;
}
void find(string s)
{
    int p=0;
    for (int i=0;i!=s.size();i++)
    {
        int x=calc(s[i]);
        if (!trie[p][x])
            trie[p][x]=++len;
        p=trie[p][x];
        if (tbj[p])
        {
            find(s.substr(i+1,s.size()));
        }
    }
    if (tbj[p])
    {
        cout<<"YES";
        //cin.get();
        //cin.get();
        exit(0);
    }
}

int main()
{
    int n;
    string s,l;
    cin>>s;
    cin>>n;
    for (int i=1;i<=n;i++)
        cin>>l,insert(l);
    find(s);
    cout<<"NO";
    //cin.get();
    //cin.get();
	return 0;
}

//这题要AC自动机？？？我不会啊