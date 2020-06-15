#include <bits/stdc++.h>
using namespace std;

int n, m, u, v;
bool unused[1005];
int d[1005];
void BFS(int u, int v, vector<vector<int> > adj){
	queue <int> Q;
	Q.push(u);
	unused[u] = false;
	while (!Q.empty()){
		int a = Q.front(); Q.pop();
		for(int i = 0; i < adj[a].size(); i++){
			int b = adj[a][i];
			if(unused[b]){
				d[b] = a;
				unused[b] = false;
				Q.push(b);
			}
		}
	}
	if(d[v] == 0){
		cout << -1 << endl;
		return;
	}
	int x = v, dem = 0;
	while (x != u){
		dem++;
		x = d[x];
	}
	cout << dem << endl;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int t = 0; cin >> t;
	while (t--){
		vector<vector<int> > adj(1005);
		cin >> n >> m >> u >> v;
		memset(unused, true, sizeof(unused));
		while (m--){
			int x, y; cin >> x >> y;
			adj[x].push_back(y);
			adj[y].push_back(x);
		}
		memset(d, 0, sizeof d);
		BFS(u, v, adj);
	}
}

