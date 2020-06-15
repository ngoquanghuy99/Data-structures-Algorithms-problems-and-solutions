#include <bits/stdc++.h>
using namespace std;
int n, k;
int OK = 0;
string s;
vector<string> vs;
bool check(){
	int dem1 = 0, dem2 = 0;
	for(int i = 0; i < n; i++){
		dem1 = 0;
		if(s[i] == 'A'){
			for(int j = i; j < i+k; j++){
				if(s[j] == 'A') dem1++;
			}
			if(dem1 == k) dem2++;
		}
	}
	if(dem2 == 1) return true; return false;
}
void nextgen(){int i=n-1;while(s[i]=='B'){s[i]='A';i--;} if(i==-1) OK=1; else s[i]='B';}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n >> k;
	for(int i = 0; i < n; i++) s+='A';
	while(!OK){
		if(check()) vs.push_back(s);
		nextgen();
	}
	cout << vs.size() << endl; for(int i = 0; i < vs.size(); i++) cout << vs[i] << endl;
	return 0;
}


