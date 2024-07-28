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

const int mxN = 2e3 + 5;
int a[mxN], b[mxN];

bool check1(int n){
	for(int i = 1; i <= 2 * n; ++i){
		if(a[i] != i) return false; 
	}
	return true;
}

bool check2(int n){
	for(int i = 1; i <= 2 * n; ++i){
		if(b[i] != i) return false; 
	}
	return true;
}

const int inf = 1e18L;
void sieunhan283(){
	int n;
	cin >> n;

	for(int i = 1; i <= 2 * n; ++i){
		cin >> a[i], b[i] = a[i];
	}

	if(check1(n)){
		cout << 0 << endl;
		return;
	}

	int bound = n * 4 + 5;
	int res = inf;
	for(int k = 1; k <= bound; ++k){
		if(k & 1){
			for(int i = 1; i <= 2 * n - 1; i += 2){
				swap(a[i], a[i + 1]);
			}	
		}else{
			for(int i = 1; i <= n; ++i){
				swap(a[i], a[i + n]);
			}
		}
		if(check1(n)){
			res = min(res, k);
			break;
		}
	}

	for(int k = 1; k <= bound; ++k){
		if(!(k & 1)){
			for(int i = 1; i <= 2 * n - 1; i += 2){
				swap(b[i], b[i + 1]);
			}	
		}else{
			for(int i = 1; i <= n; ++i){
				swap(b[i], b[i + n]);
			}
		}

		if(check2(n)){
			res = min(res, k);
			break;
		}
	}

	cout << (res == inf ? -1 : res) << endl;
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

