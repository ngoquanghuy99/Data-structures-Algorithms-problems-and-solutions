#include <bits/stdc++.h>
#define FOR(i,n) for(int i = 0; i < n; i++)
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	string a, b, a1, b1;
	cin >> a >> b; a1 = a, b1 = b;
	FOR(i,a.size()) if(a[i] == '6') a[i] = '5';
	FOR(i,b.size()) if(b[i] == '6') b[i] = '5';
	FOR(i,a1.size()) if(a1[i] == '5') a1[i] = '6';
	FOR(i,b1.size()) if(b1[i] == '5') b1[i] = '6';
	cout << atoi(a.c_str()) + atoi(b.c_str()) << " " << atoi(a1.c_str()) + atoi(b1.c_str());
}
