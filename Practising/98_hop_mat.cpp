#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

vector < vector <int> > adj(1005);
vector <int> p;
int k, n, m;
int d[1005];
bool unused[1005];
int dem = 0;

void BFS(int u){
	queue <int> Q;
	Q.push(u);
	unused[u] = false;
	while (!Q.empty()){
		u = Q.front(); Q.pop();
		d[u]++;
		for(int i = 0; i < adj[u].size(); i++){
			int v = adj[u][i];
			if(unused[v]){
				Q.push(v);
				unused[v] = false;
			}
		}
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> k >> n >> m;
	int k1 = k;
	while (k1--){
		int x; cin >> x;
		p.push_back(x);
	}
	while (m--){
		int u, v; cin >> u >> v;
		adj[u].push_back(v);
	}
	memset(d, 0, sizeof d);
	for(int i = 0; i < p.size(); i++){
		memset(unused, true, sizeof unused);
		BFS(p[i]);
	}
	for(int i = 1; i <= n; i++)
		if(d[i] == k) dem++;
	cout << dem;
}
