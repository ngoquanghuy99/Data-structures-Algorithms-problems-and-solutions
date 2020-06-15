#include <iostream>
#include <queue>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int q = 0; cin >> q;
	deque <int> dQ;
	while (q--){
		string s;
		cin >> s;
		if(s == "PUSHFRONT"){
			int x; cin >> x;
			dQ.push_front(x);
		}
		if(s == "PRINTFRONT"){
			if(!dQ.empty()) cout << dQ.front() << endl;
			else cout << "NONE" << endl;
		}
		if(s == "POPFRONT"){
			if(!dQ.empty()) dQ.pop_front();
		}
		if(s == "PUSHBACK"){
			int x1; cin >> x1; dQ.push_back(x1);
		}
		if(s == "PRINTBACK"){
			if(!dQ.empty()) cout << dQ.back() << endl;
			else cout << "NONE" << endl;
		}
		if(s == "POPBACK") if(!dQ.empty()) dQ.pop_back();
	}
	return 0;
}
