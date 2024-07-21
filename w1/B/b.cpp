#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

#ifdef LOCAL
#include<debug.h>
#else
#define debug(...) 28
#define write_output(...) 03
#define eprintf(...) 2003
#define endl '\n'
#endif

// Vi anh chi dam yeu em trong giac mo
// Noi em thuoc ve anh...

#define int long long

const int mxN = 1e5 + 5;
vector<pair<int, int>> adj[mxN];
bool visited[mxN];

bool ok(int x){
	while(x){
		int last = x % 10;
		x /= 10;
		if(last != 4 && last != 7) return false;
	}
	return true;
}

int dfs(int u){
	visited[u] = true;
	int res = 1;
	for(auto p: adj[u]){
		int v = p.second, w = p.first;

		if(!visited[v] && !ok(w))
			res += dfs(v);
	}	
	return res;
}

void sieunhan283(){
	int n;
	cin >> n;

	for(int i = 0; i < n - 1; ++i){
		int u, v, w;
		cin >> u >> v >> w;

		adj[u].push_back({w, v});
		adj[v].push_back({w, u});
	}

	int res = n * (n - 1) * (n - 2);
	for(int i = 1; i <= n; ++i){
		if(!visited[i]){
			int sz = dfs(i);
			res -= sz * (sz - 1) * (n - sz) * 2;
			res -= sz * (sz - 1) * (sz - 2);
		}
	}
	cout << res << endl;
}

signed main(){

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	int test = 1;
	//cin >> test;

	for(int itest = 1; itest <= test; ++itest){
		eprintf("------- Case %d -------\n", itest);
		sieunhan283();
		eprintf("----------------------\n");
	}
	eprintf("Output:\n");
	write_output();	

	return 0;
}

