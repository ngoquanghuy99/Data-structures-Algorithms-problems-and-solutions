/*
Name: Ngo Quang Huy
Problem: C - Bieu thuc hau to 1
*/
#include <iostream>
#include <stack>
#include <vector>
#define F(i,a,b) for(int i = a; i <= b; i++)

using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int n = 0;
	cin >> n;
	while (n--){
		string s;
		cin >> s;
		stack <char> st;
		F(i,0,s.size()-1){
			if(s[i] == '(') st.push(s[i]);
			else if(s[i] >= 'a' && s[i] <= 'z') cout << s[i];
			else if(s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/'){
				while( !st.empty() && (st.top() == '*' || st.top() == '/')){
					cout << st.top();
					st.pop();
				}
				st.push(s[i]);
			}
			else if(s[i] == ')'){
				while (st.top() != '('){
					cout << st.top();
					st.pop();
				}
				st.pop();
			}
		}
		cout << endl;
	}
	return 0;
}



// this is distributed by Ngo Quang Huy
