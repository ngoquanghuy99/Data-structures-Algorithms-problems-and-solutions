#include <iostream>
#define i64 long long
using namespace std;

void solve(i64 n){
	i64 dem = 0;
	if(n & 1) cout << 0 << endl;
	else{
		for(int i = 2; i*i <= n; i++){
			if(n%i == 0){
				if(i%2 == 0) cout << i << endl; //dem++;
				if(n/i != i && n/i % 2==0) cout << n/i << endl;//dem++;
			}
		}
	}
//	return dem+1;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int t = 0; cin >> t;
	while (t--){
		i64 n; cin >> n;
		solve(n);
//		cout << solve(n) << endl;
	}
}
