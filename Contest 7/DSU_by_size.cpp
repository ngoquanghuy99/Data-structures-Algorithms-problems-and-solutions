/**

- Author: Ngo Quang Huy
- Problem: DSU by size
- Note: Initializing par[i] = -1 (i = 1 -> n)
  par[i] = -1 ===> i is an isolated vertex
  par[i] < -1 ===> i is a root with abs(par[i]) nodes (vertices)
  par[i] > 0 ===> is a child of vertex par[i]

**/

#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;
int n, m;
vector <int> par;
int Find(int x){
	return par[x] < 0 ? x : par[x] = Find(par[x]);
}

void Union(int u, int v){
	if((u = Find(u)) == (v = Find(v))) return;
	if(par[v] < par[u]) swap (u,v);
	par[u] += par[v];
	par[v] = u;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	par.resize(n+1); par.assign(par.size(), -1);
	while (m--){
		int u, v; cin >> u >> v;
		if(u > v) swap(u,v);
		Union(u,v);
	}	
	for(int i = 1; i <= n; i++) cout << par[i] << " ";
}
