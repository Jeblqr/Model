#include <bits/stdc++.h>
using namespace std;

template <int N, int M, int K>
class ACA
{
	struct Node
	{
		int alpha[N];
		int &operator[](const int &x)
		{
			return alpha[x];
		}
	};
	Node node[M];
	int cnt[M], fail[M], tot;
	const int ROOT;
	queue<int> que;

public:
	ACA() : ROOT(0), tot(0){};
	void insert(const string &s)
	{
		int p = ROOT;
		int size = s.size();
		for (int i = 0; i != size; i++)
		{
			if (node[p][s[i] - K] == 0)
				node[p][s[i] - K] = ++tot;
			p = node[p][s[i] - K];
		}
		cnt[p]++;
	}
	void makeFail()
	{
		while (!que.empty())
			que.pop();
		memset(fail, 0, sizeof(fail));
		for (int i = 0; i != N; i++)
			if (node[ROOT][i] != 0)
				que.push(node[ROOT][i]);
		while (!que.empty())
		{
			int p = que.front();
			que.pop();
			for (int i = 0; i != N; i++)
			{
				if (node[p][i] != 0)
					fail[node[p][i]] = node[fail[p]][i], que.push(node[p][i]);
				else
					node[p][i] = node[fail[p]][i];
			}
		}
	}
	int query(const string &s)
	{
		int ans = 0;
		int p = ROOT;
		int size = s.size();
		for (int i = 0; i != size; i++)
		{
			p = node[p][s[i] - K];
			for (int k = p; k != 0 && cnt[k] != -1; k = fail[k])
				ans += cnt[k], cnt[k] = -1;
		}
		return ans;
	}
};

ACA<26, 1000000, 'a'> t;

int main()
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		string s;
		cin >> s;
		t.insert(s);
	}
	t.makeFail();
	string s;
	cin >> s;
	cout << t.query(s);
	return 0;
}
