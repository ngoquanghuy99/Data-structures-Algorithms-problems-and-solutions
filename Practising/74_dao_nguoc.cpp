#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	string s;
//	cin.ignore();
	fflush(stdin);
	getline(cin, s);
	stack <char> st;
	for(int i = 0; i < s.size(); i++){
		if(s[i] != ' ') st.push(s[i]);
		else{
			while (!st.empty()){
				cout << st.top();
				st.pop();
			}
			cout << " ";
		}
	}
	while (!st.empty()){
		cout << st.top();
		st.pop();
	}
	return 0;
}
