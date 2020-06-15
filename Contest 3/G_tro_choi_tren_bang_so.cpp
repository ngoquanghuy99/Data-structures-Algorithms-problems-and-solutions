#include<iostream>
#include<algorithm>
#include<vector>
#define i64 long long
using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	i64 t = 0;
	cin >> t;
	while(t--){
		i64 n, a[9][9];
		cin >> n;
		for(i64 i=1; i<=n; i++)
			for(i64 j=1; j<=n; j++)
				cin >> a[i][j];
		vector <i64> p(n);
		for(i64 i=0; i<n; i++)
			p[i] = i+1;
		i64 ans = -1e9;
		do {
			i64 sum = 0;
			for(i64 i = 1; i <= n; i ++)
				sum += -a[i][p[i-1]];
			ans = ans > sum ? ans : sum;
		} while(next_permutation(p.begin(),p.end()));
		cout << -ans << endl;
	}
	return 0;
}
