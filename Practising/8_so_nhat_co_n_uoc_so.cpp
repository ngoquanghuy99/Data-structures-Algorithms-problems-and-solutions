#include <bits/stdc++.h>
using namespace std;

int n; 
int v[] = {0, 2, 3, 5, 7, 11, 12, 17, 19, 23, 29};
long long res;
const long long oo = 1e18 + 1;

void cal(int i, long long ans, long long cnt){
	if(cnt > n) return;
	if(cnt == n) res = min(res, ans);
	for(int j = 1; ; j++){
		if(ans * v[i] > res) break;
		ans *= v[i];
		if(ans < 0) break;
		cal(i+1, ans, cnt * (j+1));
	}
}

void solve(){
	cin >> n;
	res = oo;
	cal(1, 1, 1);
	cout << res << endl;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int t = 0; cin >> t;
	while(t--){
		solve();
	}
}
