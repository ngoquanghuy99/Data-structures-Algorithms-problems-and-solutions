/************************************************\
*                                               *
*	you know that i can't stop thinkin bout you *
*	you're the source of everything i do        *
*                                               *
\************************************************/
#include <bits/stdc++.h>
#define y1 youlightmyfire
#define y2 youknowthaticantstopthinkinboutyou
#define i64 long long
#define db double
#define ld long double
#define pub push_back
#define puf push_front
#define pob pop_back
#define pof pop_front
#define mmap multimap
#define mset multiset
#define umap unordered_map
#define uset unordered_set
#define ummap unordered_multimap
#define umset unordered_multiset
#define FOR(i,a,b) for(i64 i=a; i<=b; i++)
#define FORD(i,a,b) for(i64 i=a; i=>b; i--)
#define FORV(i,a) for(typeof(a.begin()) i=a.begin(); i!=a.end();i++)
#define YES cout << "YES \n";
#define NO cout << "NO \n";
#define pq priority_queue
#define mp make_pair
#define fi first
#define se second

using namespace std;
const i64 mod = 1000000007;
const long double PI = 3.14159265358979323846264338327950288419716939937510582097494459230;
typedef pair<i64,i64> pii;
typedef pair<i64, pii> pip;
typedef pair <pii, i64> ppi;
typedef vector <pii> vii;
typedef vector <pip> vip;
typedef vector <ppi> vpi;

/*
///////////////////////////////////////////////////////////////////
////////////////////////// FERMAT'S LITTLE THEOREM ////////////////
///////////////////////////////////////////////////////////////////

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

void solve(){
	int n; cin >> n;
	char a[n+1][n+1];
	for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) cin >> a[i][j];
	int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
	map <pii, int> vis, path;
	queue <pii> Q;
	Q.push({x1,y1});
	vis[{x1,y1}] = 1;
	path[{x1,y1}] = 0;
	int r[] = {-1, 0, 1, 0};
	int c[] = {0, 1, 0, -1};
	while (!Q.empty()){
		pii u = Q.front(); Q.pop();
		if(vis[{x2,y2}]) {
			cout << path[{x2,y2}];
			return;
		}
		int r1 = u.first + 1, 
		r2 = u.first - 1, 
		c1 = u.second + 1,
		c2 = u.second - 1;
		
		while (r1 < n && a[r1][u.second] == '.' && vis[{r1,u.second}] == 0){
			vis[{r1, u.second}] = 1;
			path[{r1,u.second}] = path[u] + 1;
			Q.push({r1,u.second});
			r1++;
		}
		while (r2 >= 0 && a[r2][u.second] == '.' && vis[{r2,u.second}] == 0){
			vis[{r2,u.second}] = 1;
			path[{r2,u.second}] = path[u] + 1;
			Q.push({r2, u.second});
			r2--;
		}
		while (c1 < n && a[u.first][c1] == '.' && vis[{u.first,c1}] == 0){
			vis[{u.first,c1}] = 1;
			path[{u.first,c1}] = path[u] + 1;
			Q.push({u.first, c1});
			c1++;
		}
		while (c2 >= 0 && a[u.first][c2] == '.' && vis[{u.first,c2}] == 0){
			vis[{u.first, c2}] = 1;
			path[{u.first, c2}] = path[u] + 1;
			Q.push({u.first, c2});
			c2--;
		}
	}
	cout << -1;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	solve();
}
