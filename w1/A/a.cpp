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
 
void sieunhan283(){
	string s;
	cin >> s;
 
	int n = s.size();	
	int m;
	cin >> m;
 
	vector<int> a(n + 1);
	for(int i = 0; i < m; ++i){
		int x;
		cin >> x;
		a[x]++;
	}
	for(int i = 1; i <= n; ++i)
		a[i] += a[i - 1];
 
	debug(a);
	for(int i = 1; i <= n / 2; ++i){
		if(a[i] & 1)
			swap(s[i - 1], s[n - i]);
	}
	cout << s << endl;
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
 
