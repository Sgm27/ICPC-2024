#include <bits/stdc++.h>
using namespace std;
#define int long long
int n;
vector<string>v;
vector<int>a[1027];
int f[1027];
int ts[1027];
int ans = 0;
int xoa[1027];
int active[1027];
int bac[1027];
int d;
int depth[1027];
vector<int> mt;
vector<bool> used;
int check(int i, int j)
{
	i--;
	j--;
	string s1 = v[i];
	string s2 = v[j];
	for (int i = 0; i < s1.size(); i++)
	{
		if (s1[i] == '0' && s2[i] == '1')
			return 0;
	}
	return 1;
}
int Count1(string s)
{
	int ans = 0;
	for (int i = 0; i < s.size(); i++)
		if (s[i] == '1')
			ans++;
	return ans;
}
int cmp(int a, int b)
{
	return ts[a] > ts[b];
}
bool try_kuhn(int v) {
	if (used[v])
		return false;
	used[v] = true;
	for (int to : a[v]) {
		if (mt[to] == -1 || try_kuhn(mt[to])) {
			mt[to] = v;
			return true;
		}
	}
	return false;
}

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> d >> n;
	for (int i = 1; i <= n; i++)
	{
		string s;
		cin >> s;
		v.push_back(s);
	}
	//cout<<check(1,2);
	for (int i = 1; i <= n; i++)
		ts[i] = Count1(v[i - 1]), ans += ts[i] + 1;
	for (int i = 1; i <= n; i++)
		for (int j = i; j <= n; j++)
		{
			if (j == i)
				continue;
			if (check(j, i))
				a[i].push_back(j);
			if (check(i, j))
				a[j].push_back(i);
		}
	vector<int>v;
	for (int i = 1; i <= n; i++)
		v.push_back(i);
	mt.assign(n + 1, -1);
	sort(v.begin(), v.end(), cmp);
	for (int i = 0; i <= n - 1; i++)
	{
		used.assign(n + 1, false);
		try_kuhn(v[i]);
	}
	for (int i = 1; i <= n; ++i)
		if (mt[i] != -1)
		{
			ans -= (ts[mt[i]] + 1);
		}
	cout << ans - 1;
}

