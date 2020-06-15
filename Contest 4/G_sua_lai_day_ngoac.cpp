/*
Author: Ngo Quang Huy
Problem: G - Sua lai day ngoac
*/
#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>
using namespace std;
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t = 0;
	cin >> t;
	while (t--){
		int count = 0;
		string s;
		cin >> s;
		stack <char> st;
		for(int i = 0; i < s.size(); i++){
			if(s[i] == '(') st.push(s[i]);
			else{
				if(st.empty() || st.top() == ')') st.push(s[i]);
				else if(st.top() == '(')
					st.pop();
			}
		}
//		vector <char> v;
//		while (!st.empty()){
//			v.push_back(st.top());
//			st.pop();
//		}
//		for(vector<char>::reverse_iterator rt=v.rbegin(); rt!=v.rend(); rt++)
//			cout << *rt;
//		cout << endl;
		while (!st.empty()){
			char fi = st.top();
			st.pop();
			char se = st.top();
			fi==se ? count++ : (count += 2);
			st.pop();
		}
		cout << count << endl;
	}
	return 0;
}








