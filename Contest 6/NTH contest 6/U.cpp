#include<bits/stdc++.h>

using namespace std;

const int maxn = 505;

int a[maxn][maxn];

int n, m;

void trunghieu()
{
	int t;
	cin>>t;
	while(t--)
	{
		cin>>n>>m;
		int i,j;
		for(i = 0;i<n;i++)
			for(j = 0;j<m;j++)
				cin>>a[i][j];
		int ans = 0;
		int dr[] = {-1,-1,-1,0,0,1,1,1},
			dc[] = {-1,0,1,-1,1,-1,0,1};
		for(i = 0;i<n;i++)
		{
			for(j = 0;j<m;j++)
			{
				if(a[i][j] == 1)
				{
					ans++;
					queue<pair<int,int>> q;
					q.push({i,j});
					while(!q.empty())
					{
						auto u = q.front();q.pop();
						for(int k = 0;k<8;k++)
						{
							int x = u.first + dr[k],
								y = u.second + dc[k];
							if(x >=0 && y>=0 && x < n && y<m 
								&& a[x][y] == 1)
							{
								a[x][y] = 0;
								q.push({x,y});
							}
						}
					}
				}
			}
		}
		cout<<ans<<endl;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie();
	trunghieu();
	return 0;
}