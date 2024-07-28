#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<int>a[200005];
int cha[200005];
int s[200005];
int active[200005];
vector<int>v;
int ma;
vector<string>ans;
int Find(int u)
{
	if (cha[u] == 0)
		return u;
	return cha[u] = Find(cha[u]);
}
void join(int u, int v)
{
	int x = Find(u);
	int y = Find(v);
	if (x == y)
		return;
	cha[x] = y;
	s[y] += s[x];
	ma = max(ma, s[y]);
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= m; i++)
	{
		int u, v;
		cin >> u >> v;
		a[u].push_back(v);
		a[v].push_back(u);

	}
	for (int i = 1; i <= n; i++)
	{
		int x;
		cin >> x;
		v.push_back(x);
	}
	reverse(v.begin(), v.end());
	for (int i = 1; i <= n; i++)
		s[i] = 1;
	ma=1;
	for (int i = 0; i < v.size(); i++)
	{
		int u = v[i];
		active[u] = 1;
		for (int j = 0; j < a[u].size(); j++)
			if (active[a[u][j]])
				join(u, a[u][j]);
		if (ma == i + 1)
			ans.push_back("YES");
		else
			ans.push_back("NO");
	}
	for (int i = ans.size() - 1; i >= 0; i--)
		cout << ans[i] << '\n';

}

