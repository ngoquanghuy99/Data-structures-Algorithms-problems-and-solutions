#include <iostream>
#include <queue>
#include <cstring>

using namespace std;
int n, m, u, v;
bool unused[1005];

void BFS(int u, int v, vector < vector <int> > adj){
	unused[u] = false;
	queue <int> Q;
	Q.push(u);
	while (!Q.empty()){
		
	}
	
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int t = 0; cin >> t;
	while (t--){
		vector < vector <int> > adj(1005);
		cin >> n >> m >> u >> v;
		while (m--){
			int x, y; cin >> x >> y;
			adj[x].push_back(y);
			adj[y].push_back(x);
		}
		
	}
}
