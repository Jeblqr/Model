#include <iostream>
#include<algorithm>

using namespace std;

class FHQ_Treap
{
#define Maxn 10000001
	//the ROOT of the tree, the number of members of the tree, the seed of rand()
	int ROOT, len, seed;
	struct Node //the node of the tree
	{
		//the value of this node, the rand() of the node,
		//the size of this sub tree, the left and right sub tree of this tree
		int val, d, size, x, y;
		//the tag of flip
		//just something like lazy_tag in segment tree
		bool tag;
	} node[Maxn];
	int rand();
	int newNode(int val);                        //create a new node with the value is val, and return the number of the new node
	void update(int root);                       //update the node root
	void pushDown(int root);                     //update the tag of flip of the node root
	void split(int root, int k, int& x, int& y); //split the tree root with k
	int merge(int x, int y);                     //merge tree x and tree y and return the new tree
	int find_kth(int root, int k);               //find a node whose rank is k in the tree root
	void output(int root);                       //output the tree root
public:
	FHQ_Treap() : seed(20050103) {}; //initialize seed
	void ins_chain(int x);
	void ins(int val);       //insert a new node and initialize it as val
	void del(int val);       //delete a node whose value is val
	int rank(int val);       //find the rank of the node whose value is val
	int find_kth(int k);     //find a node whose rank is k
	int pre(int val);        //find the precursor of the node whose value is val
	int nxt(int val);        //find the next one of the node whose value is val
	void flip(int l, int r); //flip the section of L and R
	void output();           //output the whole tree
};

int FHQ_Treap::rand()
{
	return int(seed = seed * 428711ll % 2147483647);
}

int FHQ_Treap::newNode(int val)
{
	node[++len] = { val, rand(), 1, 0, 0 };
	return len;
}

void FHQ_Treap::update(int root)
{
	node[root].size = node[node[root].x].size + node[node[root].y].size + 1;
}

void FHQ_Treap::pushDown(int root)
{
	if (!node[root].tag)
		return;
	swap(node[root].x, node[root].y);
	if (node[root].x)
		node[node[root].x].tag ^= 1;
	if (node[root].y)
		node[node[root].y].tag ^= 1;
	node[root].tag = 0;
}

void FHQ_Treap::split(int root, int k, int& x, int& y)
{
	if (root == 0)
	{
		x = y = 0;
		return;
	}
	pushDown(root);
	if (node[node[root].x].size < k)
	{
		x = root;
		split(node[x].y, k - node[node[x].x].size - 1 , node[x].y, y);
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
		pushDown(x);
		node[x].y = merge(node[x].y, y);
		update(x);
		return x;
	}
	else
	{
		pushDown(y);
		node[y].x = merge(x, node[y].x);
		update(y);
		return y;
	}
}

void FHQ_Treap::output(int root)
{
	if (!root)
		return;
	pushDown(root);
	output(node[root].x);
	cout << node[root].val << ' ';
	output(node[root].y);
}

void FHQ_Treap::ins_chain(int x)
{
	ROOT = merge(ROOT, newNode(x));
}

void FHQ_Treap::flip(int l, int r)
{
	int x = 0, y = 0, z = 0;
	split(ROOT, l - 1, x, y);
	split(y, r - l + 1, y, z);
	node[y].tag ^= 1;
	ROOT = merge(x, merge(y, z));
}

void FHQ_Treap::output()
{
	output(ROOT);
	cout << endl;
}

FHQ_Treap t;

int main()
{
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		t.ins_chain(i);
	for (int i = 1; i <= m; i++)
	{
		int l, r;
		cin >> l >> r;
		t.flip(l, r);
		//t.output();
	}
	t.output();
	return 0;
}
