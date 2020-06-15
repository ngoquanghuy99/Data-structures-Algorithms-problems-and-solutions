#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
#include <cmath>
#include <cstring>
#include <sstream>
#define i64 long long
#define pb push_back

const i64 mod = 1000000007;

using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	priority_queue < i64, vector <i64>, greater <i64> > q;
	i64 n = 0;
	cin >> n;
	while(n--){
		i64 x; cin >> x;
		q.push(x);
	}
	while(!q.empty()){
		cout << q.top() << " ";
		q.pop();
	}
	return 0;
}

