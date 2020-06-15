#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
	int n; cin >> n;
	vector<pair<int,int> > v;
	for(int i = 0; i < n; i++){
		int x, y; cin >> x >> y;
		v.push_back({x,y});
	}
	sort(v.begin(), v.end());
	int ans = v[0].first + v[0].second;
	for(int i = 1; i < n; i++){
		if(ans <= v[i].first) ans = v[i].first + v[i].second;
		else ans += v[i].second;
	}
	cout << ans << endl;
}
