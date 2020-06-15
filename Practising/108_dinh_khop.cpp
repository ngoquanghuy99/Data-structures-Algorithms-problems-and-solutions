#pragma GCC optimize("Ofast")
#include <iostream>
#include <vector>
#include <cstring>
#include <queue>

using namespace std;

int n, m, a, b;
bool unused[1100];
int Count, otherver;
vector<pair<int, int> > mrk;
void BFS(int u, vector<vector<int> > adj){
	Count = 1;
	unused[u] = false;
	mrk.push_back({u, 0});
	queue <int> Q;
	Q.push(u);
	while (!Q.empty()){
		int a = Q.front(); Q.pop();
//		cout << a <<"->";
		for(int i = 0; i < adj[a].size(); i++){
			int b = adj[a][i];
			if(unused[b]){
				mrk.push_back({b, 0});
				otherver = b;
				Count++;
				unused[b] = false;
				Q.push(b);
			}
		}
	}
	for(int i = 0; i < mrk.size(); i++) mrk[i].second = Count;
}
void ans(vector<int> arti){
	if(arti.size() == 0){
		cout << 0 << endl;
		return;
	}
	cout << arti.size() << endl;
	for(auto i : arti) cout << i << " ";
	cout << endl;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int t = 0; cin >> t;
	while (t--){
		vector<vector<int> > adj;
		cin >> n >> m;
		adj.resize(n+1); mrk.resize(n+1);
		while (m--){
			int x, y; cin >> x >> y;
			adj[x].push_back(y);
			adj[y].push_back(x);
		}
		memset(unused, true, sizeof unused);
		for(int i = 1; i <= n; i++){
			if(unused[i])
				BFS(i, adj);
		}
		vector<int> arti;
		for(int i = 1; i <= n; i++){
			BFS(i, adj); int sumver = Count;
			memset(unused, true, sizeof unused);
			unused[i] = false;
			if(otherver != 0) BFS(otherver, adj);
			if(Count < sumver-1) arti.push_back(i);
		//	cout << Count << endl;
			memset(unused, true, sizeof unused);
		}
		ans(arti);
	}
	return 0;
}
