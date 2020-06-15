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
		while(a[i] == n-k+i) i--;
		a[i]++;
		for(int j = i+1; j <= k; j++){
			a[j] = a[i] + j-i;
		}
	}
}
void solve(){
	unordered_set<int> s;
	for(int i = 1; i <= k; i++) s.insert(b[i]);
	int dem = 0; 
	for(int i = 1; i <= k; i++) if(s.find(a[i]) == s.end()) dem++;
	if(dem != 0) cout << dem << endl;
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
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
	return 0;
}


