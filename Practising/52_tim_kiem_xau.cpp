/************************************************\
*                                               *
*	you know that i can't stop thinkin bout you *
*	you're the source of everything i do        *
*                                               *
\************************************************/
#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int t = 0;
	cin >> t;
	while (t--){
		string p, t;
		cin >> p >> t;
		if(p.find(t) != string::npos) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
}
