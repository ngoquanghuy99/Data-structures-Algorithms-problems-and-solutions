#include <bits/stdc++.h>
using namespace std;

bool isOp(char c){
	return (c=='+'||c=='-'||c=='*'||c=='/'||c=='^'||c=='%');
}

string pretopost(string s){
	stack<string> st;
	for(int i = s.length() - 1; i >= 0; i--){
		if(!isOp(s[i])) st.push(string(1, s[i]));
		else{
			string o1 = st.top(); st.pop();
			string o2 = st.top(); st.pop();
			string temp = o1 + o2 + s[i];
			st.push(temp);
		}
	}
	return st.top();
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int t = 0; cin >> t; cin.ignore();
	while (t--){
		string s; getline(cin, s);
		cout << pretopost(s) << endl;
	}
	return 0;
}
