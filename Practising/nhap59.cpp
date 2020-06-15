#include <iostream>
#include <vector>

using namespace std;
int solve(string s){
	if(s.length() < 2) return 0;
	vector<int> longest(s.size(), 0);
	int ans = 0;
	for(int i = 1; i < s.length(); i++){
		int tmp = i-longest[i-1]-1;
		if(tmp>=0 && s[tmp] =='(' && s[i] == ')'){
			longest[i] = longest[i-1]+2+(tmp-1>=0?longest[tmp-1]:0);
			ans = max(ans, longest[i]);
		}
	}
	return ans;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int t = 0; cin >> t;
	while (t--){
		string s; cin >> s; cout << solve(s) << endl;
	}
}
