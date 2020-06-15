#include <iostream>
#include <vector>
#include <algorithm>
#define FOR(i,a,b) for(int i = a; i <= b; i++)
#define mp make_pair
#define pub push_back
#define fi first
#define se second
using namespace std;
int n, k, a[1000001], b[1000001];
typedef pair<int, int> pii;
typedef pair<pii, int> ppi;
typedef vector <pii> vii;
typedef vector <ppi> vpi;
vpi v;
bool unused[100001];
int main(){
	cin >> n >> k;
	FOR(i,0,n-1) cin >> a[i];
	FOR(i,0,n-1) cin >> b[i];
	FOR(i,0,n-1) v.pub(mp(mp(a[i]-b[i], a[i]), b[i]));
	sort(v.begin(), v.end());
	int sum = 0;
	for(int i = 0; i < k; i++)
		sum += v[i].fi.se;
	for(int i = k; i < n; i++)
		sum += v[i].se;
	cout << sum;
	return 0;
}
