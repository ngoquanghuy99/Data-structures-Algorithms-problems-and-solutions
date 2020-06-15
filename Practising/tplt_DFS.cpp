#include <iostream>
#include <stack>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
int n, m;
vector <int> adj[100005];
// or we can declare "vector <int> adj[100005]" but we have to clear this array of vectors in a different way!
bool unused[100005];

void DFS(int u){
	cout << u << " ";
	unused[u] = false;
	stack <int> S;
	S.push(u);
	while (!S.empty()){
		u = S.top();
		S.pop();
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
	int t = 0;
	cin >> t;
	while (t--){
		//adj.clear();
		cin >> n >> m;
		memset(unused, true, sizeof(unused));
		while (m--){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		for(int i = 1; i <= n; i++)
			if(unused[i])
				DFS(i);
	}
	return 0;
}
