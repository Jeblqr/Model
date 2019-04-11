#include<iostream>
#include<cmath>
using namespace std;

namespace Complex_
{
	struct Complex
	{
		double a,b;
		Complex();
		Complex(double a,double b);
	};
	
	Complex::Complex() {}
	
	Complex::Complex(double a,double b):a(a),b(b) {}
	
	Complex operator+(Complex x,Complex y)
	{
		return Complex{x.a+y.a,x.b+y.b};
	}
	
	Complex operator-(Complex x,Complex y)
	{
		return Complex{x.a-y.a,x.b-y.b};
	}
	
	Complex operator*(Complex x,Complex y)
	{
		return Complex{x.a*y.a-x.b*y.b,x.a*y.b+y.a*x.b};
	}
	
	Complex operator/(Complex x,Complex y)
	{
		return Complex{(x.a*y.a+x.b*y.b)/(y.a*y.b),(x.b*y.a-x.a*y.b)/(y.a*y.b)};
	}
}

using namespace Complex_;

namespace FFT
{
	#define Pi 3.1415926536
	void fft(Complex *A,int *R,int flag,int limit)
	{
		for (int i=0;i<limit;i++)
			if (i<R[i])
				swap(A[i],A[R[i]]);
		for (int mid=1;mid<limit;mid<<=1)
		{
			Complex Wn(cos(Pi/mid),flag*sin(Pi/mid));
			for (int j=0,r=mid<<1;j<limit;j+=r)
			{
				Complex w(1,0);
				for (int k=0;k<mid;k++)
				{
					Complex x=A[j+k],y=w*A[j+mid+k];
					A[j+k]=x+y,A[j+k+mid]=x-y;
					w=w*Wn;
				}
			}
		}
	}
}

using namespace FFT;

const int MAXN = 1e7+10;
int R[MAXN],l,limit=1;
Complex A[MAXN],B[MAXN];

int main()
{
	int n,m;
	cin>>n>>m;
	for (int i=0;i<=n;i++)
		cin>>A[i].a;
	for (int i=0;i<=m;i++)
		cin>>B[i].a;
	while (limit<=n+m)
		limit<<=1,l++;
	for (int i=0;i<limit;i++)
		R[i]=((R[i>>1]>>1)|((i&1)<<(l-1)));
	fft(A,R,1,limit);
	fft(B,R,1,limit);
	for (int i=0;i<=limit;i++)
		A[i]=A[i]*B[i];
	fft(A,R,-1,limit);
	for (int i=0;i<=n+m;i++)
		cout<<int(A[i].a/limit+0.5)<<' ';
	return 0;
}
