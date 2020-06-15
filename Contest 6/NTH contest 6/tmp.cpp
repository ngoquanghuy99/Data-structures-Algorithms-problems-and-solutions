#pragma GCC optimize("Ofast")

#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

#define forn(i,n) for(i=0;i<n;++i)
#define for1(i,n) for(i=1;i<=n;++i)
#define eb emplace_back
#define all(x) (x).begin(),(x).end()
#define fill(x,b) memset((x),b,sizeof((x)))
#define fill2D(x,r,c,b) memset((x),b, sizeof(x[0][0]) * r * c)
#define whatIs(a) cout<<#a<<" is : "<<a<<endl
#define endl '\n'

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vi> vvi;
typedef vector<vll> vvll;
typedef vector<string> vs;
typedef vector<vs> vvs;
typedef vector<char> vc;
typedef vector<vc> vvc;

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

const int maxn = 9;

vector<string> a(maxn);

int n, cnt = 0;

bool check(vs a)
{
	int i,j, cntA = 0, cntB = 0, cntC = 0;
	forn(i,n)
	{
		forn(j,n)
        {
            if(i > j)
            {
                if(a[i][j] == '1')
                    cntA++;
            }
            else if(i < j)
            {
                if(a[i][j] == '1')
                    cntB++;
            }
            else
            {
                if(a[i][j] == '1')
                    cntC++;
            }
        }
	}
	return cntA + cntC == cnt && cntB == 0 || cntA == 0 && cntB + cntC == cnt;
}

class cmp{
    bool operator()(vs a, vs b){
        return a[0] < b[0];
    }
}

void trunghieu()
{
    int t;
    cin>>t;
    int test = 1;
    while(t--)
    {
    	cin>>n;
        cnt = 0;
    	int i,j;
    	forn(i,n)
    	{
            cin>>a[i];
            forn(j,n)
                cnt+= (a[i][j] == '1');
        }
        if(check(a))
        {
            cout<<"Case "<<test++<<": 0\n";
        }
        else
    	{
            gp_hash_table<string,int> path, visited;
            unordered_map<vs,int, cmp> ok;
            queue<vs> q;
            q.push(a);
            string tmp = "";
            sort(a.begin(), a.begin() + n);
            do{
                if(check(a))
                    ok[a] = 1;
            }
            while(next_permutation(a.begin(), a.begin() + n));
            while(!q.empty())
            {
                auto u = q.front();q.pop();
                string temp = "";
                forn(j,n)
                    temp+=u[j];
                if(ok[u])
                {
                    cout<<"Case #"<<test++<<": "<<path[temp]<<endl;
                    break;
                }
                for(i = 0;i<n-1;i++)
                {
                    auto u1 = u;
                    swap(u1[i],u1[i+1]);
                    string tmp = "";
                    forn(j,n)
                        tmp+=u1[j];
                    if(path[tmp] == 0)
                    {
                        path[tmp] = path[temp] + 1;
                        q.push(u1);
                    }
                }
            }
        }
    }
}

int main()
{
    cerr << "Program is running" << endl;
    t1 = clock();
    ios::sync_with_stdio(false);
    cin.tie();
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        //freopen("output.txt","w",stdout);
    #endif
    trunghieu();
    t2 = clock();
    float diff ((float)t2-(float)t1);
    float seconds = diff / CLOCKS_PER_SEC;
    cerr << "\nRunning in " << seconds << " seconds" << endl;
    return 0;
}