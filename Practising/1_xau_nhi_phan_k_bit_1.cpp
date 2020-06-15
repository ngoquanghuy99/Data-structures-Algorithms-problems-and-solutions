#include <bits/stdc++.h>
using namespace std;
int n, k, t, OK;
int a[110];
//bool isFinal(){
//	for(int i = 1; i <= n; i++) 
//		if(a[i] == 0) return false;
//	return true;
//}
void nextgen(){
	int i = n;
	while(a[i] == 1){
		a[i] = 0;
		i--;
	}
	if(i == 0) OK = 1;
	else a[i] = 1;
}
bool check(){
	int sum = 0;
	for(int i = 1; i <= n; i++) sum += a[i];
	return sum == k ? true : false; 
}
void display(){
	for(int i = 1; i <= n; i++) cout << a[i];
	cout << endl;
}
void solve(){
	cin >> t; 
	while (t--){
		cin >> n >> k; memset(a, 0, sizeof a);
		OK = 0;
		while(!OK){
			if(check()) display();
			nextgen();
		}
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	solve();
}
