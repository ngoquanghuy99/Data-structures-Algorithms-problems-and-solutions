// 58 bieu thuc hau to 2
#include <bits/stdc++.h>
using namespace std;

int isNum(char ch){
	return (ch >= 'a' && ch <= 'z');
}

int Pre(char ch){
	switch(ch){
		case '+':
		case '-': return 1;
		case '*':
		case '/': return 2;
		case '^': return 3;
	}
	return -1;
}

void solve(string s){
	int i = 0, j = 0;
	stack<char> st;
	for(i = 0, j = 0; i < s.size(); i++){
		if(isNum(s[i])) s[j++] = s[i];
		else if(s[i] == '(') st.push(s[i]);
		else if(s[i] == ')'){
			while (st.top() != '('){
				s[j++] = st.top();
				st.pop();
			}
			st.pop();
		}
		else{
			while (!st.empty() && Pre(s[i]) <= Pre(st.top())){
				s[j++] = st.top();
				st.pop();
			}
			st.push(s[i]);
		}
	}
	while (!st.empty()){
		s[j++] = st.top();
		st.pop();
	}
	while (j != s.size()){
		s[j++] = ' ';
	}
	cout << s << endl;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int t = 0; cin >> t;
	while (t--){
		string s; cin >> s; solve(s);
	}
	return 0;
}
