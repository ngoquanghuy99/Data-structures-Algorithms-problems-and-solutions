#include <iostream>
#include <cstring>
#include <string>
#include <stack>
#include <vector>

using namespace std;
int S[300], x, top = -1;
void push(int x){
	S[++top] = x;
}
int empty(){
	return (top==-1);
}
int pop(){
	int t = S[top--];
}
int main(){
	string s;
	while (cin >> s){
		if(s == "push"){
			cin >> x;
			push(x);
		}
		else if(s == "pop"){
			if(!empty()) pop();
		}
		else{
			if(empty()) cout << "empty" << endl;
			else{
				for(int i=0; i<=top; i++) 
					cout << S[i] << " ";
				cout << endl;
			}
		}
	}
}
