#include <bits/stdc++.h>
using namespace std;
int n, m, s;
bool unused[1100];


void bfs(int s, vector<vector<int> > adj, vector<pair<int,int> > T){
	unused[s] = false;
	queue<int> Q;
	Q.push(s);
	while (!Q.empty()){
		int u = Q.front(); Q.pop(); //cout << u << " ";
		for(int i = 0; i < adj[u].size(); i++){
			int v = adj[u][i];
			if(unused[v]){
				T.push_back({u, v});
				unused[v] = false;
				Q.push(v);
			}
		}
	}
	if(T.size() != n-1){
		cout << -1 << endl;
		return;
	}
	for(int i = 0; i < T.size(); i++){
		cout << T[i].first << " " << T[i].second << endl;
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int t = 0; cin >> t;
	while (t--){
		vector<vector<int> > adj;
		cin >> n >> m >> s;
		adj.resize(n+1);
		while (m--){
			int x, y; cin >> x >> y;
			adj[x].push_back(y);
			adj[y].push_back(x);
		}
		memset(unused, true, sizeof unused);
		vector<pair<int,int> > T;
		bfs(s, adj, T);
	}
	return 0;
}
