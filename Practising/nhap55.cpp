#include <iostream>
using namespace std;
int stack[250], top;

void push(int x){
	stack[++top] = x;
}
int empty(){
	return top == 0;
}
int pop(){
	int t = stack[top--];
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	string s;
	while (cin >> s){
		if(s == "push"){
			int x; cin >> x;
			push(x);
		}
		if(s == "pop") if(!empty()) pop();
		if(s == "show"){
			if(!empty()){
				for(int i = 1; i <= top; i++) cout << stack[i] << " ";
				cout << endl;
			}
			else cout << "empty" << endl;
		}
	}
}
