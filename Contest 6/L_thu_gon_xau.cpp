/*
Author: Ngo Quang Huy
Problem: L - Thu gon xau
*/
#include <iostream>
#include <stack>
#include <queue>
#include <vector> 
#include <string>
#include <cstring>
#include <cstdlib>

using namespace std;
vector <char> v;
int main(){
	string str;
	stack <char> s;
	cin >> str;
	for(int i = 0; i < str.size(); i++){
		if(s.empty()) s.push(str[i]);
		else{
			if (!s.empty() && str[i] == s.top())
				s.pop();
			else if(!s.empty() && str[i] != s.top())
				s.push(str[i]);
		}
	}
	if(s.empty()) cout << "Empty String" << endl;
	else{
		while (!s.empty()){
			char c = s.top();
			v.push_back(c);
			s.pop();
		}
		for(vector<char>::reverse_iterator rit = v.rbegin(); rit != v.rend(); rit++){
			cout << *rit;
		}
	}
	
}
