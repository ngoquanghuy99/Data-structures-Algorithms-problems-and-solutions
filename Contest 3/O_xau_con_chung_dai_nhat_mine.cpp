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
#define FOR(i,a,b) for(i64 i=a; i<b; i++)
#define pq priority_queue

const i64 mod = 1000000007;
int L[1001][1001];
using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	string c1, c2;
	cin >> c1 >> c2;
	int l1 = c1.length();
	int l2 = c2.length();
	FOR(i,0,l1) L[i][0] = 0;
	FOR(j,0,l2) L[0][j] = 0;
	FOR(i,0,l1){
		FOR(j,0,l2){
			if(c1[i+1]==c2[j+1])
				L[i+1][j+1] = L[i][j] + 1;
			else L[i+1][j+1] = max(L[i][j+1], L[i+1][j]);
		}
	}
	cout << L[l1][l2];
	return 0;
}



