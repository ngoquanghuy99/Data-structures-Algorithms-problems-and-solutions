#include <iostream>
#include <queue>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int q = 0; cin >> q;
	queue <int> Q;
	while (q--){
		string s;
		cin >> s;
		if(s == "PUSH"){
			int x; cin >> x;
			Q.push(x);
		}
		if(s == "PRINTFRONT"){
			if(!Q.empty()) cout << Q.front() << endl;
			else cout << "NONE" << endl;
		}
		if(s == "POP") if(!Q.empty()) Q.pop();
	}
	return 0;
}
