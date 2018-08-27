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
#define Max 1000000
using namespace std;

//---------------------------------------
class Trie
{
	int tree[Max][27], len, mark[Max];

  public:
	void init();
	void add(string s);
	int query(string s);
	void erase(string s);
};

void Trie::init()
{
	memset(tree, 0, sizeof tree);
	memset(mark, 0, sizeof mark);
	len = 0;
}

void Trie::add(string s)
{
	int p = 0;
	for (int i = 0; i != s.size(); i++)
	{
		if (!tree[p][s[i] - 'a'])
			tree[p][s[i] - 'a'] = ++len;
		p = tree[p][s[i] - 'a'];
	}
	mark[p]++;
}

int Trie::query(string s)
{
	int p = 0;
	for (int i = 0; i != s.size(); i++)
	{
		if (!tree[p][s[i] - 'a'])
			return 0;
		p = tree[p][s[i] - 'a'];
	}
	return mark[p];
}

void Trie::erase(string s)
{
	int p = 0;
	for (int i = 0; i != s.size(); i++)
	{
		if (!tree[p][s[i] - 'a'])
			tree[p][s[i] - 'a'] = ++len;
		p = tree[p][s[i] - 'a'];
	}
	if (mark[p])
		mark[p]--;
}
//---------------------------------------

Trie trie;

int main()
{
	trie.init();
	int n;
	cin >> n;
	string s;
	for (int i = 1; i <= n; i++)
		cin >> s, trie.add(s);
	int m;
	cin >> m;
	for (int i = 1; i <= m; i++)
	{
		cin >> s;
		int k = trie.query(s);
		switch (k)
		{
		case 0:
			cout << "WRONG\n";
			break;
		case 1:
			cout << "OK\n";
			trie.add(s);
			break;
		default:
			cout << "REPEAT\n";
			break;
		}
	}
	return 0;
}
