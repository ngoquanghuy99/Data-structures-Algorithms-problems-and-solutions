#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int n = 0; cin >> n;
	vector<pii> v;
	for(int i = 0; i < n; i++){
		int x, y; cin >> x >> y;
		v.push_back({x,y});
	}
	sort(v.begin(), v.end());
	int ans = v[0].first + v[0].second;
	for(int i = 1; i < n; i++)
		if(ans <= v[i].first)
			ans = v[i].first + v[i].second;
		else
			ans += v[i].second;
	cout << ans;
	return 0;
}


