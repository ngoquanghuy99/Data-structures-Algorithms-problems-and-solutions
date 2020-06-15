#include<bits/stdc++.h>

using namespace std;

const int maxn = 1e3 + 5;

int n, visited[maxn];
map<int,vector<int>> adjList;

void dfs(int u)
{
	visited[u] = 1;
	for(auto i:adjList[u])
		if(!visited[i])
			dfs(i);
}

void trunghieu()
{
	int t;
	cin>>t;
	while(t--)
	{
		cin>>n;
		adjList.clear();
		memset(visited,0,sizeof(visited));
		int i, u, v, cnt = 0;
		for(i = 0;i<n-1;i++)
		{
			cin>>u>>v;
			adjList[u].emplace_back(v);
			adjList[v].emplace_back(u);
		}
		for(i = 1;i<=n;i++)
		{
			if(visited[i] == 0)
			{
				cnt++;
				dfs(i);
			}
		}
		if(cnt > 1)
			cout<<"NO\n";
		else cout<<"YES\n";
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie();
	trunghieu();
	return 0;
}