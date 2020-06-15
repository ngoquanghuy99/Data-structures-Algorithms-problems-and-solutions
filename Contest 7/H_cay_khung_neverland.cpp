#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>
#include <queue>
#include <deque>
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

class UnionFind{
private:
	vector<int> p, rank;
public:
	UnionFind(int n)
	{
		rank.assign(n + 1,0);
		p.assign(n + 1,0);
		for(int i = 1;i<=n;i++)
			p[i] = i;
	}
	int findSet(int i)
	{
		return (p[i] == i) ? i : (p[i] = findSet(p[i]));
	}
	int unionSet(int i,int j)
	{
		int x = findSet(i), y = findSet(j);
		if(x == y)
			return 0;
		if(rank[x] == rank[y])
			rank[x]++;
		if(rank[x] < rank[y])
			p[x] = y;
		else p[y] = x;
		return 1;
	}
};

typedef struct Edge 
{
	int u, v,w;
} Edge;

bool operator < (const Edge &a, const Edge &b){
	return a.w < b.w;
}

void solve(){
	int t;
	cin>>t;
	while(t--){
		int v,e;
		cin>>v>>e;
		vector<Edge> edge(e);
		int i,j;
		UnionFind UF(v);
		long long ans = 0;
		for(i =0;i<e;i++)
			cin>>edge[i].u>>edge[i].v>>edge[i].w;
		sort(edge.begin(), edge.begin() + i);
		for(auto x:edge)
			if(UF.unionSet(x.u, x.v))
				ans+= x.w;
		cout<<ans<<endl;
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie();
	solve();
	return 0;
}

