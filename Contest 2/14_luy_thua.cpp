#include <bits/stdc++.h>

using namespace std;
const int mod = 1e9 + 7;
typedef long long i64;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int t = 0; cin >> t;
	while (t--){
		int n, k; cin >> n >> k;
		i64 ans = 1;
		i64 x = n;
		while (k){
			if(k & 1) ans = (1ll * ans * x) % mod;
			x = (x * x * 1ll) % mod;
			k >>= 1;
		}
		cout << ans << endl;
	}
}
