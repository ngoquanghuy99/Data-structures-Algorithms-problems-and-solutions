#include <bits/stdc++.h>

using namespace std;

const long long mod = 1e9+7, maxn = 200, maxc = 5040l;
int n, k;
long long dp[maxn][maxc];

int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    int test;
    cin >> test;
    while (test --)
    {
        cin >> n >> k;
        if (k == 0 && n == 1)
        {
            cout << 0 << endl;
            continue;
        }
        memset(dp, 0, sizeof(dp));
        for (int i = 1; i <= 9; i++)
            dp[1][i] = 1;
        for (int i = 2; i <= n; i++)
            for (int j = 0; j <= k; j++)
                for (int ii = 0; ii <= 9; ii++)
                    if (j-ii >= 0)
                        dp[i][j] = (dp[i][j] + dp[i-1][j-ii])%mod;
        cout << dp[n][k] << endl;
    }
    return 0;
}
