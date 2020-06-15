/*
Author: Ngo Quang Huy
Problem: H - Cay khung nho nhat - Minimum spanning trees
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

/*
///////////////////////////////////////////////////////////////////
////////////////////////// FERMAT'S LITTLE THEOREM ////////////////
///////////////////////////////////////////////////////////////////

int fast_pow(i64 base, i64 n, i64 M){
    if(n==0)
       return 1;
    if(n==1)
    return base;
    i64 halfn=fast_pow(base,n/2,M);
    if(n%2==0)
        return ( halfn * halfn ) % M;
    else
        return ( ( ( halfn * halfn ) % M ) * base ) % M;
}
int findMMI_fermat(int n,int M){
    return fast_pow(n,M-2,M);
    // should not perform z = (x/y)%M; instead we should perform y2
    // y2 = findMMI_fermat(y,M) then z = (x*y2)%M
}
*/
i64 n, m, w, sw, par[200005], Rank[200005];
vpi edge;

bool sort_by_se(const ppi &a, const ppi &b){
	return a.se < b.se;
}
i64 Find(int x){
	if(par[x] != x) par[x] = Find(par[x]);
	return par[x];
}

void Union(int x, int y){
	i64 u = Find(x); i64 v = Find(y);
	if(u == v) return;
	if(Rank[x] == Rank[y]) Rank[x]++;
	if(Rank[x] < Rank[y]) par[u] = v;
	else par[v] = u;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t = 0; cin >> t;
	while (t--){
		cin >> n >> m;
		FOR(i,1,n) par[i] = i;
		memset(Rank, 0, sizeof(Rank));
		sw = 0;
		while (m--){
			int u, v; cin >> u >> v >> w;
//			edge.push_back(mp(mp(u,v),w));
			cin >> edge[i].u >> edge[i].v >> edge[i].w;
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
