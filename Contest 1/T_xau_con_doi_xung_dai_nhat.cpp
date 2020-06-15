#include <bits/stdc++.h>

using namespace std;

const int maxn = 5100;
string s;
int dp[maxn][maxn], ans = 0, n;
char a[maxn];

int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    int test;
    cin >> test;
    while (test --)
    {
        ans = 0;
        cin >> s;
        n = s.length();
        for (int i = 0; i < n; i++)
            a[i+1] = s[i];
        memset(dp, 0, sizeof(dp));
        for (int i = 1; i <= n; i++)
            dp[i][i] = 1, ans = 1;
        for (int i = 1; i < n; i++)
            if (a[i] == a[i+1])
                dp[i][i+1] = 2, ans = 2;
        for (int j = 3; j <= n; j++)
            for (int i = 1; i <= n-j+1; i++)
            {
                int f = i, s = i+j-1;
                if (a[f] == a[s] && dp[f+1][s-1] != 0)
                {
                    dp[f][s] = dp[f+1][s-1] + 2;
                    ans = max(dp[f][s], ans);
                }
            }
        cout << ans << endl;
    }
    return 0;
}
