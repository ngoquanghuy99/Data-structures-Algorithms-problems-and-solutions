#include<iostream>
#include<algorithm>
#include<vector>
#define i64 long long
using namespace std;
const long long mod = 1e9 + 7;
i64 n, k;
i64 maxx(i64 i, i64 k){
	if(i-k > 0) return i-k;
	return 0;
}

i64 padding(i64 n, i64 k){
	vector <i64> f(n+1);
	f[0] = 1;
	for(i64 i=1; i<=n; i++){
		for(i64 j=i-1; j>= maxx(i,k); j--){
			f[i] = (f[i] + f[j]) % mod;
		}
	}
	return f[n];
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t = 0;
	cin >> t;
	while(t--){
		cin >> n >> k;
		cout << padding(n,k) << endl;
	}
	return 0;
}
