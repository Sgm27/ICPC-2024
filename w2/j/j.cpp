#include<bits/stdc++.h>
using namespace std;

#define int long long

#ifdef LOCAL
#include<debug.h>
#else
#define debug(...) 28
#define write_output(...) 03
#define eprintf(...) 2003
#define endl '\n'
#endif

// Vì anh chỉ dám yêu em trong giấc mơ
// Nơi em thuộc về anh...

void sieunhan283(){
	int n, m ;
	cin >> n >> m;

	map<int, int> cnt;
	for(int i = 0; i < n; ++i){
		int x;
		cin >> x;

		cnt[x]++;
	}

	int mx1 = 0, mx2 = 0;
	for(auto p: cnt){
		mx1 = max(mx1, p.second);
	}

	int res = m;
	for(auto p: cnt){
		if(p.second != mx1) mx2 = max(mx2, p.second);
	}
	if(mx2 == 0){
		cout << "NONE" << endl;
		return;
	}
	for(auto p: cnt){
		if(p.second == mx2) res = min(res, p.first);
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

