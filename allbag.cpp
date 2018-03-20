#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,m,w[1000],c[1000],f[1000];
	cin>>m>>n;
	for (int i=1;i<=n;i++) cin>>w[i]>>c[i];
	for (int i=1;i<=n;i++)
		for (int j=w[i];j<=m;j++)
			if (f[j-w[i]]+c[i]>f[j]) f[j]=f[j-w[i]]+c[i];
	cout<<"max="<<f[m];
	return 0;
}
