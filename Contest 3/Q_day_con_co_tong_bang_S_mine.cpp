/*
Author: Ngo Quang Huy
Problem:
*/
#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>
#include <queue>
#include <cmath>
#include <string>
#include <cstdlib>
#include <cstring>
#include <sstream>
#define i64 long long
#define pb push_back
#define FOR(i,a,b) for(i64 i= a; i<= b; ++i)
#define FORR(i,a,b) for(i64 i= a; i>= b; --i)
#define pq priority_queue
#define fi first
#define se second

using namespace std;
const i64 mod = 1000000007;
typedef pair<int,int> ii;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	i64 n, s, a[201], L[201];
	cin >> n >> s;
	L[0] = 1;
	FOR(i,1,n)	cin >> a[i];
	FOR(i,1,n)
		FOR(t,s,a[i])
			if(L[t-a[i]]==1) 
				L[t] = 1;
	if(L[s]) cout << "YES";
	else cout << "NO";
	return 0;
}




