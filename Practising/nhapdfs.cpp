#include <iostream>
#include <cstring>
#include <stack>
#include <vector>

using namespace std;
bool unused[1100];
int n, m, s;

void dfs(vector<vector<int> > adj){
	unused[s] = false;
	cout << s << " ";
	stack<int> S;
	S.push(s);
	while (!S.empty()){
		int top = S.top();
		S.pop();
		for(int i = 0; i < adj[top].size(); i++){
			int v = adj[top][i];
			if(unused[v]){
				unused[v] = false;
				cout << v << " ";
				S.push(top);
				S.push(v);
				break;
			}
		}
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int t = 0; cin >> t;
	while (t--){
		cin >> n >> m >> s;
		vector<vector<int> > adj;
		adj.resize(n+5);
		while (m--){
			int a, b; cin >> a >> b; 
			adj[a].push_back(b);
			adj[b].push_back(a);
		}
		memset(unused, true, sizeof unused);
		dfs(adj);
	}
}
