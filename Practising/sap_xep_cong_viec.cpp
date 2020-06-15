// sap xep cong viec
// Ngo Quang Huy
// sap xep cong viec tang dan theo thoi gian ket thuc, so sanh ket thuc cua nguoi thu i voi bat dau cua nguoi thu i+1, <= thi thoa man
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef pair <int, int> pii;

bool cmp(const pii &a, const pii &b){
	return a.second < b.second;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int t = 0; cin >> t;
	while (t--){
		vector <pii> v;
		int n; cin >> n;
		for(int i = 0; i < n; i++){
			int s, t; cin >> s >> t;
			v.push_back({s,t});
		}
		sort(v.begin(), v.end(), cmp);
		int i = 0; int dem = 1;
		for(int j = 1; j < v.size(); j++){
			if(v[i].second <= v[j].first){
				dem++;
				i = j;
			}
		}
		cout << dem << endl;
	}
}
