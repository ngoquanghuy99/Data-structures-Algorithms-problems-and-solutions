#include <iostream>
#include <sstream>
#include <vector>
#include <cstring>
#include <cstdlib>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	int n, a[55][55];
	cin >> n; int n1 = n;
	string s;
	getline(cin, s);
	int dem = 1;
	while (n--){
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
		dem++;
	}
	for(int i = 1; i <= n1; i++){
		for(int j = 1; j <= n1; j++){
			if(i < j && a[i][j]) cout << i << " " << j << endl;
		}
	}
}
