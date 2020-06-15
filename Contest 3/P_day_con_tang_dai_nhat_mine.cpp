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
#define FOR(i,a,n) for(i64 i=a; i<n; i++)
#define pq priority_queue 

const i64 mod = 1000000007;

using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	i64 n = 0, f[1001], a[1001];
	i64 max_ans = 0;
	cin >> n;
	FOR(i,0,n){
		cin >> a[i];
		f[i] = 1;
		FOR(j,0,i){
			if(a[i] > a[j] && f[j]+1>f[i])
				f[i] = f[j] + 1;
		}
		if(f[i] > max_ans) max_ans = f[i];
	}
	cout << max_ans;
	return 0;
}


