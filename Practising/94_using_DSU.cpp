// using Disjoint Set Union
#include <iostream>
#include <vector>
#include <cstring>

using namespace std;
int t, n, m, q;
vector <int> par, Rank;
int Find(int x){
	if(par[x] != x) par[x] = Find(par[x]);
	return par[x];
}

void Union(int x, int y){
	int u = Find(x); int v = Find(y);
	if(u == v) return;
	if(Rank[u] == Rank[v]) Rank[u]++;
	if(Rank[u] < Rank[v]) par[u] = v;
	else par[v] = u;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> t;
	while (t--){
		cin >> n >> m;
		par.resize(n+1);
		for(int i = 1; i <= n; i++) par[i] = i;
		Rank.resize(n+1);
		Rank.assign(Rank.size(), 0);
		while (m--){
			int u, v; cin >> u >> v;
			Union(u,v);
		}
		cin >> q;
		while (q--){
			int x, y; cin >> x >> y;
			cout << (Find(x) == Find(y) ? "YES" : "NO") << endl;
		}
	}
	return 0;
}
