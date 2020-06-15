#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int t = 0; cin >> t;
	while (t--){
		int n; cin >> n; int a[n+1];
		for(int i = 0; i < n; i++) cin >> a[i];
		sort(a, a+n);
		int b[n+1];
		for(int i = 0; i < n-1; i++){
			b[i] = a[i+1] - a[i];
		} 
		sort(b, b+n-1);
		int dem = 0;
		for(int i = 0; i < n-1; i++){
			if(b[i] == b[0]) dem++;
			else break;
		}
		cout << b[0] << " " << dem << endl;
	}
}
