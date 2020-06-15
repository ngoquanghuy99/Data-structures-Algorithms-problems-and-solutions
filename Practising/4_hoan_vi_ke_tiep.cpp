#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int t = 0; cin >> t;
	while (t--){
		int stt; cin >> stt;
		string s; cin >> s;
		cout << stt << " ";
		if(next_permutation(s.begin(), s.end())) cout << s << endl;
		else cout << "BIGGEST" << endl;
	}
}
