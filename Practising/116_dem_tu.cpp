#include <bits/stdc++.h>
#define i64 long long
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	string s;
	map <string, i64> hash; 
	while (cin >> s) hash[s]++;
	cout << hash.size() << endl;
	for(auto i : hash cout << i.first << " " << i.second << endl;
	return 0;
}
