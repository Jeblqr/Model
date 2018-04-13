#include<bits/stdc++.h>
using namespace std;
void kmp(string s1,string s2);
void getnext(string s,int next[]);
int main()
{
    //freopen("in.txt","r",stdin);
    string s1,s2;
    cin>>s1>>s2;
    kmp(s1,s2);
    return 0;
}
void kmp(string s1,string s2)
{
    int next[100000];
    getnext(s2,next);
    int i=0,j=0,ls1=s1.size(),ls2=s2.size();
    while (i<ls1&&j<ls2)
    {
        if (j==-1||s1[i]==s2[j]) i++,j++;
        else j=next[j];
        if (j==ls2)
        {
            cout<<i-j+1<<' '<<i-j+ls2;
            return;
        }
    }
    cout<<"NO";
    return;
     
}
void getnext(string s,int next[])
{
    int i=0,j=-1,ls=s.size();
    next[0]=-1;
    while (i<ls)
    {
        if (j==-1||s[i]==s[j]) i++,j++,next[i]=j;
        else j=next[j];
    }
}#include<bits/stdc++.h>
using namespace std;
void kmp(string s1,string s2);
void getnext(string s,int next[]);
int main()
{
    //freopen("in.txt","r",stdin);
    string s1,s2;
    cin>>s1>>s2;
    kmp(s1,s2);
    return 0;
}
void kmp(string s1,string s2)
{
    int next[100000];
    getnext(s2,next);
    int i=0,j=0,ls1=s1.size(),ls2=s2.size();
    while (i<ls1&&j<ls2)
    {
        if (j==-1||s1[i]==s2[j]) i++,j++;
        else j=next[j];
        if (j==ls2)
        {
            cout<<i-j+1<<' '<<i-j+ls2;
            return;
        }
    }
    cout<<"NO";
    return;
     
}
void getnext(string s,int next[])
{
    int i=0,j=-1,ls=s.size();
    next[0]=-1;
    while (i<ls)
    {
        if (j==-1||s[i]==s[j]) i++,j++,next[i]=j;
        else j=next[j];
    }
}
