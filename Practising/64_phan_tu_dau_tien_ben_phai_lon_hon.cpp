#include <iostream>
#include <stack>
#include <cstring>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int t = 0; cin >> t;
	while (t--){
		int n; cin >> n;
		int a[n+1], ans[n+1];
		memset(ans, -1, sizeof ans);
		for(int i = 0; i < n; i++) cin >> a[i];
		
		stack <int> s;
		for(int i = 0; i < n; i++){
			while (!s.empty() && a[i] > a[s.top()]){
				int x = s.top();
				s.pop();
				ans[x] = a[i];
			} 
			s.push(i);
		}
		for(int i = 0; i < n; i++) cout << ans[i] << " ";
		cout << endl;
	}
	return 0;
}
