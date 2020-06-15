#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e3+100, maxk = 1e2;
int n, k;
int dp[maxn][maxk], a[maxn];

int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    memset(dp, 0, sizeof(dp));
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        cin >> a[i], a[i] %= k;
    dp[1][a[1]] = 1;
    for (int i = 2; i <= n; i++)
    {
        for (int j = 0; j <= k; j++)
            dp[i][j] = dp[i-1][j];
        dp[i][a[i]] = max(dp[i][a[i]], 1);
        for (int j = 0; j <= k; j++)
            if (dp[i-1][j])
        {
            int val = (j+a[i])%k;
            dp[i][val] = max(dp[i][val], dp[i-1][j]+1);
        }
    }
    cout << dp[n][0];
    return 0;
}
