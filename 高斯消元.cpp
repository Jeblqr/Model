#include<bits/stdc++.h>
#define N 101
using namespace std;


//---------------------------------------
class GaussianElimination
{
	int n;
	double A[N][N+1],ESP=1e-8;
	vector<double> ans;
	public:
		void INIT(int n);
		void SetValue(int x,int y,double k);
		void SetRoot(int x,double k);
		vector<double> Calc();
};

void GaussianElimination::INIT(int n)
{
	this->n=n;
	memset(A,0,sizeof A);
	ans.resize(n);
	ans.clear();
}

void GaussianElimination::SetValue(int x,int y,double k)
{
	A[x][y]=k;
}

void GaussianElimination::SetRoot(int x,double k)
{
	A[x][n+1]=k;
}

vector<double> GaussianElimination::Calc()
{
	for (int i=1;i<=n;i++)
	{
		int tmp=i;
		for (int j=i+1;j<=n;j++)
			if (fabs(A[j][i])>fabs(A[tmp][i]))
				tmp=j;
		if (fabs(A[tmp][i])<ESP)
		{
			cout<<"No Solution";
			exit(0);
		}
		if (tmp!=i)
			swap(A[tmp],A[i]);
		double div=A[i][i];
		for (int j=i;j<=n+1;j++)
			A[i][j]/=div;
		for (int j=i+1;j<=n;j++)
		{
			div=A[j][i];
			for (int k=i;k<=n+1;k++)
				A[j][k]-=A[i][k]*div;
		}
	}
	ans[n]=A[n][n+1];
	for (int i=n-1;i>=1;i--)
	{
		ans[i]=A[i][n+1];
		for (int j=i+1;j<=n;j++)
			ans[i]-=A[i][j]*ans[j];
	}
	for (int i=1;i<=n;i++)
		cout<<fixed<<setprecision(2)<<ans[i]<<endl;
	return ans;
}
//----------------------------------------------


GaussianElimination T;

int main()
{
	return 0;
}
