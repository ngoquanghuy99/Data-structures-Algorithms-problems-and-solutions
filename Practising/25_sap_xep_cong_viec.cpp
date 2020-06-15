#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef pair <int, int> pii;

bool sort1(const pii &a, const pii &b){
	return a.second < b.second;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int t = 0; cin >> t;
	while (t--){
		int n; cin >> n;
		vector <pii> v;
		for(int i = 0; i < n; i++){
			int s, t; cin >> s >> t;
			v.push_back({s,t});
		}
		sort(v.begin(), v.end(), sort1);
		int i = 0; int dem = 1;
		for(int j = 1; j < v.size(); j++)
			if(v[i].second <= v[j].first){dem++; i = j;}
		cout << dem << endl;
	}
}
