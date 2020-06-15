#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int x[] = {0, -2, -1, 1, 2, 2, 1, -1, -2};
int y[] = {0, -1, -2, -2, -1, 1, 2, 2, 1};

int Spreadout(int a1, int b1, int a2, int b2){
	int moves[9][9], vis[9][9];
	queue < pair <int, int> > Q;
	Q.push({a1, b1});
	memset(moves, 0, sizeof moves);
	memset(vis, 0, sizeof vis);
	vis[a1][b1] = 1;
	while (!Q.empty()){
		pair <int, int> u = Q.front(); Q.pop();
		if(u.first == a2 && u.second == b2) return moves[a2][b2];
		for(int k = 1; k <= 8; k++){
			int n = u.first + x[k]; 
			int m = u.second + y[k];
			if(m < 1 || n < 1 || m > 8 || n > 8) continue;
			else{
				vis[n][m] = 1;
				moves[n][m] = moves[u.first][u.second] + 1;
				Q.push({n,m});
			}
		}
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int t = 0; cin >> t;
	char a1, a2;
	int b1, b2;
	while (t--){
		cin >> a1 >> b1 >> a2 >> b2;
		cout << Spreadout(a1 - 'a' + 1, b1, a2 - 'a' + 1, b2) << endl;
	}
}
