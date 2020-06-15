#include <iostream>
#include <queue>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int t = 0;
	cin >> t;
	while (t--){
		int dem = 0;
		long long n; cin >> n;
		queue <double> Q;
		Q.push(1);
		while (!Q.empty()){
			double temp = Q.front(); Q.pop();
			if(temp <= n){
				dem++;
				Q.push(temp*10);
				Q.push(temp*10 + 1);
			}
		}
		cout << dem << endl;
	}
}
