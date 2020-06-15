#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int n; cin >> n; string s[n+1];
	for(int i = 0; i < n; i++) cin >> s[i];
	sort(s, s+n); int ans = 1100;
	do{
		int dem = 0;
		for(int i = 0; i < n-1; i++)
			for(int j = 0; j < s[i].length(); j++)
				if(s[i+1].find(s[i][j]) != string::npos) dem++;
		ans = min(ans, dem);
	} while (next_permutation(s, s+n));
	cout << ans << endl;
	return 0;
}


