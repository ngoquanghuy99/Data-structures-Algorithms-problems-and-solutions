#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int t = 0; cin >> t;
	while (t--){
		int n, k; cin >> n >> k;
		int a[n+1]; for(int i = 0; i < n; i++) cin >> a[i];
		int pos = lower_bound(a, a+n, k) - a;
		if(k != a[pos]) cout << "NO" << endl;
		else cout << pos + 1 << endl;
	}
}
