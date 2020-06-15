#include <bits/stdc++.h>
using namespace std;
struct data{
    int st, en, cost;
    data(){};
    data(int s, int e, int c){st = s; en = e; cost = c;}
    friend bool operator < (data A, data B){
        return A.cost < B.cost;
    }
};
int n, m, u, v, c;
data E[200005];
int parent[200005];

int findset(int i) {
    if(parent[i] < 0) return i;
    parent[i] = findset(parent[i]);
    return parent[i];
}

void MST(){
    long long d = 0;
    memset(parent,-1,sizeof(parent));
    sort(E+1, E+m+1);
    for(int i=1;i<=m;i++){
        int u = findset(E[i].st);
        int v = findset(E[i].en);
        if(u != v){
            parent[u] = v;
            d += E[i].cost;
        }
    }
    cout << d << endl;
}
main(){
    int t;cin>>t;
    while(t--){
        cin >> n >> m;
        for(int i=1;i<=m;i++){
            cin >> u >> v >> c;
            E[i] = data(u,v,c);
        }
        MST();
    }
}
