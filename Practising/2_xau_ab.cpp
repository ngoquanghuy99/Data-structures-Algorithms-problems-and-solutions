#include <bits/stdc++.h>
using namespace std;
int n, k;
string s;
int OK = 0;
vector <string> v;

bool check(){
	int count1 = 0, count2 = 0;
	for(int i = 0; i < n; i++){
		count1 = 0;
		if(s[i] == 'A'){
			for(int j = i; j < i+k; j++){
				if(s[j] == 'A') count1++;
			}
			if(count1 == k) count2++;
		}
	}
	if(count2 == 1) return true;
	return false;
}

void nextgen(){
	int i = n-1;
	while (s[i] == 'B'){
		s[i] = 'A';
		i--;
	}
	if(i == -1) OK = 1;
	else s[i] = 'B';
}
void solve(){
	cin >> n >> k;
	for(int i = 0; i < n; i++)
		s += 'A';
	while (!OK){
		if(check()){
			v.push_back(s);
		}
		nextgen();
	}
	cout << v.size() << endl;
	for(int i = 0; i < v.size(); i++)
		cout << v[i] << endl;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	solve();
}
