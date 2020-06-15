#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n; cin >> n; int x[n+1];
	for(int i = 0; i < n; i++) cin >> x[i];
	int q; cin >> q; int y[q+1];
	for(int i = 0; i < q; i++) cin >> y[i];
	sort(x, x+n);
	for(int i = 0; i < q; i++){
		if(y[i] < x[0]) cout << 0 << endl;
		else cout << upper_bound(x, x+n, y[i]) - x << endl;
	}
}
