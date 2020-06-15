#include <bits/stdc++.h>

using namespace std;

const long long mod = 1e9+7;
const int maxn = 1e5+100;
long long dp[maxn];
int n, k;

void reset()
{
    memset(dp, 0, sizeof(dp));
}

int main()
{
    ios_base::sync_with_stdio(false);
    int test;
    cin >> test;
    while (test--)
    {
        reset();
        cin >> n >> k;
        dp[0] = 1;
        for (int i = 1; i <= min(n, k); i++)
            for (int j = i-1; j >= 0; j--)
                dp[i] = (dp[i]+dp[j])%mod;
        for (int i = k+1; i <= n; i++)
            dp[i] = (dp[i-1]*2LL-dp[i-k-1]+mod)%mod;
        cout << dp[n] << endl;
    }
    return 0;
}
