#include <bits/stdc++.h>
#define i64 long long
using namespace std;
i64 n;

void lucky_number(){
	i64 a = 0, b = 0;
	while (n > 0){
		if(n % 7 ==0){
			b++;
			n -= 7;
		}
		else if(n % 4 == 0){
			a++;
			n -= 4;
		}
		else{
			a++;
			n -= 4;
		}
	}
	if(n < 0){
		cout << -1 << endl; return;
	}
	for(int i = 0; i < a; i++) cout << 4;
	for(int i = 0; i < b; i++) cout << 7;
	cout << endl;
}
int main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t = 0; cin >> t;
	while (t--){
		cin >> n;
		lucky_number();
	}
}
