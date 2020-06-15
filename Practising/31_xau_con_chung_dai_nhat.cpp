// 31 Xau con chung dai nhat

#include <iostream>
using namespace std;
int L[1100][1100];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	string s1, s2; cin >> s1 >> s2;
	int l1 = s1.length(), l2 = s2.length();
	for(int i = 0; i < l1; i++) L[i][0] = 0;
	for(int j = 0; j < l2; j++) L[0][j] = 0;
	
	for(int i = 0; i < l1; i++){
		for(int j = 0; j < l2; j++){
			L[i+1][j+1] = (s1[i+1] == s2[j+1] ? L[i][j] + 1 : max(L[i][j+1], L[i+1][j]));
		}
	}
	cout << L[l1][l2];
} 
