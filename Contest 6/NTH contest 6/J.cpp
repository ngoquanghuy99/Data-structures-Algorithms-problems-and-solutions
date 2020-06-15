#pragma GCC optimize("Ofast")

#include<bits/stdc++.h>

using namespace std;

#define forn(i,n) for(i=0;i<n;++i)

void trunghieu()
{
    int n;
    cin>>n;
    string s[n],mirr[n];
    int i,j;
    forn(i,n)
    {
    	cin>>s[i];
    	mirr[i] = s[i];
    	mirr[i]+= s[i];
    }
    string temp = s[0];
    temp+=s[0];
    int beginner = 0, ans = INT_MAX;
    forn(j,s[0].size())
    {
    	string s1 = temp.substr(beginner, s[0].size());
    	int cnt = 0;
    	forn(i,n)
    	{
    		if(mirr[i].find(s1) == string::npos)
    		{
    			cout<<-1;
    			return;
    		}
    		cnt+= mirr[i].find(s1);
    	}
    	beginner++;
    	ans = min(ans, cnt);
    }
    cout<<ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie();
    trunghieu();
    return 0;
}