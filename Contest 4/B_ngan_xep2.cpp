/*
Author: Ngo Quang Huy
Problem: B - Ngan xep 2
*/
#include <iostream>
#include <stack>
using namespace std;
int main(){
	int q = 0;
	cin >> q;
	stack <int> st;
	while (q--){
		string s;
		cin >> s;
		if(s == "PUSH"){
			int x;
			cin >> x;
			st.push(x);
		}
		if(s == "PRINT"){
			if(st.empty()) cout << "NONE" << endl;
			else cout << st.top() << endl;
		}
		if(s == "POP"){
			if(!st.empty())
				st.pop();
		}
	}
	return 0;
}
