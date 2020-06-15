#include <iostream>
#include <stack>

using namespace std;
string s;

bool check(){
	stack <char> st;
	for(int i = 0; i < s.size(); i++){
		if(s[i] == '[' || s[i] == '{' || s[i] == '(') st.push(s[i]);
		else{
			if(!st.empty()){
				if(s[i] == ']')  if(st.top() != '[') return false;
				if(s[i] == ')') if(st.top() != '(') return false;
				if(s[i] == '}') if(st.top() != '{') return false;
				st.pop();
			}
			else return false;
		}
	}
	return st.empty() == true;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int t = 0; cin >> t;
	while (t--){
		cin >> s;
		cout << (check() ? "YES" : "NO") << endl;
	}
}
