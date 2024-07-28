#include <bits/stdc++.h>
using namespace std;
#define int long long
int n;
signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	int ans = 0;
	vector<int>x;
	for (int m = 1; m <= 10; m++)
		for (int i = 0; i <= 9; i++)
			for (int j = i; j <= 9; j++)
			{
				for (int mask = 0; mask < (1 << m); mask++)
				{
					int res = 0;
					int res2 = 0;
					for (int k = 0; k < m; k++)
						if ((mask >> k) & 1)
							res = res * 10 + i, res2 = res2 * 10 + j;
						else
							res = res * 10 + j, res2 = res2 * 10 + i;
					x.push_back(res);
					x.push_back(res2);
				}

			}
	sort(x.begin(), x.end());
	x.resize(unique(x.begin(), x.end()) - x.begin());
	for (int i = 0; i < x.size(); i++)
	{
		if (x[i] <= n && x[i] >= 1)
			ans++;
		//cout << x[i] << '\n';
	}
	cout << ans;


}

