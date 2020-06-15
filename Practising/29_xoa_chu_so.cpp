#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n, k; cin >> n >> k;
	stack <int> s;
	for(int i = 1; i <= n; i++){
		char c; cin >> c;
		int num = c - '0';
		if(s.empty()) s.push(num);
		else{
			while (k > 0 && !s.empty() && num > s.top()){
				s.pop(); k--;
			}
			s.push(num);
		}
	}
	while (k > 0 && !s.empty()){
		k--;
		s.pop();
	}
	vector <int> ans;
	while (!s.empty()){
		int temp = s.top();
		ans.push_back(temp);
		s.pop();
	}
	for(int i = ans.size() - 1; i >= 0; i--) cout << ans[i];
}
