#include <bits/stdc++.h>
#define i64 long long
using namespace std;
string s[101];
int n, m, dem;
bool unused[110][110];

void dfs(int u, int v){
	for(int i = u-1; i <= u+1; i++){
		for(int j = v-1; j <= v+1; j++){
			if(s[i][j]=='W' && unused[i][j]){
				dfs(i,j);
			}
		}
	}
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for(int i = 0; i < n; i++) cin >> s[i];
	memset(unused, true, sizeof unused);
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			if(s[i][j] == 'W' && unused[i][j]){
				dfs(i,j);
				dem++;
			}
		}
	}
	cout << dem;
	return 0;
}


