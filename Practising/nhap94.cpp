#include <iostream>
#include <vector>

using namespace std;
int n, m, q;
vector<int> par, Rank;

int Find(int x){
	if(par[x] != x) par[x] = Find(par[x]);
	return par[x];
}

void Union(int x, int y){
	int u = Find(x), v = Find(y);
	if(u == v) return;
	if(Rank[u] == Rank[v]) Rank[u]++;
	if(Rank[u] < Rank[v]) par[u] = v;
	else par[v] = u;
}
int main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t = 0; cin >> t;
	while (t--){
		cin >> n >> m;
		par.resize(n+1); Rank.resize(n+1);
		Rank.assign(Rank.size(), 0);
		for(int i = 1; i <= n; i++) par[i] = i;
		while (m--){
			int x, y; cin >> x >> y;
			Union(x, y);
		}
		cin >> q;
		while (q--){
			int u, v; cin >> u >> v;
			cout << (Find(u) == Find(v) ? "YES" : "NO") << endl;
		}
	}
	return 0;
}
