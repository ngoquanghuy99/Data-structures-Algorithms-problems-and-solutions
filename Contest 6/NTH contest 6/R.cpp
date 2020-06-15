#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;
using namespace std;

const int maxn = 1e3 + 5;

int n, m, visited[maxn];

void trunghieu()
{
	int t;
	cin>>t;
	while(t--)
	{
		map<int,vector<int>> adjList;
		map<int,int> group;
		memset(visited,0,sizeof(visited));
		cin>>n>>m;
		int i,j, u, v;
		for(i = 0;i<m;i++)
		{
			cin>>u>>v;
			adjList[u].emplace_back(v);
			adjList[v].emplace_back(u);
		}
		int gr = 1;
		for(i = 1;i<=n;i++)
		{
			if(visited[i] == 0)
			{
				queue<int> q;
				q.push(i);
				group[i] = gr;
				while(!q.empty())
				{
					int u = q.front();q.pop();
					for(auto j:adjList[u])
					{
						if(!visited[j])
						{
							visited[j] = 1;
							group[j] = gr;
							q.push(j);
						}
					}
				}
				gr++;
			}
		}
		int q;
		cin>>q;
		while(q--)
		{
			int x,y;
			cin>>x>>y;
			if(group[x]!=group[y])
				cout<<"NO\n";
			else cout<<"YES\n";
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie();
	//freopen("input.txt","r",stdin);
	trunghieu();
	return 0;
}