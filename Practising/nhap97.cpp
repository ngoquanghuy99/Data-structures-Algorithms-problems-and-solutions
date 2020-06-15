// 97 So luong hon dao - using Loang
#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> pii;

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t = 0; cin >> t;
	while (t--){
		int Count = 0;
		int n, m; cin >> n >> m; int a[n+1][m+1];
		for(int i = 0; i < n; i++) for(int j = 0; j < m; j++) cin >> a[i][j];
		int r[] = {-1, -1, -1, 0, 0, 1, 1, 1};
		int c[] = {-1, 0, 1, -1, 1, -1, 0, 1};
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				if(a[i][j]){
					Count++;
					queue<pii> Q; Q.push({i, j});
					while (!Q.empty()){
						pii u = Q.front(); Q.pop();
						for(int k = 0; k < 8; k++){
							int x = u.first + r[k];
							int y = u.second + c[k];
							if(x >= 0 && y >= 0 && x < n && y < m && a[x][y]){
								a[x][y] = 0;
								Q.push({x, y});
							}
						}
					}
				}
			}
		}
		cout << Count << endl;
	}
}
