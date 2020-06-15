/*
Author: Ngo Quang Huy
Problem: L - sao xeo doi cho truc tiep
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
#define db double
#define ld long double
#define pub push_back
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
#define mp make_pair;
#define fi first
#define se second

using namespace std;
const i64 mod = 1000000007;
const long double PI = 3.14159265358979323846264338327950288419716939937510582097494459230;
typedef pair<i64,i64> pii;
typedef pair<i64, pii> pip;
typedef pair <pii, i64> ppi;


/*
///////////////////////////////////////////////////////////////////
////////////////////////// fermat's little theorem ////////////////
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
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int n, a[101];
	cin >> n;
	for(int i = 0; i < n; i++) cin >> a[i];
	int dem, dem1;
	dem = dem1 = 0;
	for(int i=0; i < n-1; i++){
		for(int j = i+1; j < n; j++){
			if(a[i] > a[j]){
				swap(a[i], a[j]);
				dem ++;
			//	if(dem%2==0){
					
				//}
			}
		}
		cout << "Buoc " << ++dem1 <<": ";
					for(int i = 0; i < n; i++)
						cout << a[i] << " ";
					cout << endl;
	}
	//cout << "Buoc " << ++dem1 << ": ";
	//for(int i = 0; i < n; i++) cout << a[i] << " ";
	return 0;
}











