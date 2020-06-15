#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#define FOR(i,a,b) for(int i = a; i <= b; i++) 

using namespace std;
int n, m, sumdeg, sumver;
vector <int> par, deg;
void init(){
	cin >> n >> m;
	par.resize(n+1); par.assign(par.size(), -1);
	deg.resize(n+1); deg.assign(deg.size(), 0);
}

int Find(int x){
	return par[x] < 0 ? x : par[x] = Find(par[x]);
}

void Union(int u, int v){
	if((u = Find(u)) == (v = Find(v))) return;
	if(par[v] < par[u]) swap(u,v);
	par[u] += par[v];
	par[v] = u;
}
void process(){
	int u, v;
	while (m--){
			cin >> u >> v;
			if(u > v) swap(u,v);
			deg[u] ++; deg[v] ++;
			Union(u,v);
	}
	int mrk = 1;
	FOR(i,1,n){
		if(par[i] < -1){
			int sumver = -1*par[i];
			int sumdeg = deg[i];
			FOR(j,i+1,n)
				if(par[j] == i) sumdeg += deg[j];
			if(sumver*(sumver-1)/2 != sumdeg/2) {
				mrk = 0; break;
			}
		}
	}
	cout << (mrk == 1 ? "YES" : "NO");
	cout << endl;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int t = 0; cin >> t;
	while (t--){
		init();
		process();
	}
	return 0;
}
