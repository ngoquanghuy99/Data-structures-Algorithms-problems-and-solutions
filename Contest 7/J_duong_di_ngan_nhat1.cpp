#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int oo = 1000111000;
typedef pair<int, int> ii;

vector <ii> a[2309];
int n, m;

int d[2309];

vector <int> rs[2000];

void dijkstra(int x){
    priority_queue <ii, vector<ii>, greater<ii> > pq;
    int i, u, v, du, uv;
    for (i=1; i<=n; i++) d[i] = oo;
    d[x] = 0;
    pq.push(ii(0, x));

    while (pq.size()){
        u=pq.top().second;
        du=pq.top().first;
        pq.pop();
        if (du!=d[u]) continue;

        for (i=0; v=a[u][i].second; i++)
        {	
            uv=a[u][i].first;
            if (d[v]>du+uv) {
                d[v]=du+uv;
                pq.push(ii(d[v], v));
            }
        }
    }
	for(int i = 1; i <= n; i++)
		rs[x].push_back(d[i]);
}

main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
    int p, q, i, m, w;
    cin >> n >> m;
    while (m--){
        cin >> p >> q >> w;
        a[p].push_back(ii(w, q));
        a[q].push_back(ii(w, p));
    }
    for (i=1; i<=n; i++) a[i].push_back(ii(0,0));
    int time;
    cin >> time;
    
    for(int i = 1; i <= n; i++) dijkstra(i);
    while(time--){
    	int x, y;
    	cin >> x >> y;
    	cout << rs[x][ y - 1] << endl;
	}
	return 0;
}
