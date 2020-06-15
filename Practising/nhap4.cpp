#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t = 0; cin >> t;
	while (t--){
		int stt; cin >> stt;
		cout << stt << " ";
		string s; cin >> s;
		if(next_permutation(s.begin(), s.end())) cout << s << endl;
		else cout << "BIGGEST" << endl;
	}
	return 0;
}


