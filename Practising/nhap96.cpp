// kiem tra do thi 2 phia
#include <iostream>
#include <cstring>
#include <queue>
#include <vector>

using namespace std;

int n, m;
int color[1100];

bool tomau(int u, vector<vector<int> > adj, int color[]){
	color[u] = 1;
	queue<int> Q;
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
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t = 0; cin >> t;
	while (t--){
		vector<vector<int> > adj;
		cin >> n >> m; adj.resize(n+1);
		while (m--){
			int x, y; cin >> x >> y;
			adj[x].push_back(y);
			adj[y].push_back(x);
		}
		memset(color, -1, sizeof color);
		bool ans = true;
		for(int i = 1; i <= n; i++){
			if(color[i] == -1){
				if(!tomau(i,adj,color)){
					ans = false;
				}
			}
		}
		cout << (ans ? "YES" : "NO") << endl;
	}
	return 0;
}
