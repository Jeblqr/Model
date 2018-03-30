#include<bits/stdc++.h>
using namespace std;
int F[1000][1000];
int main()
{
	string a,b;
	cin>>a>>b;
	int al=a.length(),bl=b.length();
	for (int i=1;i<=al;i++)
		for (int j=1;j<=bl;j++)
		{
			F[i][j]=max(F[i-1][j],F[i][j-1]);
			if (a[i-1]==b[j-1])
				F[i][j]=(F[i][j],F[i-1][j-1]+1);
		}
	cout<<F[al][bl];
	return 0;
}
