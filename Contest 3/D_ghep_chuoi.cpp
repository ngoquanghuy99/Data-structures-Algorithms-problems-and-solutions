#include<iostream>
#include<algorithm>
#include<queue>
#define pb push_back
#define i64 long long
#define FOR(i,n) for(int i=0; i<n; i++)
using namespace std;
const i64 mod = 1e9+7;
i64 minopt(i64 a[], i64 n){
	priority_queue <i64, vector <i64>, greater <i64> > pq(a,a+n);
	i64 sum = 0;
	while(pq.size() > 1){
		i64 fi = pq.top();
		pq.pop();
		i64 se = pq.top();
		pq.pop();
		i64 x = (fi+se)%mod;
		sum = (sum+x)%mod;
		pq.push(x);
	}
	return sum;
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	i64 n;
	cin >> n;
	i64 a[n+1];
	FOR(i,n) cin >> a[i];
	cout << minopt(a,n);
	return 0;
}
