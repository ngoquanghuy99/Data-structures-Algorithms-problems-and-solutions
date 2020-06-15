// in node la cay nhi phan tim kiem thu tu truoc

#include <iostream>
#include <stack>
using namespace std;

void solve(int pre[], int n){
	stack <int> S;
	for(int i = 0, j = 1; j < n; i++, j++){
		bool found = false;
		if(pre[i] > pre[j]) S.push(pre[i]);
		else{
			while (!S.empty()){
				if(pre[j] > S.top()){
					S.pop();
					found = true;
				}
				else break;
			}
		}
		if(found) cout << pre[i] << " ";
	}
	cout << pre[n-1];
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int t = 0; cin >> t;
	while (t--){
		int n; cin >> n;
		int pre[n+5];
		for(int i = 0; i < n; i++) cin >> pre[i];
		solve(pre, n);
		cout << endl;
	}
}
