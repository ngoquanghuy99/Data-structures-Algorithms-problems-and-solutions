#include <bits/stdc++.h>
using namespace std;
bool unused[1100];
int truoc[1100];
int n, m, u, v;

void dfs(vector<vector<int> > adj){
	unused[u] = false;
	stack<int> S;
	S.push(u);
	while (!S.empty()){
		int x = S.top(); S.pop();
		for(int i = 0; i < adj[x].size(); i++){
			int y = adj[x][i];
			if(unused[y]){
				unused[y] = false;
				S.push(x);
				S.push(y);
				truoc[y] = x;
				break;
			}
		}
	}
	if(truoc[v] == 0){
		cout << -1 << endl;
		return;
	}
	int t = v, dem = 0;
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
		cin >> n >> m >> u >> v;
		vector<vector<int> > adj;
		adj.resize(n+1);
		while (m--){
			int x, y; cin >> x >> y;
			adj[x].push_back(y);
			adj[y].push_back(x);
		}
		memset(unused, true, sizeof unused);
		memset(truoc, 0, sizeof truoc);
		dfs(adj);
	}
	return 0;
}
