#include<iostream>
#include<cstdio>
using namespace std;
void zh(int x,int y);
char b[16]={'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
int main()
{
	
	int x;
	int y;
	cin>>x>>y;
	zh(x,y);
	return 0;
}
void zh(int x,int y)
{
	if (x>y) {cout<<b[y];return;}
	int a=y%x;
	y/=x;
	zh(x,y);
	cout<<b[a];
}
