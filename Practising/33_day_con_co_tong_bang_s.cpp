#include <bits/stdc++.h>
using namespace std;
int a[210], f[40010];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n, s; cin >> n >> s;
	f[0] = 1;
	for(int i = 1; i <= n; i++) cin >> a[i];
	for(int i = 1; i <= n; i++){
		for(int j = s; j >= a[i]; j--){
			if(f[j-a[i]] == 1) f[j] = 1;
		}
	}
	if(f[s]) cout << "YES";
	else cout << "NO";
	
}
