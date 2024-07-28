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
	int n;
	cin >> n;

	int res = 0;
	for(int i = 1; i <= n; ++i){
		int x; cin >> x;
		while(x % 2 == 0) ++res, x >>= 1;
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

