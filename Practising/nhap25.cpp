#include <bits/stdc++.h>
#define i64 long long
using namespace std;
typedef pair<int,int> pii;
typedef vector<pii> vii;
bool sort2(const pii &a, const pii &b){
	return a.second < b.second;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int t = 0; cin >> t;
	while (t--){
		i64 n; cin >> n;
		vii v;
		while (n--){
			i64 x, y; cin >> x >> y; v.push_back({x, y});
		}
		sort(v.begin(), v.end(), sort2);
		int dem = 1, i = 0;
		for(int j = 1; j < v.size(); j++){
			if(v[i].second <= v[j].first){
				dem++; i = j;
			}
		}
		cout << dem << endl;
	}
	
}
