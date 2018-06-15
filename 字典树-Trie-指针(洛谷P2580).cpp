#include<cstring>
#include<iostream>
#include<string>
using namespace std;
class node
{
    public:
        node()
        {
            for (int i=0;i!=27;i++)
            kid[i]=NULL,kg[i]=-1;
        }
        node *kid[27];
        int kg[27];
}*root,*t,*p;
void init()
{
    root=t=p=new node;
}
void insert(string str)
{
    p=root;
    for (int i=0;i!=str.size();i++)
    {
        if (p->kid[str[i]-'a']==NULL) 
            p->kid[str[i]-'a']=new node;
        p=p->kid[str[i]-'a'];	
    }
    p->kg[str[str.size()-1]-'a']=0;
}
string find(string str)
{
    p=root;
    for (int i=0;i!=str.size();i++)
    {
        if (p->kid[str[i]-'a']==NULL) 
            return "WRONG";
        p=p->kid[str[i]-'a'];	
    }
    if (p->kg[str[str.size()-1]-'a']==1)
            return "REPEAT";
    if (p->kg[str[str.size()-1]-'a']==-1)
        return "WRONG";
    p->kg[str[str.size()-1]-'a']=1;
    return "OK";
}
int main()
{
    init();
    string str;
    int n,m;
    cin>>n;
    for (int i=1;i<=n;i++)
    {
        cin>>str;
        insert(str);
    }
    cin>>m; 
    for (int i=1;i<=m;i++)
    {
        cin>>str;
        cout<<find(str)<<endl;
    }
    return 0;
}
