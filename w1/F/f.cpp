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
const int base = 67;
const int base2 = 97;
const int mxN = 10;

int f[mxN];
int f2[mxN];
const int mod = 1e9 + 7;
const int mod2 = 998244353;
struct hash_pair{
  template <class T1, class T2>
    size_t operator()(const pair<T1, T2>& p) const {
        auto hash1 = hash<T1>{}(p.first);
        auto hash2 = hash<T2>{}(p.second);
        return hash1 ^ hash2;
    }
};

// Gap doi noi sau
pair<int,int> vec_hash(const vector<int>& a){
	pair<int,int> res = {0, 0};
	for(int i = 0; i < a.size(); ++i){
		res.first += f[i + 1] * a[i];	
		res.first %= mod;

		res.second += f2[i + 1] * a[i];	
		res.second %= mod2;
	}
	return res;
}

void sieunhan283(){
	f[0] = 1;
	f2[0] = 1;
	for(int i = 1; i < mxN; ++i){
		f[i] = f[i - 1] * base;
		f[i] %= mod;

		f2[i] = f2[i - 1] * base2;
		f2[i] %= mod2;
	}
	
	int n;
	cin >> n;

	unordered_map<pair<int, int>, int, hash_pair> cnt;
	int res = n * (n - 1) / 2;

	// Inclusion–exclusion principle	
	for(int j = 0; j < n; ++j){
		vector<int> a(5);
		for(int i = 0; i < 5; ++i)
			cin >> a[i];

		sort(a.begin(), a.end());

		for(int mask = 1; mask < (1 << 5); ++mask){
			int x = 0;
			vector<int> v;
			for(int i = 0; i < 5; ++i){
				if((1 << i) & mask){
					++x;
					v.push_back(a[i]);
				}
			}
			pair<int,int> val = vec_hash(v);
			if(x & 1)
				res -= cnt[val];
			else
				res += cnt[val];

		}

		for(int mask = 1; mask < (1 << 5); ++mask){
			vector<int> v;
			for(int i = 0; i < 5; ++i){
				if((1 << i) & mask){
					v.push_back(a[i]);
				}
			}
			pair<int,int> val = vec_hash(v);
			cnt[val]++;
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

