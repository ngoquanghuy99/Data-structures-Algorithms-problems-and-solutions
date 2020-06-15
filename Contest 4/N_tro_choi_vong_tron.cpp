#include<bits/stdc++.h>
using namespace std;
int n,m;
int kiemtra(vector <int> z){
	int t = 0,i;
	while(z.size() > 1){
		t = (t + m) % z.size();
		vector <int>:: iterator k = z.begin();
		i = 0;
		while(i++ < t){
			k++;
		}
		z.erase(k);
	}
	return z[0];
}
main(){
	int test; cin>>test;
	while(test--){
		cin>>n>>m;
		vector <int> z;
		for(int i = 1; i <= n; i++) z.push_back(i);
		int kq = kiemtra(z);
		cout<<kq<<endl;
	}
}
