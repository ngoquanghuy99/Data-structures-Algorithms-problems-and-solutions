/*
Author: Ngo Quang Huy
Problem: H - xoa dau ngoac
*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>
#include <cstdio>
#include <stack>

#define base 1000000007
#define N (int)1e5+7
#define ll long long
#define ull unsigned long long
#define db double
#define ld long double
#define FOR(i, a, b) for(int i = a; i <= b; i++)
#define FO(i, a, b) for(int i = a; i < b; i++)
#define FORD(i, a, b) for(int i = a; i >= b; i--)
#define FORV(i, a) for(typeof(a.begin()) i = a.begin(); i != a.end(); i++)
#define YES cout<<"YES\n";
#define NO cout<<"NO\n";
#define yes cout<<"yes\n";
#define no cout<<"no\n";
#define Yes cout<<"Yes\n";
#define No cout<<"No\n";
#define PI 3.1415926535897
#define lamtron(n) fixed<<setprecision(n)
#define ALL(s) s.begin(),s.end()
#define NUMBER "0123456789"
#define uALPHA "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
#define lALPHA "abcdefghijklmnopqrstuvwxyz"
#define uWb "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ"
#define lWb "0123456789abcdefghijklmnopqrstuvwxyz"


using namespace std;

string s;
vector <long> a(20), b(20), st(20), x(20), xh(201);
long n, t, l;
string rs[2049];
long r = 0;

void update(){
	FO(i, 0, l)
    	xh[i] = 1;
	FOR(i, 1, n)
		if (x[i] == 0){
	  		xh[a[i]] = 0;
	  		xh[b[i]] = 0;
	  	}
	r++;
	rs[r] = "";
	FO(i, 0, l)
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
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
	cin >> s;
	n = 0;
	t = 0;
	l = s.length();
    FO(i, 0, l)
		if (s[i] == '('){
	  		t++;
	  		st[t] = i;
		}
	  	else
	  	if (s[i] == ')'){
	  		n++;
	  		a[n] = st[t];
	  		b[n] = i;
	  		t--;
		}
	Try(1);
	r--;
	sort(rs + 1, rs + 1 + r);
	rs[0] = "*";
	FOR(i, 1, r)
		if (rs[i] != rs[i - 1]) cout << rs[i] << endl;
    return 0;
}

