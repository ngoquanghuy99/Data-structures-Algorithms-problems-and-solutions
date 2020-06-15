#include <bits/stdc++.h>
using namespace std;
int n, k, a[110];
int OK = 0;
bool check(){int s=0; for(int i=1;i<=n;i++) s+=a[i]; if(s==k) return true; return false;}
void nextgen(){	int i = n; while(a[i]==1){a[i]=0;i--; }if(i==0) OK=1; else a[i]=1;}
void print(){for(int i=1;i<=n;i++) cout << a[i]; cout << endl;}
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t = 0; cin >> t;
	while (t--){
		cin >> n >> k; memset(a, 0, sizeof a);
		while (!OK){
			if(check()) print();
			nextgen();
		}
		OK = 0;
	}
	return 0;
}


