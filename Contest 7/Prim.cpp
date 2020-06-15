/**

Author: Ngo Quang Huy
ID: B17DCCN311
Problem: Prim algorithm 
Note: in Kruskal implementation using DSU, i use pair <pair<int, int>, int>
to store first vertices, last vertices, and their weights between them
but in this Prim implementation, i use two vector 2D (array of vectors), 
the first vector to store like adjacency list, the second to store weights

**/
#include <iostream>
#include <cstring>
#include <string>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <queue>
#define pub push_back
#define mp make_pair
#define se second
#define fi first
using namespace std;
typedef pair <int, int> pii;
typedef vector <pii> vii;
int n, m, dis[1005];
vector < vector <int> > adj(1005), weight(1005);
const int oo = 0x3c3c3c3c;

int Prim(int u){
	int SW = 0;
	priority_queue <pii> pQ;
	memset(dis, oo, sizeof(dis));
	pQ.push(mp(0,u)); dis[u] = 0;
	
	while (!pQ.empty()){
		pii Pop = pQ.top(); pQ.pop();
		int u = Pop.se, du = -Pop.fi;
		if(du != dis[u]) continue;
		SW += dis[u]; dis[u] = 0;
		for(int i = 0; int v = adj[u][i]; i++)
			if(dis[v] > weight[u][i]){
				dis[v] = weight[u][i];
				pQ.push(mp(-dis[v], v));
			}
	}
	return SW;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int t = 0;
	cin >> t;
	while (t--){
		cin >> n >> m;
		while (m--){
			int u, v, w;
			cin >> u >> v >> w;
			adj[u].pub(v);
			adj[v].pub(u);
			weight[u].pub(w);
			weight[v].pub(w);
		}
		for(int i = 1; i <= n; i++) adj[i].pub(0);
		cout << Prim(1) << endl;
	}
	return 0;
}
