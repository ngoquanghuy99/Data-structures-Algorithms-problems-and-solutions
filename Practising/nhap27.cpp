// 27 noi day
#include <bits/stdc++.h>
#define i64 long long
using namespace std;
const i64 mod = 1e9 + 7;
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	i64 n; cin >> n; i64 a[n+1];
	for(int i = 0; i < n; i++) cin >> a[i];
	priority_queue<i64, vector<i64>, greater<i64> > Q(a, a+n);
	i64 ans = 0;
	while (Q.size() > 1){
		i64 x = Q.top(); Q.pop();
		i64 y = Q.top(); Q.pop();
		i64 sum = (x+y)%mod;
		Q.push(sum);
		ans = (ans + sum) % mod;
	}
	cout << ans;
	return 0;
}


