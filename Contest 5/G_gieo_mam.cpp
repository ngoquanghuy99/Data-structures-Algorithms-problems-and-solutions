#include<bits/stdc++.h>

using namespace std;

const int maxn = 5e2 + 1;

int r, c, a[maxn][maxn], visited[maxn][maxn];

typedef pair<int,int> pii;

void solve()
{
	cin>>r>>c;
	int i,j,dr[] = {-1,0,0,1}, dc[] = {0,-1,1,0}, ans =  0;
	queue<pii> q;
	for(i = 0 ;i<r;i++)
		for(j = 0;j<c;j++)
		{
			cin>>a[i][j];
			if(a[i][j] == 2)
			{
				q.push(make_pair(i,j));
				visited[i][j] = 1;
			}
		}
	while(!q.empty())
	{
		vector<pii> tmp;
		while(!q.empty())
		{
			pii u = q.front();
			q.pop();
			for(int k = 0; k < 4;k++)
			{
				int x = u.first + dr[k], y = u.second + dc[k];
				if(x >=0 && y>=0 && x < r && y < c && visited[x][y] == 0 && a[x][y] == 1)
				{
					tmp.push_back(make_pair(x,y));
					a[x][y] = 2;
					visited[x][y] = 1;
				}
			}
		}
		for(int k = 0;k < tmp.size();k++)
			q.push(tmp[k]);
		if(!q.empty())
			ans++;
	}
	for(i = 0;i<r;i++)
		for(j = 0;j<c;j++)
			if(a[i][j] == 1)
			{
				cout<<-1;
				return;
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
