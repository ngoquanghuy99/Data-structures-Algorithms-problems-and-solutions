#include <bits/stdc++.h>
#define i64 long long
using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t = 0;  cin >> t;
	while (t--){
		i64 n; cin >> n; i64 a[n+1], b[n+1];
		for(int i = 0; i < n; i++) cin >> a[i];
		sort(a, a+n);
		for(int i = 0; i < n-1; i++) b[i] = a[i+1] - a[i];
		sort(b, b+n-1); cout << b[0] << " ";
		int temp = 0;
		for(int i = 0; i < n-1; i++){
			if(b[i] == b[0])
				temp++;
			else break;
		}
		cout << temp << endl;
	}
	return 0;
}

