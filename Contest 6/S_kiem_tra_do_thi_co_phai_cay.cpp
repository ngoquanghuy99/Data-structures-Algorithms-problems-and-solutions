#include <iostream>
#include <vector>
#include <stack>
using namespace std;
//vector < vector <int> > adj(1001);
bool unused[1001];
int n;
void init(){
	for(int i = 1; i <= n; i++ ) unused[i] = true;
}
void DFS(int u, vector < vector <int> > adj){
	stack <int> S;
	S.push(u);
	unused[u] = false;
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
	for(int i = 1; i <=n ; i++)
		if(unused[i]) return false;
	return true;
}
int main(){
	int t = 0;
	cin >> t;
	while (t--){
		cin >> n;
		vector < vector <int> > adj(1001);
		for(int i = 1; i <= n-1; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		init();
		DFS(1, adj);
		if(isConnected()) cout << "YES" << endl;
		else cout << "NO" << endl;
		// or we can count how many times the DFS function is called, if > 1 not, else yes :)
	}
}
