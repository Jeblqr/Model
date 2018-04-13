#include<bits/stdc++.h>
using namespace std;
int main()
{
	int m,n,w[10000],c[1000],f[10000];
	cin>>m>>n;
	for (int i=1;i<=n;i++) cin>>w[i]>>c[i];
	for (int i=1;i<=n;i++)
		for (int j=m;j>=w[i];j--)
			if (f[j-w[i]]+c[i]>f[j])  f[j]=f[j-w[i]]+c[i];
	cout<<f[m];	
	return 0;
}
