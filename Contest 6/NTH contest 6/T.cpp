#pragma GCC optimize("Ofast")

#include<bits/stdc++.h>

using namespace std;

#define forn(i,n) for(i=0;i<n;++i)
#define for1(i,n) for(i=1;i<=n;++i)
#define eb emplace_back

typedef vector<int> vi;

const int maxn = 1e3 + 5;
const int inf = 1e5;

int n, m, visited[maxn];

map<int,vi> adjList;

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
    	cin>>n>>m;
        adjList.clear();
        memset(visited,0,sizeof(visited));
    	int i,j, u, v;
    	forn(i,m)
    	{
    		cin>>u>>v;
    		adjList[u].eb(v);
    		adjList[v].eb(u);
    	}
        vector<int> color(n + 1, inf);
        int flag = 1;
        for(i = 1;i<=n && flag;i++)
        {
            if(color[i] == inf)
            {
                queue<int> q;
                q.push(i);
                color[i] = 1;
                while(!q.empty() && flag)
                {
                    int u = q.front();q.pop();
                    for(auto i:adjList[u])
                    {
                        if(color[i] == inf)
                        {
                            color[i] = 1 - color[u];
                            q.push(i);
                        }
                        else if(color[i] == color[u])
                        {
                            flag = 0;
                            break;
                        }
                    }
                }
            }
        }
        if(flag)
            cout<<"YES\n";
        else cout<<"NO\n";
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie();
    trunghieu();
    return 0;
}