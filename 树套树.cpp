#include <bits/stdc++.h>
using namespace std;

class FHQ_Treap
{
#define Maxn 50100
	int len, seed;
	struct Node
	{
		int val, d, size, x, y;
	} node[Maxn * 40];
	int rand();
	int newNode(int val);
	void update(int root);
	void split(int root, int k, int &x, int &y);
	int merge(int x, int y);

public:
	FHQ_Treap() : seed(20050103){};
	void ins(int &ROOT, int val);
	void del(int &ROOT, int val);
	int rank(int &ROOT, int val);
	int find_kth(int root, int k);
	int pre(int &ROOT, int val);
	int nxt(int &ROOT, int val);
#undef Maxn
};

int FHQ_Treap::rand()
{
	return int(seed = seed * 428711ll % 19260817);
}

int FHQ_Treap::newNode(int val)
{
	node[++len] = {val, rand(), 1, 0, 0};
	return len;
}

void FHQ_Treap::update(int root)
{
	node[root].size = node[node[root].x].size + node[node[root].y].size + 1;
}

void FHQ_Treap::split(int root, int k, int &x, int &y)
{
	if (root == 0)
	{
		x = y = 0;
		return;
	}
	if (node[root].val <= k)
	{
		x = root;
		split(node[x].y, k, node[x].y, y);
	}
	else
	{
		y = root;
		split(node[y].x, k, x, node[y].x);
	}
	update(root);
}

int FHQ_Treap::merge(int x, int y)
{
	if (x == 0 || y == 0)
		return x | y;
	if (node[x].d < node[y].d)
	{
		node[x].y = merge(node[x].y, y);
		update(x);
		return x;
	}
	else
	{
		node[y].x = merge(x, node[y].x);
		update(y);
		return y;
	}
}

int FHQ_Treap::find_kth(int root, int k)
{
	if (k == node[node[root].x].size + 1)
		return root;
	if (k <= node[node[root].x].size)
		return find_kth(node[root].x, k);
	else
		return find_kth(node[root].y, k - node[node[root].x].size - 1);
}

void FHQ_Treap::ins(int &ROOT, int val)
{
	int x = 0, y = 0;
	split(ROOT, val, x, y);
	ROOT = merge(merge(x, newNode(val)), y);
}

void FHQ_Treap::del(int &ROOT, int val)
{
	int x = 0, y = 0, z = 0;
	split(ROOT, val, x, z);
	split(x, val - 1, x, y);
	y = merge(node[y].x, node[y].y);
	ROOT = merge(merge(x, y), z);
}

int FHQ_Treap::rank(int &ROOT, int val)
{
	int x = 0, y = 0;
	split(ROOT, val - 1, x, y);
	int ans = node[x].size + 1;
	ROOT = merge(x, y);
	return ans;
}

int FHQ_Treap::pre(int &ROOT, int val)
{
	int x = 0, y = 0;
	split(ROOT, val - 1, x, y);
	if (x == 0)
		return -2147483647;
	int ans = node[find_kth(x, node[x].size)].val;
	ROOT = merge(x, y);
	return ans;
}

int FHQ_Treap::nxt(int &ROOT, int val)
{
	int x = 0, y = 0;
	split(ROOT, val, x, y);
	if (y == 0)
		return 2147483647;
	int ans = node[find_kth(y, 1)].val;
	ROOT = merge(x, y);
	return ans;
}

class SegmentTree : private FHQ_Treap
{
#define Maxn 50100
	int ROOT[8*Maxn];

public:
	int n;
	void update(int root, int l, int r, int k, int _val, int val, bool flag);
	int rank(int root, int l, int r, int L, int R, int val);
	int find_kth(int L, int R, int k);
	int pre(int root, int l, int r, int L, int R, int val);
	int nxt(int root, int l, int r, int L, int R, int val);
#undef Maxn
};

void SegmentTree::update(int root, int l, int r, int k, int _val, int val, bool flag)
{
	if (flag)
		FHQ_Treap::del(ROOT[root], _val);
	FHQ_Treap::ins(ROOT[root], val);
	if (l == r)
		return;
	int mid = (l + r) / 2;
	if (k <= mid)
		update(root * 2, l, mid, k, _val, val, flag);
	else
		update(root * 2 + 1, mid + 1, r, k, _val, val, flag);
}

int SegmentTree::rank(int root, int l, int r, int L, int R, int val)
{
	if (l == L && r == R)
		return FHQ_Treap::rank(ROOT[root], val) - 1;
	int mid = (l + r) / 2;
	if (R <= mid)
		return rank(root * 2, l, mid, L, R, val);
	if (L > mid)
		return rank(root * 2 + 1, mid + 1, r, L, R, val);
	return rank(root * 2, l, mid, L, mid, val) + rank(root * 2 + 1, mid + 1, r, mid + 1, R, val);
}

int SegmentTree::find_kth(int L, int R, int k)
{
	int l = 0, r = 1e8;
	while (l <= r)
	{
		int mid = (l + r) / 2;
		int lll = rank(1, 1, n, L, R, mid);
		int rrr = rank(1, 1, n, L, R, mid + 1);
		if (lll < k && rrr >= k)
			return mid;
		if (lll >= k)
			r = mid - 1;
		else
			l = mid + 1;
	}
	return -1;
}

int SegmentTree::pre(int root, int l, int r, int L, int R, int val)
{
	if (l == L && r == R)
		return FHQ_Treap::pre(ROOT[root], val);
	int mid = (l + r) / 2;
	if (R <= mid)
		return pre(root * 2, l, mid, L, R, val);
	if (L > mid)
		return pre(root * 2 + 1, mid + 1, r, L, R, val);
	return max(pre(root * 2, l, mid, L, mid, val), pre(root * 2 + 1, mid + 1, r, mid + 1, R, val));
}

int SegmentTree::nxt(int root, int l, int r, int L, int R, int val)
{
	if (l == L && r == R)
		return FHQ_Treap::nxt(ROOT[root], val);
	int mid = (l + r) / 2;
	if (R <= mid)
		return nxt(root * 2, l, mid, L, R, val);
	if (L > mid)
		return nxt(root * 2 + 1, mid + 1, r, L, R, val);
	return min(nxt(root * 2, l, mid, L, mid, val), nxt(root * 2 + 1, mid + 1, r, mid + 1, R, val));
}

SegmentTree t;
int a[50100];

int main()
{
	int op, l, r, k, pos;
	int n, m;
	cin >> n >> m;
	t.n = n;
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
		t.update(1, 1, n, i, 0, a[i], false);
	}
	for (int i = 1; i <= m; i++)
	{
		scanf("%d", &op);
		switch (op)
		{
		case 1:
			scanf("%d%d%d", &l, &r, &k);
			printf("%d\n", t.rank(1, 1, n, l, r, k) + 1);
			break;
		case 2:
			scanf("%d%d%d", &l, &r, &k);
			printf("%d\n", t.find_kth(l, r, k));
			break;
		case 3:
			scanf("%d%d", &pos, &k);
			t.update(1, 1, n, pos, a[pos], k, true);
			a[pos] = k;
			break;
		case 4:
			scanf("%d%d%d", &l, &r, &k);
			printf("%d\n", t.pre(1, 1, n, l, r, k));
			break;
		case 5:
			scanf("%d%d%d", &l, &r, &k);
			printf("%d\n", t.nxt(1, 1, n, l, r, k));
			break;
		}
	}
	return 0;
}
