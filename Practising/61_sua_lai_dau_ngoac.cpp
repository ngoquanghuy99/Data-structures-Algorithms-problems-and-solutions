#include <iostream>
#include <stack>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int t = 0; cin >> t;
	while (t--){
		string s; cin >> s;
		stack <char> st;
		for(int i = 0; i < s.size(); i++){
			if(s[i] == '(') st.push(s[i]);
			else{
				if(st.empty() || st.top() == ')') st.push(s[i]);
				else if(st.top() == '(') st.pop();
			}
		}
		int dem = 0;
		while (!st.empty()){
			char f = st.top(); st.pop();
			char s = st.top();
			f == s ? dem++ : (dem += 2);
			st.pop();
		}
		cout << dem << endl;
	}
}
