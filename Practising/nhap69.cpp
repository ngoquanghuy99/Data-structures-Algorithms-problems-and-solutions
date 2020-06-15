#include <bits/stdc++.h>
using namespace std;
bool isOp(char c){
	return (c=='+'||c=='-'||c=='*'||c=='/'||c=='%'||c=='^');
}

string solve(string s){
	stack<string> st;
	for(int i = 0; i < s.length(); i++){
		if(!isOp(s[i])) st.push(string(1, s[i]));
		else{
			string o1 = st.top(); st.pop();
			string o2 = st.top(); st.pop();
			string temp =  "(" + o2 + s[i] + o1 + ")";
			st.push(temp);
		}
	}
	return st.top();
}
int main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t= 0; cin >> t; cin.ignore();
	while (t--){
		string s; getline(cin, s);
		cout << solve(s) << endl;
	}
}
