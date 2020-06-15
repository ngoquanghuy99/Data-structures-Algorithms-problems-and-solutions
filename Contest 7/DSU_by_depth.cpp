/**

Author: Ngo Quang Huy
Problem: DSU by depth
Note: Initializing par[i] = i (i = 1 -> n), Rank[i] = 0 (i = 1 -> n)

**/

#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
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
	int n, m;
	cin >> n >> m;
	par.resize(n+1); 
	for (int i = 1; i <= n; i++) par[i] = i;
	Rank.resize(n+1); 
	Rank.assign(Rank.size(), 0);
	while (m--){
		int u, v;
		cin >> u >> v;
		Union(u,v);
	}
	for (int i = 1; i <= n; i++) cout << i << " -> " << Find(i) << endl;
	return 0;
}
