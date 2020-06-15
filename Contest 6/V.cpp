#pragma GCC optimize("Ofast")

#include<bits/stdc++.h>

using namespace std;

typedef pair<int,int> pii;

const int maxn = 1e3 + 5;

int n, k, m;

vector<pii> point(maxn);

void solve()
{
	cin>>n>>k>>m;
	map<pair<pii, pii>, int> ban;
	map<pii,int> visited, group;
	int i,j, u, v, x, y, gr = 1;
	for(i = 0;i<m;i++)
	{
		cin>>u>>v>>x>>y;
		ban[{{u,v},{x,y}}] = 1;
		ban[{{x,y},{u,v}}] = 1;
	}
	for(i = 0;i<k;i++)
		cin>>point[i].first>>point[i].second;
	int dr[] = {-1,0,0,1},
		dc[] = {0,-1,1,0}, ans = 0;
	for(i = 0;i<k;i++)
	{
		int x = point[i].first, y = point[i].second;
		if(!visited[{x,y}])
		{
			queue<pii> q;
			q.push({x,y});
			visited[{x,y}] = 1;
			group[{x,y}] = gr;
			while(!q.empty())
			{
				auto u = q.front();q.pop();
				for(int j = 0;j<4;j++)
				{
					int x1 = u.first + dr[j],
						y1 = u.second + dc[j];
					if(x1 >= 1 && y1 >= 1 && x1 <= n && y1 <= n  && !visited[{x1,y1}] 
						&& ban[{{x1,y1},{u.first,u.second}}] == 0)
					{
						group[{x1,y1}] = gr;
						q.push({x1,y1});
						visited[{x1,y1}] = 1;
					}
				}
			}
			gr++;
		}
	}
	for(i = 0;i<k;i++)
	{
		int x = point[i].first, y = point[i].second;
		for(j = i + 1;j<k;j++)
		{
			int x1 = point[j].first, y1 = point[j].second;
			if(group[{x,y}]!= group[{x1,y1}])
				ans++;
		}
	}
	cout<<ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie();
    solve();
    return 0;
}
