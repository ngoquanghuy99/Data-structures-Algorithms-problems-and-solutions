#include <queue>
#include <iostream>
#define i64 long long
using namespace std;
i64 n, t;
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> t;
	while (t--){
		cin >> n;
		queue <double> q;
		q.push(1); 
		int dem = 0;
		while (!q.empty()){
			double t = q.front();
			q.pop();
			if(t <= n){
				dem++;
				q.push(t* 10);
				q.push(t * 10 + 1);
			}
		}
		cout << dem << endl;
	}
	return 0;
}












