#include <bits/stdc++.h>

using namespace std;

int t, n, m, u, v;
bool unused[1100];
int truoc[1100];

void DFS(vector<vector<int> > adj){
	unused[u] = false;
	stack <int> S;
	S.push(u);
	while (!S.empty()){
		int a = S.top(); S.pop();
		for(int i = 0; i < adj[a].size(); i++){
			int b = adj[a][i];
			if(unused[b]){
				unused[b] = false;
				S.push(a); S.push(b); truoc[b] = a;
				break;
			}
		}
	}
	if(!truoc[v]){
		cout << -1 << endl;
		return;
	}
	int dem = 0;
	int temp = v; 
	while (temp != u){
		dem++;
		temp = truoc[temp];
	}
	cout << dem << endl;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> t; 
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
		DFS(adj);
	}
	return 0;
}
