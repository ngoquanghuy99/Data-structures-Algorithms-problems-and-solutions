#include <bits/stdc++.h>
using namespace std;

string s; int n;

void Input() {
	cin >> s;
	n = s.size();
}

void Solve() {
	int ans = 0;
	for (int i=0; i<n; i++) {
		int L = i, R = i, Len = 1;
		while (L-1 >= 0 && R+1 < n && s[L-1] == s[R+1]) {Len += 2; L--; R++;}
		ans = max(ans, Len);
	}
	for (int i=1; i<n; i++) {
		if (s[i-1] != s[i]) continue;
		int L = i-1, R = i, Len = 2;
		while (L-1 >= 0 && R+1 < n && s[L-1] == s[R+1]) {Len += 2; L--; R++;}
		ans = max(ans, Len);
	}
	cout << ans << endl;
}

int main(int argc, char* argv[]) {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	int T; cin >> T; while (T--) {Input(); Solve();} return 0;
}


