//#pragma GCC optimize(3)
//#define NDEBUG
#include<iostream>
#include<cstring>
#include<cstdio>
#include<string>
#include<cstdlib>
#include<algorithm>
#include<set>
#include<cmath>
#include<iomanip>
#include<vector>
#include<map>
#include<stack>
#include<queue>
using namespace std;

string ZzToHz(string s)
{
    string ans;
    stack<pair<int,char> > st;
    for (int i=0;i!=s.size();i++)
    {
        switch (s[i])
        {
            case '(':
                st.push(make_pair(100,s[i]));
                break;
            case ')':
                while (st.size()&&st.top().second!='(')
                {
                	ans=ans+st.top().second+' ';
                    st.pop();
                }
                st.pop();
                break;
            case '+':
                while (st.size()&&st.top().first>=1&&st.top().second!='(')
                {
                	ans=ans+st.top().second+' ';
                    st.pop();
                }
                st.push(make_pair(1,s[i]));
                break;
            case '-':
                while (st.size()&&st.top().first>=1&&st.top().second!='(')
                {
                	ans=ans+st.top().second+' ';
                    st.pop();
                }     
                st.push(make_pair(1,s[i]));
                break;
            case '*':
                while (st.size()&&st.top().first>=2&&st.top().second!='(')
                {
                	ans=ans+st.top().second+' ';
                    st.pop();
                }
                st.push(make_pair(2,s[i]));
                break;	
            case '/':
                while (st.size()&&st.top().first>=2&&st.top().second!='(')
                {
                	ans=ans+st.top().second+' ';
                    st.pop();
                }         
                st.push(make_pair(2,s[i]));
                break;
            case '^':
            	while (st.size()&&st.top().first>=3&&st.top().second!='(')
                {
                	ans=ans+st.top().second+' ';
                    st.pop();
                }         
                st.push(make_pair(3,s[i]));
                break;
            default:
                ans.push_back(s[i]);
                break;	
        }
    }
    while (st.size())
    {
    	ans.push_back(st.top().second);
        st.pop();
    } 
    return ans;
}

void Clop(stack<int> &st,char op)
{
    int x,y;
    x=st.top();
    st.pop();
    y=st.top();
    st.pop();
    switch (op)
    {
        case '+':
            st.push(y+x);
            break;
        case '-':
            st.push(y-x);
            break;
        case '*':
            st.push(y*x);
            break;
        case '/':
            st.push(y/x);
            break;
        case '^':
            st.push(pow(y,x));
            break;
    }
}

int Calc(string s)
{
    stack<int> st;
    int l=0;
    for (int i=0;i!=s.size();i++)
    {
        if (s[i]==' ')
            continue;
        if (s[i]>='0'&&s[i]<='9')
            st.push(s[i]-'0');
        else
            Clop(st,s[i]);
        
    }
    return st.top();
}
int main()
{
    return 0;
}
