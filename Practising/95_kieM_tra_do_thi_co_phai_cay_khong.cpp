#include <iostream>
#include <stack>
#include <vector>
#include <cstring>
using namespace std;
int t, n;
bool unused[1005];

void DFS(int u, vector < vector <int> > adj){
	unused[u] = false;
	stack <int> S;
	S.push(u);
	while (!S.empty()){
		u = S.top();
		S.pop();
		for(int i = 0; i < adj[u].size(); i++){
			int v = adj[u][i];
			if(unused[v]){
				unused[v] = false;
				S.push(u);
				S.push(v);
				break;
			}
		}
	}
}

bool isConnected(){
	for(int i = 1; i <= n; i++) if(unused[i]) return false;
	return true;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> t;
	while (t--){
		cin >> n; int x = n - 1;
		vector < vector <int> > adj(1005);
		while (x--){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		memset(unused, true, sizeof(unused));
		DFS(1, adj);
		cout << (isConnected() ? "YES" : "NO") << endl;
	}
	return 0;
}
