#include <iostream>
using namespace std;

int main(){
	int t = 0; cin >> t;
	while (t--){
		int n; cin >> n; int a[n+5];
		for(int i = 0; i < n; i++) cin >> a[i];
		int ans = -1e9;
		for(int i = 0; i < n; i++){
			int x = i;
			int y = i;
			while (x >= 0 && a[x] >= a[i]) x--;
			x++;
			while (y < n && a[y] >= a[i]) y++;
			y--;
			int temp = a[i]*(y-x+1);
			ans = max(temp, ans);
		}
		cout << ans << endl;
	}
}
