#include <bits/stdc++.h>
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
stack<int> st;
vector<int> canh_cau;
map<pair<int,int>,int> thu_tu;
int n,m,parent[1001],low[1001],number[1001],num=1,a[1001][1001];
void DFS(int top)
{
	st.push(top);
	parent[top]=-1;
	number[top]=num++;
	while(!st.empty())
	{
		int dinh=st.top(),check=1;
		st.pop();
		for(int i=1;i<=n;i++)
		{
			if(a[dinh][i])
			{
			  a[i][dinh]=a[dinh][i]=0;
			  if(parent[i]==0)
			  {
			    st.push(dinh);
				st.push(i);
				parent[i]=dinh;
				number[i]=num++;
				check=0;
				break;
			  }
			  else low[dinh]=min(low[dinh],number[i]);
			}
		}
		if(check&&!st.empty())low[st.top()]=min(low[st.top()],low[dinh]);
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--)
    {
    	cin>>n>>m;
    	num=1;
    	thu_tu.clear();
    	canh_cau.clear();
    	for(int i=1;i<=n;i++)
		{
			parent[i]=0;
			low[i]=n+1;
			number[i]=1;
		}
		for(int i=1;i<=n;i++)
		 for(int j=1;j<=n;j++)
		    a[i][j]=0;
    	for(int i=1;i<=m;i++)
    	{
    		int x,y;
    		cin>>x>>y;
    		a[x][y]=a[y][x]=1;
    		thu_tu[make_pair(x,y)]=thu_tu[make_pair(y,x)]=i;
		}
		for(int i=1;i<=n;i++)
		 if(parent[i]==0)DFS(i);
		for(int i=1;i<=n;i++)
		 if(parent[i]!=-1&&low[i]>=number[i])
		  canh_cau.push_back(thu_tu[make_pair(parent[i],i)]);
		sort(canh_cau.begin(),canh_cau.end());
		cout<<canh_cau.size()<<endl;
		for(int i=0;i<canh_cau.size();i++)
		 cout<<canh_cau[i]<<" ";
		cout<<endl;
    }
	return 0;
}
