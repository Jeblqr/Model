#include<iostream>
#include<string>
#include<cstring>
#include<algorithm>
#define Max 1000
using namespace std;

class HAA
{
	bool IsF;
	short num[Max];
	int len;
	int max(int a, int b);
public:
	HAA();
	void init();
	HAA operator+ (HAA x);
	HAA operator- (HAA y);
	HAA operator* (HAA x);
	HAA operator/ (HAA x);
	void operator= (std::string s);
	void operator= (long long s);
	bool operator== (const HAA &x) const;
	bool operator> (const HAA &x) const;
	bool operator< (const HAA &x) const;
	void scan();
	void print();
	friend istream &operator>>(istream &in,HAA &x);
	friend ostream &operator<<(ostream &out,HAA &x);
};


int HAA::max(int a, int b)
{
	return a >= b ? a : b;
}

HAA::HAA()
{
	memset(num,0,sizeof num);
	len=0;
	IsF=0;
}

void HAA::init()
{
	memset(num,0,sizeof num);
	len=0;
	IsF=0;
}

HAA HAA::operator+ (HAA x)
{
	HAA tmp;
	if (IsF!=x.IsF)
	{
		tmp=*this,tmp.IsF=0;
		return x-tmp;
	}		
	tmp.len = max(x.len, len)+10;
	for (int i = 1; i <= max(x.len, len); i++)
		tmp.num[i] += num[i] + x.num[i], tmp.num[i + 1] += tmp.num[i] / 10, tmp.num[i] %= 10;
	while (!tmp.num[tmp.len]&&tmp.len)
		tmp.len--;
	if (IsF==1)
		tmp.IsF=1;
	return tmp;
}

HAA HAA::operator- (HAA y)
{
	if (y.IsF==1)
	{
		y.IsF=0;
		return *this+y;
	}	
	HAA tmp,x=*this;
	if (IsF==1)
	{
		x.IsF=0;
		tmp=x+y;
		tmp.IsF=1;
		return tmp;
	}
	if (x<y)
		tmp=x,x=y,y=tmp,tmp.init(),tmp.IsF=1;
	tmp.len = max(x.len, y.len)+10;
	for (int i = 1; i <= max(x.len, y.len); i++)
	{
		if (x.num[i]<y.num[i])
			x.num[i]+=10,x.num[i+1]--;
		tmp.num[i]=x.num[i]-y.num[i];
	}
	while (!tmp.num[tmp.len]&&tmp.len)
		tmp.len--;
	return tmp;
}

HAA HAA::operator* (HAA x)
{
	HAA tmp;
	tmp.len = x.len+len;
	for (int i = 1; i <= len; i++)
	{
		int k=0;
		for (int j=1;j<=x.len;j++)
		{
			tmp.num[i+j-1]+=k+num[i]*x.num[j];
			k=tmp.num[i+j-1]/10;
			tmp.num[i+j-1]%=10;
		}
		tmp.num[i+x.len]+=k;
	}
	while (!tmp.num[tmp.len]&&tmp.len)
		tmp.len--;
	if (x.IsF!=IsF)
		tmp.IsF=1;
	return tmp;
}

HAA HAA::operator/ (HAA x)
{}

bool HAA::operator== (const HAA &x) const
{
	if (x.IsF!=IsF)
		return 0;
	if (len!=x.len)
		return 0;
	for (int i=1;i<=len;i++)
		if (num[i]!=x.num[i])
			return 0;
	return 1;
}

bool HAA::operator> (const HAA &x) const
{
	if (x.IsF!=IsF)
		return x.IsF;
	if (x.IsF==1)
	{
		if (len!=x.len)
			return len<x.len;
		for (int i=1;i<=len;i++)
			if (num[i]!=x.num[i])
				return num[i]<x.num[i];
		return 0;
	}
	if (len!=x.len)
		return len>x.len;
	for (int i=1;i<=len;i++)
		if (num[i]!=x.num[i])
			return num[i]>x.num[i];
	return 0;
}

bool HAA::operator< (const HAA &x) const
{
	if (x.IsF!=IsF)
		return IsF;
	if (x.IsF==1)
	{
		if (len!=x.len)
			return len>x.len;
		for (int i=1;i<=len;i++)
			if (num[i]!=x.num[i])
				return num[i]>x.num[i];
		return 0;
	}
	if (len!=x.len)
		return len<x.len;
	for (int i=1;i<=len;i++)
		if (num[i]!=x.num[i])
			return num[i]<x.num[i];
	return 0;
}

void HAA::operator= (string s)
{
	init();
	if (s[0]=='-')
		IsF=1;
	while (s[0]=='0')
		s=s.substr(1,s.size());
	if (s[0]=='-')
		IsF=1,s=s.substr(1,s.size());;
	len = s.size();
	for (int i = 0; i != s.size(); i++)
		num[len - i] = s[i] - '0';
}

void HAA::operator= (long long s)
{
	init();
	if (s<0)
		IsF=1,s*=-1;
	len = 0;
	while(s)
		num[++len] = s % 10,s/=10;
}

void HAA::scan()
{
	string s;
	cin >> s;
	*this = s;
}

void HAA::print()
{
	if (len==0)
		cout<<0;
	if (IsF)
		cout<<'-';
	for (int i = len; i >= 1; i--)
		cout << num[i];
}

istream &operator>>(istream &in,HAA &x)
{
	x.scan();
	return in;
}

ostream &operator<<(ostream &out,HAA &x)
{
	x.print();
	return out;
}

HAA a, b, c, d, e;

int main()
{
	return 0;
}
