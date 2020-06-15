#include <iostream>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;
int t, n, m, q;
bool unused[1005];

void BFS(int u, vector < vector <int> > adj, int trace[]){
	unused[u] = false;
	queue <int> Q;
	Q.push(u);
	while (!Q.empty()){
		u = Q.front(); Q.pop();
		for(int i = 0; i < adj[u].size(); i++){
			int v = adj[u][i];
			if(unused[v]){
				trace[v] = u;
				unused[v] = false;
				Q.push(v);
			}
		}
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> t;
	while (t--){
		vector < vector <int> > adj(1005);
		cin >> n >> m;
		while (m--){
			int u, v; cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		memset(unused, true, sizeof(unused));
		cin >> q;
		int trace[1005] = {0};
		while (q--){
			int x, y; cin >> x >> y;
			BFS(x, adj, trace);
			cout << (trace[y] != 0 ? "YES" : "NO") << endl;
		}
	}
	return 0;
}
