#include<iostream>
#include<cstring>
using namespace std;

int b[1001], f[1001][10];

int dfs(int cnt, int low, bool flag)
{
	if (cnt == 0)
		return 1;
	if (!flag && f[cnt][low] != -1)
		return f[cnt][low];
	int tmp = 0;
	int MAX = flag ? b[cnt] : 9;
	for (int i = low; i <= MAX; i++)
		tmp += dfs(cnt - 1, i, flag && i == MAX);
	if (!flag)
		f[cnt][low] = tmp;
	return tmp;
}

int find(int x)
{
	memset(b, 0, sizeof b);
	memset(f, -1, sizeof f);
	while (x)
		b[++b[0]] = x % 10, x /= 10;
	return dfs(b[0], 0, true);
}

int main()
{
	int a, b;
	while (cin >> a >> b)
		cout << find(b) - find(a - 1) << endl;
	return 0;
}
