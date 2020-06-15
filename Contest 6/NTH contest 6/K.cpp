#pragma GCC optimize("Ofast")

#include<bits/stdc++.h>

using namespace std;

#define forn(i,n) for(i=0;i<n;++i)
#define for1(i,n) for(i=1;i<=n;++i)
#define eb emplace_back
#define all(x) (x).begin(),(x).end()
#define fill(x,b) memset((x),b,sizeof((x)))
#define fill2D(x,r,c,b) memset((x),b, sizeof(x[0][0]) * r * c)
#define whatIs(a) cout<<#a<<" is : "<<a<<endl

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vi> vvi;
typedef vector<vll> vvll;
typedef vector<string> vs;
typedef vector<vs> vvs;

const int mod = 1e9 + 7;
clock_t t1,t2;

ll binPow(ll a, ll b){ll x = 1, y = a;while (b){if (b & 1)x = (x * y) % mod;y = (y*y) % mod;b >>= 1;}return x % mod;}

ll inverserEuler(int n){return binPow(n, mod-2);}

ll C(int k, int n){vll f(n+1,1);for(int i = 2;i<=n;i++)f[i] = (f[i-1]*i)%mod;return (f[n] * ((inverserEuler(f[k]) * inverserEuler(f[n-k]))%mod)%mod)%mod;}

/* Extend Euclid: ax + by = c;
ll x, y;
 
void extendEuclid(ll a, ll b){if(b == 0){x = 1;y = 0;return;}extendEuclid(b,a%b);ll x1 = y, y1 = x - (a/b) * y;x = x1;y = y1;}
// nghiem : x + (b/d)*k, y - (a/d) * k;
*/
/*--------------------------------------------------------------------------------------------------*/

void trunghieu()
{
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		cin>>s;
		int N = s.size();
		N = 2*N + 1;
		int L[N];
		L[0] = 0; 
		L[1] = 1; 
		int C = 1;
		int R = 2; 
		int i = 0;
		int iMirror; 
		int maxLPSLength = 0; 
		int maxLPSCenterPosition = 0; 
		int start = -1; 
		int end = -1; 
		int diff = -1; 

		for (i = 2; i < N; i++)  
		{ 

			iMirror  = 2*C-i; 
			L[i] = 0; 
			diff = R - i; 

			if(diff > 0) 
				L[i] = min(L[iMirror], diff); 
			while ( ((i + L[i]) < N && (i - L[i]) > 0) &&  
				( ((i + L[i] + 1) % 2 == 0) ||  
					(s[(i + L[i] + 1)/2] == s[(i - L[i] - 1)/2] ))) 
						L[i]++;

			if(L[i] > maxLPSLength)
			{ 
				maxLPSLength = L[i]; 
				maxLPSCenterPosition = i; 
			} 
			if (i + L[i] > R)  
			{ 
				C = i; 
				R = i + L[i]; 
			} 
		} 
		cout<<maxLPSLength<<endl;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie();
	trunghieu();
	return 0;
}