#include <bits/stdc++.h>
#define i64 long long
using namespace std;
i64 cur[] = {1, 2, 5, 10, 20, 50, 100, 200, 500, 1000};
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int t = 0; cin >> t;
	while (t--){
		i64 n; cin >> n;
		i64 num = 0;
		for(int i = 9; i >= 0; i--){
			num += (n/cur[i]);
			n %= cur[i];
		}
		cout << num << endl;
	}
}
