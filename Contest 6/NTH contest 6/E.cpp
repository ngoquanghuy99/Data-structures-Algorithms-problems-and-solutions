#include<bits/stdc++.h>

using namespace std;

const int maxn = 105;

pair<int,int> a[maxn];

int n;

void trunghieu()
{
	cin>>n;
	int i,j;
	for(i = 0;i<n;i++)
		cin>>a[i].first>>a[i].second;
	sort(a,a+n,[](pair<int,int> a, pair<int,int> b){
		return a.first < b.first
		|| a.first == b.first && a.second < b.second;
	});
	int ans = 0;
	for(i = 0;i < n;i++)
	{
		if(i == 0)
			ans = a[i].first + a[i].second;
		else
		{
			if(a[i].first < ans)
				ans+=a[i].second;
			else ans = a[i].first + a[i].second;
		}
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