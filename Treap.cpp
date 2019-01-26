#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <cstdio>
using namespace std;
class Treap
{
	struct Node
	{
		int val, d, l, r, cnt, size;
	};
	Node node[1000001];
	int tot, seed;
	inline void zig(int &root);
	inline void zag(int &root);
	inline int rand();
	inline void newNode(int &root, int k);
	inline void update(int root, int new_root);

  public:
	Treap():seed(2333333),tot(0){};
	void Insert(int &root, int k);
	void Delete(int &root, int k);
	int Rank(int root, int k);
	int Find(int root, int k);
	int Pre(int root, int k);
	int Nxt(int root, int k);
};
inline void Treap::zig(int &root)
{
	int new_root = node[root].r;
	node[root].r = node[new_root].l;
	node[new_root].l = root;
	update(root, new_root);
	root = new_root;
}
inline void Treap::zag(int &root)
{
	int new_root = node[root].l;
	node[root].l = node[new_root].r;
	node[new_root].r = root;
	update(root, new_root);
	root = new_root;
}
inline int Treap::rand()
{
	return seed = ((seed * seed + 12345) * seed + 23333333)*seed;
}
inline void Treap::newNode(int &root, int k)
{
	root = ++tot;
	node[root] = {k, rand(), 0, 0, 1, 1};
}
inline void Treap::update(int root, int new_root)
{
	node[new_root].size = node[root].size;
	node[root].size = node[node[root].l].size + node[node[root].r].size + node[root].cnt;
}
void Treap::Insert(int &root, int k)
{
	if (root == 0)
	{
		newNode(root, k);
		return;
	}
	node[root].size += 1;
	if (node[root].val == k)
	{
		node[root].cnt += 1;
		return;
	}
	if (k < node[root].val)
	{
		Insert(node[root].l, k);
		if (node[node[root].l].d > node[root].d)
			zag(root);
	}
	else
	{
		Insert(node[root].r, k);
		if (node[node[root].r].d > node[root].d)
			zig(root);
	}
}
void Treap::Delete(int &root, int k)
{
	if (root == 0)
		return;

	if (node[root].val == k)
	{
		if (node[root].cnt > 1)
		{
			node[root].size -= 1;
			node[root].cnt -= 1;
			return;
		}
		if (node[root].l == 0 || node[root].r == 0)
		{
			root = node[root].l | node[root].r;
			return;
		}
		if (node[node[root].l].d < node[node[root].r].d)
		{
			zig(root);
			Delete(root, k);
		}
		else
		{
			zag(root);
			Delete(root, k);
		}
		return;
	}
	node[root].size -= 1;
	if (k < node[root].val)
		Delete(node[root].l, k);
	else
		Delete(node[root].r, k);
}
int Treap::Rank(int root, int k)
{
	if (root == 0)
		return 0;
	if (node[root].val == k)
		return node[node[root].l].size + 1;
	if (k < node[root].val)
		return Rank(node[root].l, k);
	return node[node[root].l].size + node[root].cnt + Rank(node[root].r, k);
}
int Treap::Find(int root, int k)
{
	if (root == 0)
		return 0;
	if (node[node[root].l].size >= k)
		return Find(node[root].l, k);
	if (node[node[root].l].size + node[root].cnt>=k)
		return node[root].val;
	return Find(node[root].r, k - node[node[root].l].size - node[root].cnt);
}
int Treap::Pre(int root, int k)
{
	if (root == 0)
		return -2147483640;
	if (node[root].val < k)
		return max(node[root].val, Pre(node[root].r, k));
	else
		return Pre(node[root].l, k);
}
int Treap::Nxt(int root, int k)
{
	if (root == 0)
		return 2147483640;
	if (node[root].val > k)
		return min(node[root].val, Nxt(node[root].l, k));
	else
		return Nxt(node[root].r, k);
}
Treap T;
int main()
{
	int n, root = 1;
	cin >> n;
	while (n--)
	{
		int opt, x;
		cin >> opt >> x;
		switch (opt)
		{
		case 1:
			T.Insert(root, x);
			break;
		case 2:
			T.Delete(root, x);
			break;
		case 3:
			cout << T.Rank(root, x) << endl;
			break;
		case 4:
			cout << T.Find(root, x) << endl;
			break;
		case 5:
			cout << T.Pre(root, x) << endl;
			break;
		case 6:
			cout << T.Nxt(root, x) << endl;
			break;
		}
	}
	return 0;
}
