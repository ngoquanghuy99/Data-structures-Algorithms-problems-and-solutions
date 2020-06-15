/*
Author: Ngo Quang Huy
Problem: H - xoa dau ngoac
*/
#include <bits/stdc++.h>
#define FOR(i,a,b) for(int i = a; i <= b; i++)
#define FO(i,a,b) for(int i = a; i < b; i++)
using namespace std;

string s;
vector <long> a(20), b(20), st(20), x(20), xh(201);
long n, t, l;
string rs[2049];
long r = 0;

void update(){
	xh.assign(xh.size(), 1);
	FOR(i, 1, n)
		if (x[i] == 0){
	  		xh[a[i]] = 0;
	  		xh[b[i]] = 0;
	  	}
	r++;
	rs[r] = "";
	FOR(i,0,l-1)
		if(xh[i]) rs[r] += s[i];
}
void Try(long i){
    FOR(j, 0, 1){
		x[i] = j;
		if (i == n) update();
		else Try(i + 1);
	}
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> s;
	n = 0; t = 0; l = s.length();
    FOR(i,0,l-1)
		if (s[i] == '('){
	  		st[++t] = i;
		}
	  	else
	  	if (s[i] == ')'){
	  		a[++n] = st[t--];
	  		b[n] = i;
		}
	Try(1);
	r--;
	sort(rs + 1, rs + 1 + r);
	rs[0] = "*";
	FOR(i, 1, r)
		if (rs[i] != rs[i - 1]) cout << rs[i] << endl;
    return 0;
}

