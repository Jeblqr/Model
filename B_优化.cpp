#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <sstream>
#include <string>
#include<iomanip>
#define Max 30
using namespace std;
bool a[Max][Max];
long long ans1,ans2;
void dg(int k1,int k2,int f)
{
    for (int i=2;i<=f+1;i++)
        for (int ii=1;ii<=f-i+2;ii++)
            if (a[i-1][ii]==a[i-1][ii+1])
                a[i][ii]=0,k1++;
            else    
                a[i][ii]=1,k2++;
    if (k1==k2)
        ans1++;
    else
        ans2++;
}
void sc(int k,int f,int k1,int k2)
{
	a[1][k]=0;
	if (k==f)
		dg(k1+1,k2,f-1);
	else	
		sc(k+1,f,k1+1,k2);
	a[1][k]=1;
	if (k==f)
		dg(k1,k2+1,f-1);
	else	
		sc(k+1,f,k1,k2+1);
}
void HowMany(int k)
{
	memset(a,0,sizeof a);
	ans1=ans2=0;
	sc(1,k,0,0);
}
int main() {
  for (int i=2;i<=23;i++)
  {
      HowMany(i);
      cout<<"n="<<i<<": ";
      cout<<fixed<<setw(10)<<"WM(n)="<<ans1<<"     BWM(n)="<<ans2<<"     Sum(n)="<<ans2+ans1<<endl;
  }
  cin.get();
  cin.get();
  return 0;
}

/*
n=2:      WM(n)=0          BWM(n)=4           Sum(n)=4
n=3:      WM(n)=4          BWM(n)=4           Sum(n)=8
n=4:      WM(n)=6          BWM(n)=10          Sum(n)=16
n=5:      WM(n)=0          BWM(n)=32          Sum(n)=32
n=6:      WM(n)=0          BWM(n)=64          Sum(n)=64
n=7:      WM(n)=12         BWM(n)=116         Sum(n)=128
n=8:      WM(n)=40         BWM(n)=216         Sum(n)=256
n=9:      WM(n)=0          BWM(n)=512         Sum(n)=512
n=10:     WM(n)=0          BWM(n)=1024        Sum(n)=1024
n=11:     WM(n)=171        BWM(n)=1877        Sum(n)=2048
n=12:     WM(n)=410        BWM(n)=3686        Sum(n)=4096
n=13:     WM(n)=0          BWM(n)=8192        Sum(n)=8192
n=14:     WM(n)=0          BWM(n)=16384       Sum(n)=16384
n=15:     WM(n)=1896       BWM(n)=30872       Sum(n)=32768
n=16:     WM(n)=5160       BWM(n)=60376       Sum(n)=65536
n=17:     WM(n)=0          BWM(n)=131072      Sum(n)=131072
n=18:     WM(n)=0          BWM(n)=262144      Sum(n)=262144
n=19:     WM(n)=32757      BWM(n)=491531      Sum(n)=524288
n=20:     WM(n)=59984      BWM(n)=988592      Sum(n)=1048576
n=21:     WM(n)=0          BWM(n)=2097152     Sum(n)=2097152
n=22:     WM(n)=0          BWM(n)=4194304     Sum(n)=4194304
n=23:     WM(n)=431095     BWM(n)=7957513     Sum(n)=8388608
*/