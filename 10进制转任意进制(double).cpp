
#include<bits/stdc++.h>
using namespace std;
void zh(int x,int y);
char s[36]={'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
int main()
{
	double a;
	int k,i=1;
	cin>>a>>k;
	zh(k,(int)a);
	cout<<".";
	while (a>0&&i<=10)
	{
		a=(a-((int)a))*k;
		int x=(int)a;
		a-=x;
		cout<<s[x];
		i++;
	}
	return 0;
}
void zh(int x,int y)
{
	if (x>y) {cout<<s[y];return;}
	int a=y%x;
	y/=x;
	zh(x,y);
	cout<<s[a];
}
