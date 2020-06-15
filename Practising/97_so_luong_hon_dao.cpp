#include <bits/stdc++.h>
using namespace std;
typedef pair <int, int> pii;
int n, m, a[505][505];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int t = 0; cin >> t;
	while (t--){
		cin >> n >> m;
		for(int i = 0; i < n; i++) for(int j = 0; j < m; j++) cin >> a[i][j];
		int dem = 0;
		int r[] = {1, 1, 1, 0, 0, -1, -1, -1};
		int c[] = {-1, 0, 1, -1, 1, -1, 0, 1};
		
		for(int i = 0 ; i < n; i++){
			for(int j = 0; j < m; j++){
				if(a[i][j] == 1){
					dem++;
					queue <pii> Q;
					Q.push({i,j});
					while (!Q.empty()){
						pii u = Q.front(); Q.pop();
						for(int k = 0; k < 8; k++){
							int x = u.first + r[k];
							int y = u.second + c[k];
							if(x >= 0 && y >= 0 && x < n && y < m && a[x][y] == 1){
								a[x][y] = 0;
								Q.push({x,y});
							}
						}
					}
				}
			}
		}
		cout << dem << endl;
	}
}
