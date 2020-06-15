#include <iostream>
#define i64 long long
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	i64 t = 0; cin >> t;
	while (t--){
		i64 n; cin >> n; i64 a[n+1];
		for(int i = 0; i < n; i++) cin >> a[i];
		i64 ans = -1e9;
		for(int i = 0; i < n; i++){
			int x = i, y = i;
			while (x >= 0 && a[x] >= a[i]) x--;
			x++;
			while (y < n && a[y] >= a[i]) y++;
			y--;
			i64 temp = a[i]*(y-x+1);
			ans = max(ans, temp);
		}
		cout << ans << endl;
	}
	return 0;
}
