// 99 quan ma
#include <iostream>
#include <cstring>
#include <queue>
using namespace std;
typedef pair<int, int> pii;

int spread(int a1, int b1, int a2, int b2){
	int r[] = {0, -2, -1, 1, 2, 2, 1, -1, -2};
	int c[] = {0, -1, -2, -2, -1, 1, 2, 2, 1};
	int moves[9][9], vis[9][9];
	memset(moves, 0, sizeof moves); 
	memset(vis, 0, sizeof vis);
	queue<pii> Q;
	Q.push({a1, b1});
	vis[a1][b1] = 1;
	while (!Q.empty()){
		pii u = Q.front(); Q.pop();
		if(u.first == a2 && u.second == b2) return moves[a2][b2];
		for(int k = 1; k < 9; k++){
			int x = u.first + r[k];
			int y = u.second + c[k];
			if(x < 1 || y < 1 || x > 8 || y > 8) continue;
			else{
				moves[x][y] = moves[u.first][u.second] + 1;
				vis[x][y] = 1;
				Q.push({x, y});
			}
		}
	}
}
int main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t = 0; cin >> t;
	char a1, a2; int b1, b2;
	while (t--){
		cin >> a1 >> b1 >> a2 >> b2;
		cout << spread(a1-'a'+1, b1, a2-'a'+1, b2) << endl;
	}
	return 0;
}
