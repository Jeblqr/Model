#include <bits/stdc++.h>
using namespace std;

class FHQ_Treap
{
#define Maxn 100001
    int ROOT, len, seed;
    struct Node
    {
        int val, d, size, x, y;
    } node[Maxn];
    int rand();
    int newNode(int val);
    void update(int root);
    void split(int root, int k, int &x, int &y);
    int merge(int x, int y);
    int find_kth(int root, int k);

public:
    FHQ_Treap() : seed(20050103){};
    void ins(int val);
    void del(int val);
    int rank(int val);
    int find_kth(int k);
    int pre(int val);
    int nxt(int val);
};

int FHQ_Treap::rand()
{
    return int(seed = seed * 428711ll % 2147483647);
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

void FHQ_Treap::ins(int val)
{
    int x = 0, y = 0;
    split(ROOT, val, x, y);
    ROOT = merge(merge(x, newNode(val)), y);
}

void FHQ_Treap::del(int val)
{
    int x = 0, y = 0, z = 0;
    split(ROOT, val, x, z);
    split(x, val - 1, x, y);
    y = merge(node[y].x, node[y].y);
    ROOT = merge(merge(x, y), z);
}

int FHQ_Treap::rank(int val)
{
    int x = 0, y = 0;
    split(ROOT, val - 1, x, y);
    int ans = node[x].size + 1;
    ROOT = merge(x, y);
    return ans;
}

int FHQ_Treap::find_kth(int k)
{
    return node[find_kth(ROOT, k)].val;
}

int FHQ_Treap::pre(int val)
{
    int x = 0, y = 0;
    split(ROOT, val - 1, x, y);
    int ans = node[find_kth(x, node[x].size)].val;
    ROOT = merge(x, y);
    return ans;
}

int FHQ_Treap::nxt(int val)
{
    int x = 0, y = 0;
    split(ROOT, val, x, y);
    int ans = node[find_kth(y, 1)].val;
    ROOT = merge(x, y);
    return ans;
}

inline int read()
{
    int x = 0, f = 1;
    char c = getchar();
    while (c > '9' || c < '0')
    {
        if (c == '-')
            f = -1;
        c = getchar();
    }
    while (c >= '0' && c <= '9')
    {
        x = x * 10 + c - '0';
        c = getchar();
    }
    return x * f;
}

FHQ_Treap t;

int main()
{
    int n;
    n = read();
    while (n--)
    {
        int opt, x;
        opt = read();
        x = read();
        switch (opt)
        {
        case 1:
            t.ins(x);
            break;
        case 2:
            t.del(x);
            break;
        case 3:
            cout << t.rank(x) << endl;
            break;
        case 4:
            cout << t.find_kth(x) << endl;
            break;
        case 5:
            cout << t.pre(x) << endl;
            break;
        case 6:
            cout << t.nxt(x) << endl;
            break;
        }
    }
    return 0;
}
