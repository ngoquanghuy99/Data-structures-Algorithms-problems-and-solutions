#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> pii;
void solve(){
	int n = 0; cin >> n;
	char a[n+1][n+1];
	for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) cin >> a[i][j];
	int x1, y1, x2, y2;
	cin >> x1 >> y1 >> x2 >> y2;

	map <pii, int> vis, path;
	queue <pii> Q;
	Q.push({x1,y1});
	vis[{x1,y1}] = 1;
	path[{x1,y1}] = 0;
	while (!Q.empty()){
		pii u = Q.front(); Q.pop();
		if(vis[{x2,y2}]){
			cout << path[{x2,y2}];
			return;
		}
		int r1 = u.first + 1, 
			r2 = u.first - 1,
			c1 = u.second + 1,
			c2 = u.second -1;
		while (r1 < n && a[r1][u.second] == '.' && vis[{r1,u.second}] == 0){
			vis[{r1,u.second}] = 1;
			path[{r1,u.second}] = path[u] + 1;
			Q.push({r1,u.second});
			r1++;
		}
		while (r2 >= 0 && a[r2][u.second] == '.' && vis[{r2,u.second}] == 0){
			vis[{r2,u.second}] = 1;
			path[{r2,u.second}] = path[u] + 1;
			Q.push({r2,u.second});
			r2--;
		}
		while (c1 < n && a[u.first][c1] == '.' && vis[{u.first,c1}] == 0){
			vis[{u.first,c1}] = 1;
			path[{u.first,c1}] = path[u] + 1;
			Q.push({u.first,c1});
			c1++;
 		}
 		while (c2 >= 0 && a[u.first][c2] == '.' && vis[{u.first,c2}] == 0){
 			vis[{u.first,c2}] == 1;
 			path[{u.first,c2}] = path[u] + 1;
 			Q.push({u.first,c2});
 			c2--;
		 }
	}
	cout << -1;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	solve();
	return 0;
}
