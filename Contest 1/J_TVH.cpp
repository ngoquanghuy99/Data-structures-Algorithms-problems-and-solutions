#include<iostream>
#include<algorithm>
 
using namespace std;
 
int m,n;
int a[30][30];
int ans;
void DFS(int u, int k)
{
    ans = max(ans,k);
    for (int i = 0; i < n ; i++)
    {
        if (a[u][i]) 
        {
            a[u][i] = 0;
            a[i][u] = 0;
            DFS(i,k+1);
            a[u][i] = 1;
            a[i][u] = 1;
 
        }
    }
}
 
int main()
{
    ios::sync_with_stdio(false);
    int test;
    cin >> test;
    while(test--)
    {
        ans = 0;
 
        for(int i = 0; i < 30; i++)
            for (int j = 0; j < 30 ; j++) a[i][j] = 0;
        cin >> n >> m;
        for (int i = 1; i <= m; i++)
        {
            int u,v;
            cin >> u >> v;
            a[u][v] = a[v][u] = 1;
        }
        for (int i = 0; i < n ; i++)
        {
            DFS(i,0);
        }
 
        cout << ans << endl;
    }
}
