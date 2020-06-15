/************************************************\

	you know that i can't stop thinkin bout you
	you're the source of everything i do

\************************************************/
#include <bits/stdc++.h>
#define i64 long long
using namespace std;


int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	i64 n; cin >> n;
	priority_queue<i64, vector<i64>, greater<i64> > Q1, Q2;
	while (n--){
		i64 a, b; cin >> a >> b;
		Q1.push(a); Q2.push(b);
	}
	i64 x = Q1.top(); i64 y = Q2.top(); 
	cout << x*y;
	return 0;
}


