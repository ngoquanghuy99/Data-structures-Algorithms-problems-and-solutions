#include <iostream>
#include <queue>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int t = 0; cin >> t;
	while (t--){
		int n = 0; cin >> n;
		queue <int> Q;
		while (n--){
			int x; cin >> x;
			if(x == 1) cout << Q.size() << endl;
			if(x == 2) cout << (Q.empty() ? "YES" : "NO") << endl;
			if(x == 3){
				int x2; cin >> x2; Q.push(x2);
			}
			if(x == 4) if(!Q.empty()) Q.pop();
			if(x == 5) cout << (!Q.empty() ? Q.front() : -1) << endl;
			if(x == 6) cout << (!Q.empty() ? Q.back() : -1) << endl;
		}
	}
	return 0;
}
