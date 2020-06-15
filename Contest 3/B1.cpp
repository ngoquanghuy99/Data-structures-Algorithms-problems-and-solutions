#pragma GCC optimize("Ofast")
 
#include <bits/stdc++.h>
using namespace std;
 
#define y0 holdtheflower
#define y1 enjoythecolorandscent
#define yn walkthroughthesoulgarden
#define j1 feelthewarmbreathofkindnessandsalvation
 
#define endl '\n'
mt19937 rng32(chrono::steady_clock::now().time_since_epoch().count());
mt19937_64 rng64(chrono::steady_clock::now().time_since_epoch().count());
 
int n;
vector<pair<int, int>> a;
 
void Input() {
	cin >> n; a.resize(n);
	for (auto &P: a) cin >> P.second >> P.first;
}
 
void Solve() {
	sort(a.begin(), a.end());
	int ans = 1, last = a[0].first;
	for (int i=1; i<n; i++) {
		if (a[i].second >= last) {
			ans++;
			last = a[i].first;
		}
	}
	cout << ans << endl;
}
 
int main(int argc, char* argv[]) {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	Input(); Solve(); return 0;
}
