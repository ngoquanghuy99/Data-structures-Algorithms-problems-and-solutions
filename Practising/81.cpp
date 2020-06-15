#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

typedef pair <int, int> pii;
int r, c, a[505][505];
void solve(){
	cin >> r >> c;
	int x[] = {-1, 0, 1, 0};
	int y[] = {0, 1, 0, -1};
	int vis[505][505];
	int ans = 0;
	memset(vis, 0, sizeof vis);
	queue <pii> Q;
	for(int i = 0; i < r; i++)
		for(int j = 0; j < c; j++){
			cin >> a[i][j];
			if(a[i][j] == 2){
				Q.push({i,j});
				vis[i][j] = 1;
			}
		}

	while (!Q.empty()){
		vector <pii> temp;
		while (!Q.empty()){
			pii u = Q.front(); Q.pop();
			for(int k = 0; k < 4; k++){
				int rr = u.first + x[k];
				int cc = u.second + y[k];
				if(rr >= 0 && cc >= 0 && rr < r && cc < c && vis[rr][cc] == 0 && a[rr][cc] == 1){
					temp.push_back({rr,cc});
					vis[rr][cc] = 1;
					a[rr][cc] = 2;
				}
			}
		}
		for(int k = 0; k < temp.size(); k++)
			Q.push(temp[k]);
		if(!Q.empty()) ans++;
	}
	for(int i = 0; i < r; i++)
		for(int j = 0; j < c; j++)
			if(a[i][j] == 1){
				cout << -1;
				return;
			}
	cout << ans;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	solve();
}
