#include <iostream>
#include <vector>

using namespace std;
int n, m;

int solve(vector <int> v){
	int t = 0, i;
	while (v.size() > 1){
		t = (t + m) % v.size();
		vector <int>::iterator k = v.begin();
		i = 0;
		while (i++ < t){
			k++;
		}
		v.erase(k);
	}
	return v[0];
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int t = 0;
	cin >> t;
	while (t--){
		cin >> n >> m;
		vector <int> v;
		for(int i = 1; i <= n; i++) v.push_back(i);
		cout << solve(v) << endl;
	}
}
