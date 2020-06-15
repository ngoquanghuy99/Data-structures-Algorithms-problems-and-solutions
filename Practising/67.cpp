#include <iostream>
#include <stack>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int t = 0; cin >> t;
	while (t--){
		string s; cin >> s;
		stack <int> st;
		int stt = 0;
		for(int i = 0; i < s.size(); i++){
			if(s[i] == '('){
				cout << ++stt << " ";
				st.push(stt);
			}
			else if(s[i] == ')'){
				cout << st.top() << " ";
				st.pop();
			}
		}
		cout << endl;
	}
}
