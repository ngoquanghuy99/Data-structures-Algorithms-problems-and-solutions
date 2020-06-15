#include <iostream>
#include <string>
using namespace std;
int main(){
	int t = 0; cin >> t;
	while (t--){
		string s1, s2; cin >> s1 >> s2;
		if(s1.find(s2) != string::npos) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	return 0;
}
