#include <bits/stdc++.h>
#define FOR(i,a,b) for(int i = a; i <= b; i++)
using namespace std;

int n, k, a[1000001];

int main(){
	ios_base::sync_with_stdio(false);
	int t = 0;
	cin >> t;
	while (t--){
		cin >> n >> k;
		FOR(i,0,n-1) cin >> a[i];
		int pos = lower_bound(a, a+n, k) - a;
		if(k != a[pos]) cout << "NO" << endl;
		else cout << pos + 1 << endl;
	}
	return 0;
}
