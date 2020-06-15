#include <bits/stdc++.h>

using namespace std;

int n, m;
bool e[30][30];
int ans = 0;

void dfs(int u, int w){
    ans = max(ans, w);
    for (int i = 0;i < n; i++)
        if (e[u][i]){
	        e[u][i] = 0;
	        e[i][u] = 0;
	        dfs(i, w+1);
	        e[u][i] = 1;
	        e[i][u] = 1;
    	}
}

int main(){
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--){
        ans = 0;
        for (int i = 0; i < 30; i++)
            for (int j = 0; j < 30; j++)
                e[i][j] = 0;
        cin >> n>> m;
        for (int i = 1; i <= m; i++){
            int u, v;
            cin >> u >> v;
            e[u][v] = 1;
            e[v][u] = 1;
        }
        for (int i = 0; i < n; i++)
            dfs(i, 0);
        cout << ans << endl;
    }
}

