#include <bits/stdc++.h>
using namespace std;
bool unused[1100];
int n, m, s;

void dfs(int s, vector<vector<int> > adj){
	unused[s] = false;
	cout << s << " ";
	stack<int> S;
	S.push(s);
	while (!S.empty()){
		int u = S.top(); S.pop();
		for(int i = 0; i < adj[u].size(); i++){
			int v = adj[u][i];
			if(unused[v]){
				cout << v << " ";
				unused[v] = false;
				S.push(u);
				S.push(v);
				break;
			}
		}
	}
	cout << endl;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int t = 0; cin >> t;
	while (t--){
		cin >> n >> m >> s;
		vector<vector<int> > adj;
		adj.resize(n+1);
		while (m--){
			int x, y; cin >> x >> y;
			adj[x].push_back(y);
			adj[y].push_back(x);
		}
		memset(unused, true, sizeof unused);
		dfs(s, adj);
	}
	return 0;
}
