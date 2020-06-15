#include<bits/stdc++.h>

using namespace std;

const int maxn = 1e5 + 5;

pair<int,int> cost[maxn];

int n,k;

void trunghieu()
{
	cin>>n>>k;
	int i,j;
	for(i = 0;i<n;i++)
		cin>>cost[i].first;
	for(i = 0;i<n;i++)
		cin>>cost[i].second;
	sort(cost, cost + n, [](pair<int,int> a, pair<int,int> b){
		return a.first - a.second < b.first - b.second;
	});
	long long ans = 0;
	for(i = 0;i<n;i++)
	{
		if(i < k)
			ans+= cost[i].first;
		else ans+= cost[i].second;
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