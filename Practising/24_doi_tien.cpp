#include <bits/stdc++.h>

using namespace std;

int cur[] = {1, 2, 5, 10, 20, 50, 100, 200, 500, 1000};

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int t = 0; cin >> t;
	while (t--){
		int n; cin >> n;
		int amount = 0;
		for(int i = 9; i >= 0; i--){
			amount += (n/cur[i]);
			n %= cur[i];
		}
		cout << amount << endl;
	}
	return 0;
}
