#include <bits/stdc++.h>
using namespace std;
int n, k, a[110], b[110];

bool isFinal(){
	for(int i = 1; i <= k; i++) if(a[i] != n-k+i) return false;
	return true;
}

void nextgen(){
	if(isFinal()) cout << k << endl;
	else{
		int i = k;
		while (a[i] == n-k+i) i--;
		a[i]++;
		for(int j = i+1; j <= k; j++){
			a[j] = a[i] + j -i;
		}
	}
}

void solve(){
	int x = 0, dem = 0;
	for(int i = 1; i <= k; i++){
		x = 0;
		for(int j = 1; j <= k; j++){
			if(a[i] == b[j]){
				x = 1;
				break;
			}
		}
		if(!x) dem++;
	}
	if(dem != 0) cout << dem << endl;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int t = 0; cin >> t;
	while (t--){
		cin >> n >> k;
		for(int i = 1; i <= k; i++){
			cin >> a[i];
			b[i] = a[i];
		}
		nextgen();
		solve();
	}
}
