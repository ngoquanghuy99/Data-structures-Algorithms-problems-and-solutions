#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstring>
#include <cstdlib>
#include <sstream>

using namespace std;
int n, dem, A[1001][1001];
int main(){
	cin >> n;
	int n1 = n;
	dem = 1;
	string s;
	getline(cin, s);
	while (n--){
		getline(cin, s);
		vector <string> tokens;
		stringstream ss(s);
		string tok;
		while (getline(ss, tok, ' '))
			tokens.push_back(tok);
		for(int i = 0; i < tokens.size(); i++){
			int num = atoi(tokens[i].c_str());
			A[dem][num] = 1;
			A[num][dem] = 1;
		}
		dem ++;
	}
	for(int i = 1; i <= n1; i++){
		for(int j = 1; j <= n1; j++){
			cout << A[i][j] << " ";
		}
		cout << endl;
	}
}
