#pragma GCC optimize("Ofast")
#include <iostream>
#include <queue>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int t = 0; cin >> t;
	while (t--){
		int n; cin >> n;
		queue <long long> Q;
		Q.push(9);
		while (1){
			long long u = Q.front(); Q.pop();
			if(u % n == 0){
				cout << u << endl;
				break;
			}
			Q.push(u * 10);
			Q.push(u * 10 + 9);
		}
	}
	return 0;
}
