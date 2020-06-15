#include<bits/stdc++.h>

using namespace std;

const int maxn = 1e3 + 5;

int a[maxn][maxn];

int n;

void trunghieu()
{
	cin>>n;
	int i,j;
	cin.ignore();
	string s;
	for(i = 0;i<n;i++)
	{
		getline(cin,s);
		stringstream ss(s);
		string token;
		while(ss>>token)
		{
			int u = stoi(token);
			a[i][u - 1] = 1;
			a[u-1][i] = 1;
		}
	}
	for(i = 0;i<n;i++)
	{
		for(j = 0;j<n;j++)
			cout<<a[i][j]<<" ";
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