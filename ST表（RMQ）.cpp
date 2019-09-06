#include <bits/stdc++.h>
#define Maxn 100010
using namespace std;

const int K = log2(Maxn) + 5;

int n, m, f[Maxn][K];

void init() {
    for (int j = 1; (1 << j) <= n; j++)
        for (int i = 1; i + (1 << j) - 1 <= n; i++) f[i][j] = max(f[i][j - 1], f[i + (1 << (j - 1))][j - 1]);
}

int query(int l, int r) {
    int k = log2(r - l + 1);
    return max(f[l][k], f[r - (1 << k) + 1][k]);
}

signed main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) scanf("%d", &f[i][0]);
    init();
    for (int i = 1; i <= m; i++) {
        int l, r;
        scanf("%d%d", &l, &r);
        printf("%d\n", query(l, r));
    }
    return 0;
}
