
#include <iostream> 
#include <stack> 
using namespace std; 


bool check(string &str){ 
	stack <char> st; 
	for (auto &i : str){ 
		if(i == ')'){ 
			char top = st.top(); 
			st.pop(); 
			bool res = true; 

			while (top != '(') { 
				if (top == '+' || top == '-' || top == '*' || top == '/' || top == ' ') 
					res = false; 
				top = st.top(); 
				st.pop(); 
			} 
			if (res == true) 
				return true; 
		} 

		else
			st.push(i); 
	} 
	return false; 
} 
int main() { 
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t = 0; cin >> t; cin.ignore();
//	getline(cin, s);
	while (t--){
		string s;
	//	fflush(stdin);
		getline(cin, s);
		cout << (check(s) ? "Yes" : "No") << endl;
	}
	return 0; 
} 

