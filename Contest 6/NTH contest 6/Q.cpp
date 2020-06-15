#include<bits/stdc++.h>

using namespace std;

const int maxn = 105;

char a[maxn][maxn];

int n, m;

void trunghieu()
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
			if(a[i][j] == 'W')
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
							&& a[x][y] == 'W')
						{
							a[x][y] = '.';
							q.push({x,y});
						}
					}
				}
			}
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