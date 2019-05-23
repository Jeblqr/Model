#include<bits/stdc++.h>
using namespace std;


//------------------------------
class Manacher
{
	string s;
	vector<int> hw;
	string change(const string& _s);
	public:
		vector<int> operator()(const string& _s);
};

string Manacher::change(const string& _s)
{
	string s;
	s.resize(_s.size()*2+3);
	s[0]=s[1]='#';
	int len=_s.size();
	for (int i=0;i!=len;i++)
		s[i*2+2]=_s[i],s[i*2+3]='#';
	return s;
}

vector<int> Manacher::operator()(const string& _s)
{
	s=change(_s);
	hw.resize(s.size());
	int maxr=0,mid=0,len=s.size();
	for (int i=1;i!=len;i++)
	{
		if (i<maxr)
			hw[i]=min(hw[mid*2-i],hw[mid]+mid-i);
		else
			hw[i]=1;//一个字符就是一个回文串 
		while (s[i-hw[i]]==s[i+hw[i]])
		//以i为mid，i-hw[i]为左端点的上一个， i+hw[i]为右端点的下一个
			hw[i]++;
		if (hw[i]+i>maxr)//右端点比最大的右端点（maxr）长 
			maxr=hw[i]+i,mid=i;
	}
	return hw;
}
//------------------------------


int main()
{
	string s;
	cin>>s;
	Manacher T;
	vector<int> vec=T(s);
	int ans=1;
	for (auto i:vec)
		ans=max(ans,i);
	cout<<ans-1;
	return 0;
}
