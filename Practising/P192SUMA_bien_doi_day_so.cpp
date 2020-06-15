#include <bits/stdc++.h>
#define i64 long long
using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	vector<i64> a;
	i64 n, d, ans, x; cin >> n >> d;
	for(int i = 0; i < n; i++){
		cin >> x; a.push_back(x);
	}
	ans = 0;
	for(int i = 0; i < n-1; i++){
		while(a[i] >= a[i+1]){
			ans++;
			a[i+1] = a[i+1] + d;
		}
	}
	cout << ans << endl;
	return 0;
}


