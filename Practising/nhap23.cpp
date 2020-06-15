#include <bits/stdc++.h>
#define i64 long long
using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	priority_queue<i64, vector<i64>, greater<i64> > Q1, Q2;
	i64 n; cin >> n;
	while (n--){
		i64 x, y; cin >> x >> y;
		Q1.push(x); Q2.push(y);
	}
	cout << Q1.top() * Q2.top() << endl;
	return 0;
}


