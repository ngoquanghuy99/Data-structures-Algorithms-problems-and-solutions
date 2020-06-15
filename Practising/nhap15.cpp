#include <bits/stdc++.h>
#define i64 long long
using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t = 0; cin >> t;
	while (t--){
		i64 n, k; cin >> n >> k;
		i64 a[n+1]; for(int i = 0; i < n; i++) cin >> a[i];
		i64 pos = lower_bound(a, a+n, k) - a;
		if(a[pos] != k) cout << "NO" << endl;
		else cout << pos + 1 << endl;
	}
	return 0;
}


