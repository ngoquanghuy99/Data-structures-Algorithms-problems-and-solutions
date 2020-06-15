#include <bits/stdc++.h>
using namespace std;
int n, m, u, v;
bool unused[1005];
int trace[1005];

void DFS(int u, int v, vector<vector<int> > adj){
	unused[u] = false;
	stack <int> S;
	S.push(u);
//	cout << u << " ";
	while (!S.empty()){
		int a = S.top(); S.pop();
		for(int i = 0; i < adj[a].size(); i++){
			int b = adj[a][i];
			if(unused[b]){
//				cout << b << " ";
				unused[b] = false;
				S.push(a);
				S.push(b);
				trace[b] = a;
				break;
			}
		}
	}
	if(trace[v] == 0){
		cout << -1 << endl;
		return;
	}
	int x = v, dem = 0;
	while (x != u){
		dem++;
	//	cout << x << " ";
		x = trace[x];
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
		while (m--){
			int x, y; cin >> x >> y;
			adj[x].push_back(y);
			adj[y].push_back(x);
		}
		memset(unused, true, sizeof unused);
		memset(trace, 0, sizeof trace);
		DFS(u,v,adj);
	}
	return 0;
}
