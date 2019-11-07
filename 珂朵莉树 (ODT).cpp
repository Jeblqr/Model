#include <bits/stdc++.h>
using namespace std;

class ChthollyTree
{
protected:
#define Maxn 200000001
	struct Node
	{
		int l, r;
		mutable long long val;
		bool operator<(const Node &t) const
		{
			return l < t.l;
		};
	};
	set<Node> st;
	set<Node>::iterator split(int pos);

public:
	void assign(int l, int r, long long val);
};

set<ChthollyTree::Node>::iterator ChthollyTree::split(int pos)
{
	set<Node>::iterator it = st.lower_bound(Node{pos, -1, 0});
	if (it != st.end() && it->l == pos)
		return it;
	it--;
	Node tmp = *it;
	st.erase(it);
	st.insert(Node{tmp.l, pos - 1, tmp.val});
	return st.insert(Node{pos, tmp.r, tmp.val}).first;
}

void ChthollyTree::assign(int l, int r, long long val)
{
	set<Node>::iterator it_r = split(r + 1), it_l = split(l);
	st.erase(it_l, it_r);
	st.insert(Node{l, r, val});
}

class T : protected ChthollyTree
{
private:
	long long power(long long a, long long b, long long mod)
	{
		long long ans = 1;
		a %= mod;
		while (b)
		{
			if (b & 1)
				ans = ans * a % mod;
			a = a * a % mod;
			b >>= 1;
		}
		return ans;
	}

public:
	void assign(int l, int r, long long val)
	{
		set<Node>::iterator it_r = split(r + 1), it_l = split(l);
		st.erase(it_l, it_r);
		st.insert(Node{l, r, val});
	}
	void insert(int l, int r, long long val)
	{
		st.insert(Node{l, r, val});
	}
	void add(int l, int r, int val)
	{
		set<Node>::iterator it_r = split(r + 1), it_l = split(l);
		for (; it_l != it_r; it_l++)
			it_l->val += val;
	}
	long long find_kth(int l, int r, int k)
	{
		set<Node>::iterator it_r = split(r + 1), it_l = split(l);
		vector<pair<long long, int>> vec;
		for (; it_l != it_r; it_l++)
			vec.push_back(make_pair(it_l->val, it_l->r - it_l->l + 1));
		sort(vec.begin(), vec.end());
		for (vector<pair<long long, int>>::iterator it = vec.begin(); it != vec.end(); it++)
		{
			k -= it->second;
			if (k <= 0)
				return it->first;
		}
		return -1LL;
	}
	long long power(int l, int r, int x, int mod)
	{
		set<Node>::iterator it_r = split(r + 1), it_l = split(l);
		long long ans = 0;
		for (; it_l != it_r; it_l++)
		ans = (ans + ((long long)(it_l->r - it_l->l + 1)) * power(it_l->val, (long long)x, (long long)mod)) % mod;
		return ans;
	}
};

T t;

typedef long long LL;
const int MOD7 = 1e9 + 7;
const int MOD9 = 1e9 + 9;
const int imax_n = 1e5 + 7;
int n, m;
LL seed, vmax;

LL rnd()
{
	LL ret = seed;
	seed = (seed * 7 + 13) % MOD7;
	return ret;
}

LL a[imax_n];

int main()
{
	auto aaa=1;
	scanf("%d %d %lld %lld", &n, &m, &seed, &vmax);
	for (int i = 1; i <= n; ++i)
	{
		a[i] = (rnd() % vmax) + 1;
		t.insert(i, i, a[i]);
	}
	t.insert(n+1, n+1, 0);
	int lines = 0;
	for (int i = 1; i <= m; ++i)
	{
		int op = int(rnd() % 4) + 1;
		int l = int(rnd() % n) + 1;
		int r = int(rnd() % n) + 1;
		if (l > r)
			std::swap(l, r);
		int x, y;
		if (op == 3)
			x = int(rnd() % (r - l + 1)) + 1;
		else
			x = int(rnd() % vmax) + 1;
		if (op == 4)
			y = int(rnd() % vmax) + 1;
		if (op == 1)
			t.add(l, r, LL(x));
		else if (op == 2)
			t.assign(l, r, LL(x));
		else if (op == 3)
			cout << t.find_kth(l, r, x) << '\n';
		else
			cout << t.power(l, r, x, y) << '\n';
	}
	return 0;
}
