#include <bits/stdc++.h>

using namespace std;
int n;

void demuoc(){
	int dem = 0;
	if(n & 1) cout << 0 << endl;
	else{
		for(int i = 2; i*i <= n; i++){
			if(n % i == 0){
				if(i % 2 == 0) dem++;
				if(n/i != i && n/i % 2 == 0) dem++;
			}
		}
		cout << dem + 1 << endl;
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int t = 0; cin >> t;
	while (t--){
		cin >> n;
		demuoc();
	}
}
