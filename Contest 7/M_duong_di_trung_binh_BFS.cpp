#include <iostream>
#include <iomanip>
#include <queue>
#include <cstring>
#include <vector>
#define y1 you_light_my_fire
#define y2 i_will_not_leave_till_its_ourtime
#define x1 you_know_that_i_cant_stop_think_about_you
#define x2 your_the_source_of_every_thing_i_do
using namespace std;
int n, m;
vector <vector<int> > adj, dislist;
bool unused[100005];
void BFS(int x){
	int dem = 1;
	unused[x] = false; queue <int> Q; Q.push(x); 
	while (!Q.empty()){
		int u = Q.front(); Q.pop();
		for(int i = 0; i < adj[u].size(); i++){
			int v = adj[u][i]; 
			if(unused[v]){
				unused[v] = false; Q.push(v); dislist[x].push_back(dem);
			}
		}
		dem++;
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int t = 0; cin >> t;
	while (t--){
		adj.clear();
		dislist.clear();
		cin >> n >> m;
		adj.resize(n+1);
		dislist.resize(n+1);
		memset(unused, true, n+1);
		while (m--){
			int u, v; cin >> u >> v;
			adj[u].push_back(v);
		}
		int dis = 0; int ed = 0;
		for(int i = 1; i <= n; i++){
			BFS(i);
			for(int j = 0; j < dislist[i].size(); j++){
				ed += j;
				dis += dislist[i][j];
			}
			memset(unused, true, n+1);
		}
		double ans = ((1.0*dis)/(1.0*ed));
	//	printf("%.2f \n", ans);
		cout << fixed << setprecision(2) << ans << endl;
	}
	return 0;
}
