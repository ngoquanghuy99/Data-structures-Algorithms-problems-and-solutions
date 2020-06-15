#include <bits/stdc++.h>
#define i64 long long
using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int n; cin >> n; int n1 = n, a[100][100];
	int dem = 1;
	cin.ignore();
	while (n1--){
		string s;
		getline(cin, s);
		string tok; vector<string> token; stringstream ss(s);
		while (getline(ss, tok, ' ')) token.push_back(tok);
		for(int i = 0; i < token.size(); i++){
			int num = atoi(token[i].c_str());
			a[num][dem] = 1;
			a[dem][num] = 1; 
		}
		dem++;
	}
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}


