/*
Author: Ngo Quang Huy
Problem: D - Bieu thuc hau to 2
*/
#include <bits/stdc++.h>
using namespace std;
int isNum(char ch){
	return (ch >= 'a' && ch <= 'z');
}
int Prec(char ch){
	switch (ch){
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
int InToPo(string s){
    stack <char> st;
    int i, j;
    for(i =0, j=0; i < s.size(); i++){
        if(isNum(s[i]))
            s[j++] = s[i];
        else if(s[i] == '(')
            st.push(s[i]);
        else if(s[i] == ')'){
            while(st.top()!= '('){
                s[j++] = st.top();
                st.pop();
            }
            st.pop();
        }
        else{
            while(!st.empty()&& Prec(s[i]) <= Prec(st.top())){
                s[j++] = st.top();
                st.pop();
            }   
            st.push(s[i]);
            
        }
    }
    while(!st.empty()){
            s[j++] = st.top();
            st.pop();
    }
    while(j!=s.size())
        s[j++] = ' ';
    cout<< s << endl;
}
int main(){
	int t = 0;
	cin >> t;
	while (t--){
		string s; cin >> s; InToPo(s);
	}
	return 0;
}

