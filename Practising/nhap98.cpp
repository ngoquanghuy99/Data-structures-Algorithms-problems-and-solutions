#include <bits/stdc++.h>
using namespace std;
int k, n, m;
vector<int> p;
vector<vector<int> > adj;
bool unused[1100];
int d[1100];

void BFS(int u){
	queue<int> Q;
	Q.push(u);
	unused[u] = false;
	d[u]++;
	while (!Q.empty()){
		int x = Q.front(); Q.pop();
		d[x]++;
		for(int i = 0; i < adj[x].size(); i++){
			int v = adj[x][i];
			if(unused[v]){
				unused[v] = false;
				Q.push(v);
			}
		}
	}
}
int main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> k >> n >> m; adj.resize(n+1);
	p.resize(n+1);
	for(int i = 0; i < k; i++){
		cin >> p.at(i);
	}
	while (m--){
		int a, b; cin >> a >> b;
		adj[a].push_back(b);
	}
	memset(d, 0, sizeof d);
	for(int i = 0; i < p.size(); i++){
		memset(unused, true, sizeof unused);
		BFS(p[i]);
	}
	int ans = 0;
	for(int i = 1; i <= n; i++){
		if(d[i] == k) ans++;
	}
	cout << ans;
}
