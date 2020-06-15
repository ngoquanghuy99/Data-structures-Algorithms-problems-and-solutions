#include<bits/stdc++.h>

using namespace std;

void trunghieu()
{
	int t;
	cin>>t;
	while(t--)
	{
		string p, t;
		cin>>p>>t;
		if(p.find(t)!=string::npos)
			cout<<"YES\n";
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