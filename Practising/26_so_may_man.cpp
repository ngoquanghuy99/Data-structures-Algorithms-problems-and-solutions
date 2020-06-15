/************************************************\

	you know that i can't stop thinkin bout you
	you're the source of everything i do

\************************************************/
#include <bits/stdc++.h>
using namespace std;
int n;

void lucky_number(){
	int a = 0, b = 0;
	while (n > 0){
		if(n % 7 == 0){
			b++;
			n -= 7;
		}
		else if(n % 4 ==0){
			a++;
			n -= 4;
		}
		else{
			a++;
			n -= 4;
		}
	}
	if(n < 0){
		cout << -1 << endl;
		return;
	}
	for(int i = 0; i < a; i++) cout << 4;
	for(int i = 0; i < b; i++) cout << 7;
	cout << endl;
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t = 0; cin >> t;
	while (t--){
		cin >> n;
		lucky_number();
	}
	return 0;
}


