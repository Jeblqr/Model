#include <bits/stdc++.h>
const int Maxn = 210001;
using namespace std;

class HJTTree {
    struct Node {
        int l, r, sum;
    } node[Maxn << 5];
    int cnt;

   public:
    int root[Maxn];
    void build(int& p, int l, int r) {
        p = ++cnt;
        if (l == r)
            return;
        int mid = (l + r) / 2;
        build(node[p].l, l, mid);
        build(node[p].r, mid + 1, r);
    }
    void change(int& p, int q, int l, int r, int x) {
        p = ++cnt;
        node[p] = node[q];
        node[p].sum += 1;
        if (l == r)
            return;
        int mid = (l + r) / 2;
        if (x <= mid)
            change(node[p].l, node[q].l, l, mid, x);
        else
            change(node[p].r, node[q].r, mid + 1, r, x);
    }
    int query(int p, int q, int l, int r, int k) {
        if (l == r)
            return l;
        int mid = (l + r) / 2;
        int tmp = node[node[q].l].sum - node[node[p].l].sum;
        if (tmp >= k)
            return query(node[p].l, node[q].l, l, mid, k);
        else
            return query(node[p].r, node[q].r, mid + 1, r, k - tmp);
    }
} T;

int a[Maxn], b[Maxn];

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i], b[i] = a[i];
    sort(b + 1, b + n + 1);
    int size = unique(b + 1, b + n + 1) - b - 1;
    T.build(T.root[0], 1, size);
    for (int i = 1; i <= n; i++)
        T.change(T.root[i], T.root[i - 1], 1, size,
                 (lower_bound(b + 1, b + size + 1, a[i]) - b));
    while (m --> 0) {
        int x, y, k;
        cin >> x >> y >> k;
        cout << b[T.query(T.root[x - 1], T.root[y], 1, size, k)] << endl;
    }
    return 0;
}
