#include <iostream>
#include <string> 
#include <vector>
using namespace std; 

int solve(string s) { 
	if (s.length() <= 1) return 0; 
	int curMax = 0; 
	vector<int> longest(s.size(), 0); 
	for (int i = 1; i < s.length(); i++){ 
		auto temp = i-longest[i-1]-1;
		if (temp >= 0 && s[temp] == '(' && s[i] == ')'){ 
				longest[i] = longest[i - 1] + 2 + 
				((temp-1 >= 0) ? longest[temp-1] : 0); 
					curMax = max(longest[i], curMax); 
		} 
	} 
	return curMax; 
} 

int main() { 
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int t = 0;
	cin >> t;
	while (t--){
		string s;
		cin >> s;
		cout << solve(s) << endl;
	}
	return 0; 
} 


