#include <bits/stdc++.h>
using namespace std;


string s[101];
bool unused[101][101];
int n, m;

void DFS(int u, int v){
	unused[u][v] = false;
	for(int i = u - 1; i <= u + 1; ++i)
		for(int j = v - 1; j <= v + 1; ++j)
			if(s[i][j] == 'W' && unused[i][j])
				DFS(i,j);
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	int dem = 0;
	for(int i = 0; i < n; ++i) 
		cin >> s[i];
	for(int i = 0; i < n; ++i)
		for(int j = 0; j < m; ++j) 
			unused[i][j] = true;
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < m; ++j){
			if(s[i][j] == 'W' && unused[i][j]){
				DFS(i,j);
				dem++;
			}
		}
	}
	cout << dem;
	return 0;
}
