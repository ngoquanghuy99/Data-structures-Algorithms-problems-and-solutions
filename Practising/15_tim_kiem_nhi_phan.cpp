#include <bits/stdc++.h>

using namespace std;
long long a[100005];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int t = 0; cin >> t;
	while (t--){
		int n, k; cin >> n >> k;
		for(int i = 0; i < n; i++) cin >> a[i];
		int pos = lower_bound(a, a+n, k) - a;
		if(a[pos] == k) cout << pos + 1 << endl;
		else cout << "NO" << endl;
	}
}
