#include <bits/stdc++.h>
using namespace std;
int n, m, u, v;
bool unused[1100];
int truoc[1100];

void bfs(vector<vector<int> > adj){
	unused[u] = false;
	queue<int> Q;
	Q.push(u);
	while (!Q.empty()){
		int x = Q.front(); Q.pop();// cout << x << " ";
		for(int i = 0; i < adj[x].size(); i++){
			int y = adj[x][i];
			if(unused[y]){
				unused[y] = false;
				Q.push(y);
				truoc[y] = x;
			}
		}
	}
	if(truoc[v] == 0){
		cout << -1 << endl;
		return;
	}
	int t = v;
	int dem = 0;
	while (t != u){
		dem++;
		t = truoc[t];
	}
	cout << dem << endl;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int t = 0; cin >> t;
	while (t--){
		vector<vector<int> > adj;
		cin >> n >> m >> u >> v;
		adj.resize(n+1);
		while (m--){
			int x, y; cin >> x >> y;
			adj[x].push_back(y);
			adj[y].push_back(x);
		}
		memset(unused, true, sizeof unused);
		memset(truoc, 0, sizeof truoc);
		bfs(adj);
//		bfs(s, adj);
	}
	return 0;
}
