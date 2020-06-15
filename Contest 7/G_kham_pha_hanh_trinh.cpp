#include <bits/stdc++.h>
#define LL long long
#define maxn 100005
using namespace std;

int n, m, u, v, cntE = 0, self_edge = 0, nComponent;
int xet[maxn], parent[maxn], cnt[maxn];
vector<int> adj[maxn];

int findset(int u){
	return (parent[u] == u ? u : parent[u] = findset(parent[u]));
}

void join(int u,int v){
    parent[findset(u)] = findset(v);
}

void solve(){
    for(int i=1;i<=n;i++) if(xet[i] == 0) nComponent--;
    if(nComponent != 1){
        cout << 0 << endl; return;
    }
    LL ans = 0;
    ans += 1LL*self_edge*(self_edge-1)/2;
    ans += 1LL*self_edge*cntE;
    for(int i=1;i<=n;i++) ans += 1LL*cnt[i]*(cnt[i]-1)/2;
    cout << ans << endl;
}
main(){
    int sotest = 1;
    cin >> sotest;
    while(sotest--){
        cin >> n >> m;
        for(int i=1;i<=n;i++) parent[i] = i;
        self_edge = 0; cntE = 0; nComponent = n;
        memset(xet, 0, sizeof(xet));
        memset(cnt, 0, sizeof(cnt));
        for(int i=1;i<=m;i++){
            cin >> u >> v;
            xet[u] = xet[v] = 1;
            if(findset(u) != findset(v)){
                nComponent--;
                join(u, v);
            }
            if(u != v){
                cnt[u]++; cnt[v]++; cntE++;
            }
            else self_edge++;
        }
        solve();
    }
}
