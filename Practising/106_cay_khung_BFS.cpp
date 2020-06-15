#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef vector<pii> vii;
int n, m, u;
bool unused[1100];

void tree_BFS(vector<vector<int> > adj, vii tree){
	unused[u] = false;
	queue <int> Q;
	Q.push(u);
	while (!Q.empty()){
		int a = Q.front(); Q.pop();
		for(int i = 0; i < adj[a].size(); i++){
			int b = adj[a][i];
			if(unused[b]){
				unused[b] = false;
				Q.push(b);
				tree.push_back(make_pair(a,b));
			}
		}
	}
	if(tree.size() < n-1) cout << -1 << endl;
	else for(auto i : tree) cout << i.first << " " << i.second << endl;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int t = 0; cin >> t;
	while (t--){
		cin >> n >> m >> u;
		vector<vector<int> > adj;
		vii tree;
		adj.resize(n+1);
		while (m--){
			int x, y; cin >> x >> y;
			adj[x].push_back(y);
			adj[y].push_back(x);
		}
		memset(unused, true, sizeof unused);
		tree_BFS(adj, tree);
	}
	return 0;
}
