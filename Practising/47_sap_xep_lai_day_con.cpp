/************************************************\

	you know that i can't stop thinkin bout you
	you're the source of everything i do

\************************************************/
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int t = 0; cin >> t;
	while (t--){
		int n; cin >> n;
		int a[n+1], b[n+1];
		for(int i = 0; i < n; i++){
			cin >> a[i];
			b[i] = a[i];
		}
		sort(a, a+n);
		deque <int> Q;
		for(int i = 0; i < n; i++){
			if(b[i] != a[i]) Q.push_back(i);
		}
		if(Q.empty()) cout << "YES" << endl;
		else{
			int x = Q.front(); int y = Q.back();
			cout << y - x + 1<< endl;
		}
	}
	return 0;
}
