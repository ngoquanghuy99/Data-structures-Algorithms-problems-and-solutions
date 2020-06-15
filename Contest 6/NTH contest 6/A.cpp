#pragma GCC optimize("Ofast")

#include<bits/stdc++.h>

using namespace std;

#define forn(i,n) for(i=0;i<n;++i)

const int maxn = 1e5 + 5;

int n, k, a[maxn];

void trunghieu()
{
    int t;
    cin>>t;
    while(t--)
    {
    	cin>>n>>k;
    	int i,j, flag = 0, ans = -1;
    	forn(i,n)
    	{
    		cin>>a[i];
    		if(a[i] == k)
    			ans = i + 1;
    	}
    	if(ans!=-1)
    		cout<<ans<<endl;
    	else cout<<"NO\n";
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie();
    trunghieu();
    return 0;
}