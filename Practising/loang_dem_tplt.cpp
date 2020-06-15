#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define y1 youknowthaticantstopthinkinboutyou
#define y2 yourethesourceofeverythingido
using namespace std;

typedef pair <int, int> pii;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int t = 0; cin >> t;
	while (t--){
		int n, m, a[505][505];
		int connected_components = 0;
		int x[] = {-1, -1, -1, 0, 0, 1, 1, 1};
		int y[] = {-1, 0, 1, -1, 1, -1, 0, 1};
		cin >> n >> m;
		for(int i = 0; i < n; i++) for(int j = 0; j < m; j++) cin >> a[i][j];
		queue <pii> Q;
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				if(a[i][j] == 1){
					connected_components++;
					Q.push({i,j});
					while (!Q.empty()){
						pii u = Q.front(); Q.pop();
						for(int k = 0; k < 8; k++){
							int r = u.first + x[k];
							int c = u.second + y[k];
							if(r >= 0 && c >= 0 && r < n && c < m && a[r][c] == 1){
								a[r][c] = 0;
								Q.push({r,c});
							}
						}
					}
				}
			}
		}
		cout << connected_components << endl;
	}
	return 0;
}
