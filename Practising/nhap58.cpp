#include <bits/stdc++.h>
using namespace std;
int isNum(char c){
	return (c >= 'a' && c <= 'z');
}
int Pre(char c){
	switch(c){
		case '+':
		case '-':
			return 1;
		case '*':
		case '/': 
			return 2;
		case '^':
			return 3;
	}
	return -1;
}

void InToPos(string s){
	stack<char> st;
	int i, j;
	for(i=0, j=0; i < s.size(); i++){
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
	while (j != s.size()) s[j++] = ' ';
	cout << s << endl;
}
int main(){
	int t = 0; cin >> t;
	while (t--){
		string s; cin >> s; InToPos(s);
	}
}
