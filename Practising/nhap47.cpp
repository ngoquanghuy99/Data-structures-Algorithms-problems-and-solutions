#include <bits/stdc++.h>
#define i64 long long
using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t = 0; cin >> t;
	while (t--){
		i64 n; cin >> n; i64 a[n+1], b[n+1];
		for(int i = 0; i < n; i++){
			cin >> a[i];
			b[i] = a[i];
		}
		sort(a, a+n);
		deque<i64> Q;
		for(int i = 0; i < n; i++){
			if(a[i] != b[i]) Q.push_back(i);
		}
		if(Q.empty()) cout << "YES" << endl;
		else
		cout << Q.back() - Q.front() + 1 << endl;
	}
	return 0;
}


