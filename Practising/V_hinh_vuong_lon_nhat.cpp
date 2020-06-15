#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e3+100;
int n, m;
int a[maxn][maxn], dp[maxn][maxn], ans = 0;

void reset()
{
    ans = 0;
    memset(a, 0, sizeof(a));
    memset(dp, 0, sizeof(dp));
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
        cin >> n >> m;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
                cin >> a[i][j];
        for (int i = 1;  i <= n; i++)
            for (int j = 1; j <= m; j++)
                if (a[i][j])
                    {
                        dp[i][j] = min(dp[i-1][j-1], min(dp[i][j-1], dp[i-1][j]))+1;
                        ans = max(ans, dp[i][j]);
                    }
                else
                    dp[i][j] = 0;
        cout << ans << endl;
    }
    return 0;
}
