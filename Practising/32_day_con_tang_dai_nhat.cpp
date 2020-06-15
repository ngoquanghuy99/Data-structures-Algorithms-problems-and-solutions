#pragma GCC optimize("Ofast")
 
#include <bits/stdc++.h>
using namespace std;
 
int n; vector<int> a;
 
void Input() {
	cin >> n; a.resize(n);
	for(auto &z : a) cin >> z;
}
 
void Solve() {
	vector <int> L;
	for(int i = 0; i < n; i++){
		int id = lower_bound(L.begin(), L.end(), a[i]) - L.begin();
		if(id == L.size()) L.push_back(a[i]);
		else L[id] = a[i];
	}
	cout << L.size();
}
 
int main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	Input(); Solve(); return 0;
}
 
