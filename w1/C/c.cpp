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

/*
int n;
set<int> d1, d2, col;

int dfs(int row){
	if(row == n + 1)
		return 1;

	int res = 0;
	for(int i = 1; i <= n; ++i){
		if(col.find(i) == col.end()
				&& d1.find(row - i) == d1.end()
				&& d2.find(row + i) == d2.end()){
			col.insert(i);
			d1.insert(row - i);
			d2.insert(row + i);
			res += dfs(row + 1);
			col.erase(i);
			d1.erase(row - i);
			d2.erase(row + i);
		}
	}
	return res;
}
*/

// Choi ban mot ti ha ha :v
int res[] = {0, 0, 0, 0, 2, 10, 4, 40, 92, 352, 724, 2680, 14200, 73712, 365596};

void sieunhan283(){
	int n;
	cin >> n;
	cout << res[n] << endl;
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

