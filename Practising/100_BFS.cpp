#include <iostream>
#include <queue>
#include <cstring>
#include <vector>

using namespace std;

int t, n, m, u;
bool unused[1005];
void BFS(int u, vector < vector <int> > adj){
	unused[u] = false;
	queue <int> Q;
	Q.push(u);
	while (!Q.empty()){
		u = Q.front(); Q.pop(); cout << u << " ";
		for(int i = 0; i < adj[u].size(); i++){
			int v = adj[u][i];
			if(unused[v]){
				unused[v] = false;
				Q.push(v);
			}
		}
	}
	cout << endl;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> t;
	while (t--){
		vector < vector <int> > adj(1005);
		cin >> n >> m >> u;
		while (m--){
			int u, v; cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		memset(unused, true, sizeof(unused));
		BFS(u, adj);
	}
	return 0;
}

