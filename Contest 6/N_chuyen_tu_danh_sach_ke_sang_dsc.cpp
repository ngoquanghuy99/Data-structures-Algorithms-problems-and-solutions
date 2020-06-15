/*
Author: Ngo Quang Huy
Problem N: Chuyen tu danh sach ke sang danh sach canh
Tips: Using stringstream to convert adjacency list to adjacency matrix and ...
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <cstring>
#include <string>
#include <cstdlib>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n, A[52][52];
	cin >> n;
	int n1 = n;
	string s;
	getline(cin, s);
	int dem = 1;
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
		dem++;
	}
	for(int i = 1; i <= n1; i++){
		for(int j = 1; j <= n1; j++){
			if(i < j && A[i][j] == 1){
				cout << i << " " << j;
				cout << endl;
			}
		}
	}
}
