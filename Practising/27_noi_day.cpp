#include <iostream>
#include <vector>
#include <queue>
#define i64 long long
using namespace std;
const i64 mod = 1e9 + 7;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	i64 n; cin >> n; i64 a[n+1];
	for(int i = 0; i < n; i++) cin >> a[i];
	priority_queue <i64, vector <i64>, greater <int> > Q(a, a+n);
	int sum = 0;
	while (Q.size() > 1){
		i64 f = Q.top(); Q.pop();
		i64 s = Q.top(); Q.pop();
		i64 x = (f + s) % mod;
		Q.push(x);
		sum = (sum + x) % mod;
	}
	cout << sum;
}
