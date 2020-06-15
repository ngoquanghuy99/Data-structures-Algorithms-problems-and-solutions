#include <bits/stdc++.h>
#define LL long long
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define maxn 100005

using namespace std;

typedef pair<LL,int>II;
const LL Linfi = 1e18;

int n, m, u, v, k, x, c;
vector<II> adj[maxn];
LL d[maxn], F[maxn];
priority_queue<II, vector<II>, greater<II> > Q;

void solve() {
	memset(F,0,sizeof(F));
	for(int i=1;i<=n;i++){
		d[i] = Linfi;
	}
	d[1] = 0; F[1] = 1;
	Q.push(mp(0,1));
	while(!Q.empty()){
		u = Q.top().se; Q.pop();
		if(u == n){
			cout << d[u] << " " << F[u] << endl;
			return;
		}
		for(int i=0;i<adj[u].size();i++){
			v = adj[u][i].se;
			int d_u_v = adj[u][i].fi;
			if(d[u] + d_u_v < d[v]){
				d[v] = d[u] + d_u_v;
				F[v] = F[u];
				Q.push(mp(d[v], v));
			}
			else if(d[u] + d_u_v == d[v]) F[v] += F[u];
		}
	}
}
main() {
    cin >> n >> m;
    for(int i=1;i<=m;i++){
		scanf("%d %d %d",&u, &v, &c);
        adj[u].pb(mp(c,v));
        adj[v].pb(mp(c,u));
    }
    solve();
}

