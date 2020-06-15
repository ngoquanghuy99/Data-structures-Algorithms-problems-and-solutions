#include<bits/stdc++.h>

using namespace std;

const int maxn = 1e3 + 5;

int a[maxn][maxn], n;
map<int,vector<int>> adjList;

void trunghieu()
{
	cin>>n;
	int i,j;
	for(i = 1;i<=n;i++)
	{
		for(j = 1;j<=n;j++)
		{
			cin>>a[i][j];
			if(a[i][j])
			{
				adjList[i].emplace_back(j);
			}
		}
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