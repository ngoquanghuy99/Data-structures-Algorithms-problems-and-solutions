#include <iostream>
#include <algorithm>
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int t = 0; cin >> t;
	while (t--){
		int n; cin >> n; int a[n+1]; for(int i = 0; i < n; i++) cin >> a[i];
		sort(a, a+n); for(int i = 0; i < n; i++) cout << a[i] << " ";
		cout << endl;
	}
}
