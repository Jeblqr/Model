#include<bits/stdc++.h>
using namespace std;
int F[10001][5],l=0,k=0;
int main()
{
	memset(F,0,sizeof(F));
	int n;
	cin>>n;
	for (int i=1;i<=n;i++)
	{
		cin>>F[i][1];
		F[i][2]=1;
		F[i][3]=0;
		
	}
	for (int i=n-1;i>=1;i--)
	{
		l=k=0;
		for (int j=i+1;j<=n;j++)
		{
			
			if ((F[j][1]>=F[i][1])&&(F[j][2]>l))
			{
				l=F[j][2];
				k=j;
			}
		}
		if (l>0)
		{
			F[i][2]=l+1;
			F[i][3]=k;
		}
	}
	k=0;
	for (int i=1;i<=n;i++)
	{
		if (F[i][2]>F[k][2]) k=i;
	}	
	cout<<"max="<<F[k][2]<<endl;
	while (k!=0)
	{
		cout<<F[k][1]<<' ';
		k=F[k][3];
	}
	return 0;
}
