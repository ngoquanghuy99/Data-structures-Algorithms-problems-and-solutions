#include <iostream>
#include <cstring>
#include <iomanip>
using namespace std;

const int oo = 1000111000;
int a[105][105], n, m;
void minimize(int &a, int b){
	a = a > b ? b : a;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int t = 0; cin >> t;
	while (t--){
		cin >> n >> m;
		for(int i = 1; i <= n; i++) for(int j = 1; j <= n; j++) a[i][j] = oo;
		for(int i = 1; i <= n; i++) a[i][i] = 0;
		while (m--){
			int u, v;
			cin >> u >> v;
			a[u][v] = 1;
		}
		for(int k = 1; k <= n; k++) 
			for(int i = 1; i <= n; i++)
				for(int j = 1; j <= n; j++)
					minimize(a[i][j], a[i][k] + a[k][j]);
		int sum = 0; int dem = 0;
		for(int i = 1; i <= n; i++)
			for(int j = 1; j <= n; j++)
				if(a[i][j] != oo && a[i][j] != 0){
					sum += a[i][j];
					dem ++;
				}
	//	cout << sum << " " << dem << " --- " << endl;
		cout << fixed << setprecision(2) << ((1.0*sum) / (1.0*dem)) << endl;
	}
}
