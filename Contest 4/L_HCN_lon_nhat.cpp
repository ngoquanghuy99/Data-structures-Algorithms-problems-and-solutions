#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> iPair;
typedef vector<int> iVector;
typedef vector<iVector> iMatrix;
#define MOD 1000000007
#define INF 1e18
#define long long long
#define endl ('\n')
#define fill(ar,val) memset(ar,val,sizeof(ar))
#define fastIO ios::sync_with_stdio(false); cin.tie(0)

class SegmentTree
{
	int n;
	vector<long> vec, tree;

	int getMin(int s, int e)
	{
		if(s==-1)
			return e;
		if(e==-1)
			return s;
		return (vec[s] < vec[e] ? s : e);
	}

	void build(int s, int e, int node)
	{
		if(s==e)
			tree[node] = s;
		else
		{
			int m = s + (e-s>>1);
			build(s,m,node<<1);
			build(m+1,e,node<<1|1);
			tree[node] = getMin(tree[node<<1],tree[node<<1|1]);
		}
	}

	long RMQ(int s, int e, int l, int r, int node)
	{
		if(s>e || s>r || e<l)
			return -1;
		if(s>=l && e<=r)
			return tree[node];
		else
		{
			int m = s + (e-s>>1);
			long lQuery = RMQ(s,m,l,r,node<<1);
			long rQuery = RMQ(m+1,e,l,r,node<<1|1);
			return getMin(lQuery,rQuery);
		}
	}

	long query(int s, int e)
	{
		if(s>e)
			return -INF;
		if(s==e)
			return vec[s];

		int m = RMQ(0,n-1,s,e,1);
		long lQuery = query(s,m-1);
		long rQuery = query(m+1,e);
		return max({lQuery, rQuery, (e-s+1) * vec[m]});
	}


public:
	SegmentTree(const vector<long> &v)
	{
		this->vec = v;
		this->n = v.size();
		tree.resize(n<<2);
		build(0,n-1,1);
	}

	long query()
	{
		return query(0,n-1);
	}
};

int main()
{
	fastIO;
	int t = 0;
	cin >> t;
	while(t--)
	{
		int n; cin >> n;
		if(n==0)
			break;
		vector<long> h(n);
		for(int i=0;i<n;i++)
			cin >> h[i];
		SegmentTree st(h);
		cout << st.query() << endl;
	}
	return 0;
}

