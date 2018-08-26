#include <iostream>
#include <cstring>
#include <cstdio>
#include <string>
#include <cstdlib>
#include <algorithm>
#include <set>
#include <cmath>
#include <iomanip>
#include <vector>
#include <map>
#include <queue>
#define Max 500000
using namespace std;
long long class ST
{
	struct Node
	{
		long long val, mark;
	} tree[Max];
	long long ls(long long k);
	long long rs(long long k);
	void PushUp(long long f, long long l, long long r, long long k);
	void PushUpSum(long long f);
	void PushUpMin(long long f);
	void PushUpMax(long long f);
	void PushDown(long long f, long long l, long long r);

  public:
	void init();
	void build(long long f, long long a[], long long l, long long r);
	long long query(long long f, long long i, long long j, long long l, long long r);
	void updata(long long f, long long i, long long j, long long l, long long r, long long val);
};

long long ST::ls(long long k) { return k << 1; }

long long ST::rs(long long k) { return k << 1 | 1; }

void ST::PushUpSum(long long f) { tree[f].val = tree[ls(f)].val + tree[rs(f)].val; }

void ST::PushUpMin(long long f) { tree[f].val = min(tree[ls(f)].val, tree[rs(f)].val); }

void ST::PushUpMax(long long f) { tree[f].val = max(tree[ls(f)].val, tree[rs(f)].val); }

void ST::PushUp(long long f, long long l, long long r, long long k)
{
	tree[f].val += (r - l + 1) * k;
	tree[f].mark += k;
}

void ST::PushDown(long long f, long long l, long long r)
{
	long long mid = (l + r) / 2;
	PushUp(ls(f), l, mid, tree[f].mark);
	PushUp(rs(f), mid + 1, r, tree[f].mark);
	tree[f].mark = 0;
}

void ST::init()
{
	memset(tree, 0, sizeof tree);
}

void ST::build(long long f, long long a[], long long l, long long r)
{
	tree[f].mark = 0;
	if (l == r)
	{
		tree[f].val = a[l];
		return;
	}
	long long mid = (l + r) / 2;
	build(ls(f), a, l, mid);
	build(rs(f), a, mid + 1, r);
	PushUpSum(f);
}

long long ST::query(long long f, long long i, long long j, long long l, long long r)
{
	if (i >= l && j <= r)
		return tree[f].val;
	PushDown(f, i, j);
	long long mid = (i + j) / 2;
	long long res = 0;
	if (l <= mid)
		res += query(ls(f), i, mid, l, r);
	if (r > mid)
		res += query(rs(f), mid + 1, j, l, r);
	return res;
}

void ST::updata(long long f, long long i, long long j, long long l, long long r, long long val)
{
	if (i >= l && j <= r)
	{
		tree[f].val += val * (j - i + 1);
		tree[f].mark += val;
		return;
	}
	PushDown(f, i, j);
	long long mid = (i + j) / 2;
	if (l <= mid)
		updata(ls(f), i, mid, l, r, val);
	if (r > mid)
		updata(rs(f), mid + 1, j, l, r, val);
	PushUpSum(f);
}

ST st;
long long a[Max], n, m;

int main()
{
	st.init();
	cin >> n >> m;
	for (long long i = 1; i <= n; i++)
		cin >> a[i];
	st.build(1, a, 1, n);
	long long k, x, y, g;
	for (long long i = 1; i <= m; i++)
	{
		cin >> g;
		switch (g)
		{
		case 1:
			cin >> x >> y >> k;
			st.updata(1, 1, n, x, y, k);
			break;
		case 2:
			cin >> x >> y;
			cout << st.query(1, 1, n, x, y) << endl;
			break;
		}
	}
	return 0;
}
