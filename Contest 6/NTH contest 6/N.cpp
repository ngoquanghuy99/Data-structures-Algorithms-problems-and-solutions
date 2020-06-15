#include<bits/stdc++.h>

using namespace std;

const int maxn = 50;

int ans[maxn][maxn], n;

map<int,set<int>> adjList;

void trunghieu()
{
	cin>>n;
	int i;
	cin.ignore();
	string s;
	set<pair<int,int>> ans;
	for(i = 1;i<=n;i++)
	{
		getline(cin,s);
		string token;
		stringstream ss(s);
		while(ss>>token)
		{
			int v = stoi(token), u = i;
			if(u > v)
				swap(u,v);
			ans.insert({u,v});
		}
	}
	for(auto i:ans)
		cout<<i.first<<" "<<i.second<<endl;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie();
	trunghieu();
	return 0;
}