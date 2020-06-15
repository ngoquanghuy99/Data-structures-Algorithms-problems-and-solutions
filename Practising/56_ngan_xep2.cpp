#include <iostream>
#include <stack>
using namespace std;


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int Q; cin >> Q;
	stack <int> st;
	while (Q--){
		string s;
		cin >> s;
		if(s == "PUSH"){
			int x; cin >> x; 
			st.push(x);
		}
		if(s == "PRINT"){
			if(!st.empty()) cout << st.top() << endl;
			else cout << "NONE" << endl;
		}
		if(s == "POP"){
			if(!st.empty()) st.pop();
		}
	}
	return 0;
}
