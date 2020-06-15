#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int t = 0;
	cin >> t;
	while (t--){
		int n; cin >> n;
		queue <long long> Q;
		Q.push(1);
		while (n--){
			long long u = Q.front(); Q.pop();
			cout << u << " ";
			Q.push(u * 10);
			Q.push(u * 10 + 1);
		}
		cout << endl;
	}
	return 0;
}
