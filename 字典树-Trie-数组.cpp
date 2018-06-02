#include<bits/stdc++.h>
using namespace std;
int t_s=1,t[1000000][27];
bool tl[1000000];
void ins(string s)
{
	int n=1;
	for (int i=0;i!=s.size();i++)
	{
		if (t[n][s[i]-'a']==0)	t[n][s[i]-'a']=++t_s;
		n=t[n][s[i]-'a'];
	}
	tl[n]=1;
}
string f(string s)
{
	int n=1;
	for (int i=0;i!=s.size();i++)
	{
		if (t[n][s[i]-'a']==0)	return "No?";
		n=t[n][s[i]-'a'];
	}
	if (tl[n])
		return "Oh! Yes!";
	else
		return "No?";
}
int main()
{
	int k;
	cin>>k;
	string s;
	while (k--)
		cin>>s,ins(s);
	while (cin>>s)
	{
		cout<<f(s)<<endl;
	}
}
