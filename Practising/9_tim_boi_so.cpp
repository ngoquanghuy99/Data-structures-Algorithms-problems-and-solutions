#include <bits/stdc++.h>
#define i64 long long
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int t = 0; cin >> t;
	while (t--){
		i64 n; cin >> n;
		queue <i64> Q;
		Q.push(9);
		while (1){
			i64 u = Q.front(); Q.pop();
			if(u % n == 0){
				cout << u << endl;
				break;
			}
			Q.push(u*10);
			Q.push(u*10 + 9);
		}
	}
	return 0;
}
