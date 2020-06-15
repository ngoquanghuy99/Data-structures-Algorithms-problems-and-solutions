#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int t = 0; cin >> t;
	while (t--){
		int n; cin >> n;
		int a[n+5];
		for(int i = 0; i < n; i++) cin >> a[i];
		sort(a, a+n);
		for(int i = 0; i < n; i++) cout << a[i] << " ";
		cout << endl;
	}
}
