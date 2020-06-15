#include <iostream>
#include <unordered_map>
#define FOR(i,a,b) for(int i = a; i <= b; i++)
using namespace std;
int n, m;
int par[100005], Rank[100005], root[100005];

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
	int t = 0; cin >> t;
	while (t--){
		cin >> n >> m;
		FOR(i,1,n){ 
			Rank[i] = 0; 
			par[i] = i; 
		}
		while (m--){
			int u, v; 
			cin >> u >> v; 
			Union(u,v); 
		}
		unordered_map <int, int> hash;
		FOR(i,1,n){
			root[i] = Find(i);
			hash[root[i]]++;
		} 
		int max_count = 0, res = -1;
		for(auto i : hash){
			if(i.second > max_count){
				max_count = i.second;
				res = i.first;
			}
		}
		cout << max_count << endl;
	}
	return 0;
}
