#include <iostream>
#include <stack>
#include <vector>
#include <cstring>

using namespace std;
int t, n, m, u;
bool unused[1005];
void DFS(int u, vector < vector <int> > adj){
	cout << u << " ";
	unused[u] = false;
	stack <int> S;
	S.push(u);
	while (!S.empty()){
		u = S.top(); S.pop();
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
	cin >> t;
	while (t--){
		vector < vector <int> > adj(1005);
		cin >> n >> m >> u;
		while (m--){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		memset(unused, true, sizeof(unused));
		DFS(u, adj);
	}
	return 0;
}
