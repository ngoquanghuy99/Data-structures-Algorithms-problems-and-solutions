#include <iostream>
#include <queue>
#include <cstring>
#include <vector>

using namespace std;
int t, n, m;
bool isBipartite(int u, vector < vector <int> > adj, int color[]){
	queue <int> Q;
	color[u] = 1;
	Q.push(u);
	while (!Q.empty()){
		u = Q.front(); Q.pop();
		for(int i = 0; i < adj[u].size(); i++){
			int v = adj[u][i];
			if(color[v] == color[u]) return false;
			if(color[v] == -1){
				if(color[u] == 1) color[v] = 2;
				else color[v] = 1;
				Q.push(v);
			}
		}
	}
	return true;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> t;
	while (t--){
		vector < vector <int> > adj(1005);
		int color[1005];
		cin >> n >> m;
		while (m--){
			int u, v; cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		for(int i = 1; i <= n; i++) color[i] = -1;
		bool ans = true;
		for(int i = 1; i <= n; i++){
			if(color[i] == -1){
				if(!isBipartite(i,adj,color)){
					ans = false;
					break;
				}
			}
		}
		cout << (ans ? "YES" : "NO") << endl;
	}
}
