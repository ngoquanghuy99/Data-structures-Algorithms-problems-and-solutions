/*
Author: Ngo Quang Huy
Problem: F - kiem tra day ngoac dung
*/
#include <iostream>
#include <string>
#include <cstring>
#include <stack>
#include <cstdlib>
#include <algorithm>

using namespace std;
string s;
bool check(){
		cin >> s;
		stack <char> st;
		for(int i = 0; i < s.size(); i++){
			if(s[i] == '[' || s[i] == '{' || s[i] == '(')
				st.push(s[i]);
			else{
				if(!st.empty()){
					if(s[i] == ']') 
						if(st.top() != '[')
							return false;
					if(s[i] == '}')
						if(st.top() != '{')
							return false;
					if(s[i] == ')')
						if(st.top() != '(')
							return false;
					st.pop();
				}
				else return false;
			}
		}
		return st.empty()==true;
}
int main(){
	int t = 0;
	cin >> t;
	while (t--){
		check() ? cout << "YES" << endl : cout << "NO" << endl;
	}
}
