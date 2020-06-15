#include <iostream>
#include <vector>
#include <stack>

using namespace std;
int n, m, q, x, y;
bool unused[1005];
void DFS(int u, vector<vector<int> > ke, int truoc[]){
	unused[u] = false;
	stack <int> s;
	s.push(u);
	while (!s.empty()){
		u = s.top();
		s.pop();
		for(int i = 0; i < ke[u].size(); i++){
			int v = ke[u][i];
			if(unused[v]){
				unused[v] = false;
				s.push(u);
				s.push(v);
				truoc[v] = u;
				break;
			}
		}
	}
}
void init(){
	for(int i= 1; i <= n; i++) unused[i] = true;
}
int main(){
	int t = 0;
	cin >> t;
	while (t--){
		vector<vector<int> > ke(1005);
		cin >> n >> m;
		for(int i = 1; i <= m; i++){
			int u, v;
			cin >> u >> v;
			ke[u].push_back(v);
			ke[v].push_back(u);
		}
		cin >> q;
		while (q--){
			cin >> x >> y;
			init();
			int truoc[1005] = {0};
			DFS(x,ke,truoc);
			truoc[y] == 0 ? cout << "NO" << endl : cout << "YES" << endl;
		}
	}
}
