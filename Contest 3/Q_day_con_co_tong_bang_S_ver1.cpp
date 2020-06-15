#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <string>
#include <math.h>
#define FOR(i,a,b) for(int i= a; i<= b; ++i)
#define FORD(i,a,b) for(int i= a; i>= b; --i)
#define pb push_back
#define fi first
#define se second
using namespace std;
const long long base=1e9+7;
const int MAX=1e6 + 9;
typedef pair<int, int> ii;
typedef long long ll;
int getBit(int sky, int i) {return (sky >> (i-1)) & 1;}
int onBit(int sky, int i) { return sky | (1 << (i-1));}
int n, s, a[209],f[400009];
 
int main() {
	cin >> n >> s;
	FOR(i,1,n) cin >> a[i];
	f[0] = 1;
	for( int i = 1; i < n; i++ ) {
		for( int j = s; j >= a[i]; j-- ) {
			if( f[j-a[i]] == 1 ) f[j] = 1;
		} 
	}
	if( f[s] ) cout << "YES";
	else cout << "NO";
	return 0;
}
