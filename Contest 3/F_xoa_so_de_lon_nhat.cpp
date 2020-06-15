#include<iostream>
#include<stack>
#include<vector>

using namespace std;
vector <int> largest;
stack <int> s;
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int n, k;
	cin >> n >> k;
	for(int i=1; i<=n; i++){
		char c;
		cin >> c;
		int num = c - 48;
		if(s.empty())
			s.push(num);
		else{
			while(k > 0 && !s.empty() && num > s.top()){
				s.pop();
				k --;
			}
			s.push(num);
		}
	}
	while(k>0 && !s.empty()){
		s.pop();
		k--;
	}
	while(!s.empty()){
		int x = s.top();
		largest.push_back(x);
		s.pop();
	}
	for(int i=largest.size()-1; i>=0; i--)
		cout << largest[i];
	return 0;
}
