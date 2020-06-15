#include <iostream>
#include <vector>

using namespace std;
int a[1005][1005];
vector < vector <int> > adj(1005);
int main(){
	ios_base::sync_with_stdio(false);
	int n; cin >> n;
	for(int i = 1; i <= n; i++) 
		for(int j = 1; j <= n; j++){
			cin >> a[i][j];
			if(a[i][j] == 1 && i > j){
				adj[i].push_back(j);
				adj[j].push_back(i);
			}
		}
	for(int i = 1; i <= n; i++){
		for(int j = 0; j < adj[i].size(); j++)
			cout << adj[i][j] << " ";
		cout << endl;
	}
}
