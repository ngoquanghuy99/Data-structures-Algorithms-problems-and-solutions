// 14 luy thua
#include <bits/stdc++.h>
#define i64 long long
using namespace std;

const i64 mod = 1e9 + 7;
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t = 0; cin >> t; 
	while (t--){
		i64 n, k;
		 cin >> n >> k;
		 i64 ans = 1;
		 while (k){
		 	if(k & 1) ans = (1ll * ans * n) % mod;
		 	n = (1ll * n * n) % mod;
		 	k >>= 1;
		 }
		 cout << ans << endl;
	}
	return 0;
}


