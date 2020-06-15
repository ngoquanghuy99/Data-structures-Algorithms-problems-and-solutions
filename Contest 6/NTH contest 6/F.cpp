#include<bits/stdc++.h>

using namespace std;

const int maxn = 1e2 + 5;

int n, a[maxn], b[maxn];

void trunghieu()
{
	cin>>n;
	int i,j;
	for(i = 0;i<n;i++)
		cin>>a[i];
	for(i = 0;i<n;i++)
		cin>>b[i];
	sort(a,a+n);
	sort(b,b+n);
	for(i = 0;i<n;i++)
	{
		if(a[i] > b[i])
		{
			cout<<"NO";
			return;
		}
	}
	cout<<"YES";
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie();
	//freopen("input.txt","r",stdin);
	trunghieu();
	return 0;
}