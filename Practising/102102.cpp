#include <iostream>
#include <queue>
#include <vector>
#include <cstring>

using namespace std;

int t, n, m;
bool unused[1005];
vector<vector<int> > adj(1005);
void BFS(int u){
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
		adj.clear();
		cin >> n >> m;
		while (m--){
			int u, v; cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		memset(unused, true, sizeof(unused));
		for(int i = 1; i <= n; i++){
			if(unused[i]) BFS(i);
		}
	}
	return 0;
}
