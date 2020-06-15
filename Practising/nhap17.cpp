#include <bits/stdc++.h>
#define i64 long long
using namespace std;
i64 F[100];
void init(){
	F[0] = 0; F[1] = 1;
	for(int i = 2; i <= 92; i++) F[i] = F[i-1] + F[i-2];
}
char solve(i64 n, i64 k){
	if(n==1) return 'A';
	if(n==2) return 'B';
	if(k <= F[n-2]) return solve(n-2, k);
	return solve(n-1, k-F[n-2]);
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t = 0; cin >> t;
	init();
	while (t--){
		i64 n, k; cin >> n >> k;
		cout << solve(n, k) << endl;
	}
	return 0;
}


