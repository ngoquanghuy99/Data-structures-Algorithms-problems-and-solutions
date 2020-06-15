#include<bits/stdc++.h>

using namespace std;

void trunghieu()
{
	int n,m;
	cin>>n>>m;
	map<int, vector<int>> adjList;
	int i,j, u, v;
	for(i = 0;i<m;i++)
	{
		cin>>u>>v;
		adjList[u].emplace_back(v);
		adjList[v].emplace_back(u);
	}
	for(i = 1;i<=n;i++)
	{
		for(auto j:adjList[i])
			cout<<j<<" ";
		cout<<endl;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie();
	trunghieu();
	return 0;
}