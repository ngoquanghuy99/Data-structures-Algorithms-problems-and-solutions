#include <bits/stdc++.h>

using namespace std;

int a[30][30], dd[30][30], ufr[30];
int n, ans = INT_MAX;

void reset()
{
    memset(a, 0, sizeof(a));
    memset(dd, 0, sizeof(dd));
    memset(ufr, 0, sizeof(ufr));
}

int findmin()
{
    int mn = INT_MAX;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (i != j && dd[i][j] == 0)
                mn = min(mn, a[i][j]);
    return mn;
}

void dfs(int u, int cnt, int dis)
{
    if (cnt == n)
    {
        ans = min(ans, dis);
        return;
    }
    ufr[u] = 1;
    for (int v = 1; v <= n; v++)
    {
        if (ufr[v])
            continue;
        if (findmin()*(n-cnt) + dis > ans)
            continue;
        dd[u][v] = 1;
        dfs(v, cnt+1, dis+a[u][v]);
        dd[u][v] = 0;
    }
    ufr[u] = 0;
}

int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    int test;
    cin >> test;
    while (test--)
    {
        reset();
        cin >> n;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                cin >> a[i][j];
        for (int i = 1; i <= n; i++)
            if (findmin() < ans)
                dfs(i, 1, 0);
        cout << ans << endl;
    }
    return 0;
}
