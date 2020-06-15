/*
Author: Ngo Quang Huy
Problem: Kruskal using DSU
*/
#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>
#include <queue>
#include <deque>
#include <map>
#include <cmath>
#include <string>
#include <cstdlib>
#include <cstring>
#include <sstream>
#define i64 long long
#define db double
#define ld long double
#define pub push_back
#define puf push_front
#define pob pop_back
#define pof pop_front
#define mmap multimap
#define mset multiset
#define umap unordered_map
#define uset unordered_set
#define ummap unordered_multimap
#define umset unordered_multiset
#define FOR(i,a,b) for(i64 i=a; i<=b; i++)
#define FORD(i,a,b) for(i64 i=a; i=>b; i--)
#define FORV(i,a) for(typeof(a.begin()) i=a.begin(); i!=a.end();i++)
#define YES cout << "YES \n";
#define NO cout << "NO \n";
#define pq priority_queue
#define mp make_pair
#define fi first
#define se second

using namespace std;
const i64 mod = 1000000007;
const long double PI = 3.14159265358979323846264338327950288419716939937510582097494459230;
typedef pair<i64,i64> pii;
typedef pair<i64, pii> pip;
typedef pair <pii, i64> ppi;
typedef vector <pii> vii;
typedef vector <pip> vip;
typedef vector <ppi> vpi;

i64 n, m, par[105], Rank[105], root[105], w, p, q, sw;
vpi edge;

bool sort_by_se(const ppi &a, const ppi &b){
	return a.se < b.second;
}
void make_set(){
	memset(par, -1, sizeof(par));
	memset(Rank, 0, sizeof(Rank));
}
int Find(int x){
	return (par[x] < 0) ? x : (par[x] = Find(par[x]));
}
void Union(int x, int y){
	int u = Find(x); int v = Find(y);
	if(u == v) return;
	if(Rank[u] == Rank[v]) Rank[u]++;
	if(Rank[u] < Rank[v]) par[u] = v;
	else par[v] = u;
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t = 0; cin >> t;
	while (t--){
		cin >> n >> m;
		make_set();
		sw = 0;
		while (m--){
			cin >> p >> q >> w;
			edge.pub(mp(mp(p, q), w));
		}
		sort(edge.begin(), edge.end(), sort_by_se);
		FOR(i,1,n){
			if(Find(edge[i].fi.fi) != Find(edge[i].fi.se)){
				Union(edge[i].fi.fi, edge[i].fi.se);
				sw += edge[i].se;
			}  
		}
		cout << sw << endl;
	}
	return 0;
}

