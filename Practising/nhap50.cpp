#include <bits/stdc++.h>
#define i64 long long
using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int n; cin >> n; int a[n+1];
	for(int i = 0; i < n; i++) cin >> a[i];
	int q; cin >> q; int y[q+1];
	for(int i = 0; i < q; i++) cin >> y[i];
	sort(a, a+n);
	for(int i = 0; i < q; i++){
		if(y[i] < a[0]) cout << 0 << endl;
		else cout << upper_bound(a, a+n, y[i]) - a << endl;
	}
	return 0;
}


