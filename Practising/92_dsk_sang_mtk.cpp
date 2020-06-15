#include <iostream>
#include <sstream>
#include <vector>
#include <cstring>
#include <string>
#include <cstdlib>

using namespace std;
int a[1005][1005];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n; cin >> n;
	string s;
	getline(cin, s);
	int n1 = n;
	int dem = 1;
	while (n1--){
		getline(cin, s);
		stringstream ss(s);
		string tok;
		vector <string> tokens;
		while (getline(ss, tok, ' ')) tokens.push_back(tok);
		for(int i = 0; i < tokens.size(); i++){
			int num = atoi(tokens[i].c_str());
			a[dem][num] = 1;
			a[num][dem] = 1;
		}
		dem ++;
	}
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++)
			cout << a[i][j] << " ";
		cout << endl;
	}
}
