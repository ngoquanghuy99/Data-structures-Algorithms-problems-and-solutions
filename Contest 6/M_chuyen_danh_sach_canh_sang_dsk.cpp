/*
Author: Ngo Quang Huy
Problem: M - Chuyen danh sach canh sang danh sach ke
*/
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>

using namespace std;
int n, m;
vector < vector <int> > adj(55);

int main(){
	cin >> n >> m;
	for(int i = 1; i <= m; i++){
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	for(int i = 1; i <= m; i++)
		sort(adj[i].begin(), adj[i].end());
	for(int i = 1; i <= n; i++){
		for(int j = 0; j < adj[i].size(); j++){
			cout << adj[i][j] << " ";
		}
		cout << endl;
	}
}
