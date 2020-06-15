#include <stdio.h>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>
using namespace std;

typedef pair<int, int> ii;
const int N=100005, oo=0x3c3c3c3c;
int n, m, d[N];
vector<int> a[N], b[N];

int prim(int u) {
    int Sum = 0;
    priority_queue<ii> qu;
    for (int i=1; i<=n; i++) d[i]=oo;
    qu.push(ii(0, u)); d[u]=0;
    
    while (qu.size()) {
        ii Pop=qu.top(); qu.pop();
        int u=Pop.second, du=-Pop.first;
        if (du!=d[u]) continue;
        Sum+=d[u]; d[u]=0;
        
        for (int i=0; int v=a[u][i]; i++)
        if (d[v] > b[u][i]) { 
            d[v]=b[u][i]; 
            qu.push(ii(-d[v], v)); 
        }
    }
    return Sum;
}

main() {
    scanf("%d%d", &n, &m);
    for (int i=1; i<=m; i++) {
        int x, y, z;
        scanf("%d%d%d", &x, &y, &z);
        a[x].push_back(y);
        b[x].push_back(z);
        a[y].push_back(x);
        b[y].push_back(z);
    }
    for (int i=1; i<=n; i++)
        a[i].push_back(0);
    cout << prim(1) << endl;
}

