#include <iostream>
#include <map>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	string temp;
	map <string, int> hash;
	while (cin >> temp)
		hash[temp]++;
	cout << hash.size() << endl;
	for(auto i : hash) cout << i.first << " " << i.second << endl;
	return 0;
}
