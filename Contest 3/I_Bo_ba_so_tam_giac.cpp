/*
Author: Ngo Quang Huy
Problem: I - Bo ba so tam giac
*/
#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>
#include <queue>
#include <map>
#include <cmath>
#include <string>
#include <cstdlib>
#include <cstring>
#include <sstream>
#define i64 long long
#define pb push_back
#define FOR(i,a,b) for(i64 i=a; i<=b; i++)
#define FORD(i,a,b) for(i64 i=a; i=>b; i--)
#define pq priority_queue
#define mp make_pair;
#define fi first
#define se second

using namespace std;
const i64 mod = 1000000007;
typedef pair<int,int> ii;
/*
int fast_pow(i64 base, i64 n, i64 M){
    if(n==0)
       return 1;
    if(n==1)
    return base;
    i64 halfn=fast_pow(base,n/2,M);
    if(n%2==0)
        return ( halfn * halfn ) % M;
    else
        return ( ( ( halfn * halfn ) % M ) * base ) % M;
}
int findMMI_fermat(int n,int M){
    return fast_pow(n,M-2,M);
    // should not perform z = (x/y)%M; instead we should perform y2
    // y2 = findMMI_fermat(y,M) then z = (x*y2)%M
}
*/
bool check(vector <i64> a, i64 n){
	for(int i=n-1; i>=2; i--)
		if(a.at(i) < a.at(i-1)+a.at(i-2)) return true;
	return false;
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t = 0;
	cin >> t;
	while(t--){
		i64 n;
		cin >> n;
		vector <i64> a;
		FOR(i,0,n-1){
			i64 x; 
			cin >> x;
			a.pb(x);
		}
		sort(a.begin(), a.end());
		check(a,n);
		if(check(a,n)==true) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	return 0;
}






