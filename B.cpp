#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <sstream>
#include <string>
#define Max 30
using namespace std;
long long a[Max]={0,0,0,4,6,0,0,12,40,0,0,171,410,0,0,1896,5160,0,0,32757,59984,0,0,431095};
/*bool a[Max][Max];
long long ans;
void dg(int c,int k1,int k2,int f)
{
	if (f==0)
	{
		if (k1==k2)
			ans++;
		return;
	}
	for (int i=1;i<=f;i++)
	{
		if (a[c-1][i]==a[c-1][i+1])
			k1++,a[c][i]=0;
		else	
			k2++,a[c][i]=1;
	}
	dg(c+1,k1,k2,f-1);
}
void sc(int k,int f,int k1,int k2)
{
	a[1][k]=0;
	if (k==f)
		dg(2,k1+1,k2,f-1);
	else	
		sc(k+1,f,k1+1,k2);
	a[1][k]=1;
	if (k==f)
		dg(2,k1,k2+1,f-1);
	else	
		sc(k+1,f,k1,k2+1);
}
long long HowMany(int k)
{
	memset(a,0,sizeof a);
	ans=0;
	sc(1,k,0,0);
	return ans;
}
int main() {
  cout<<0;
  for (int i=2;i<=23;i++)
  cout<<','<<HowMany(i);
  cin.get();
  cin.get();
  return 0;
}*/
int main()
{
	int n;
	cin>>n;
	cout<<a[n];
	//cin.get();
    //cin.get();
	return 0;
}