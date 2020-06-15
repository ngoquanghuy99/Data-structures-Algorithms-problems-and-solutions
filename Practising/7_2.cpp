#include <bits/stdc++.h>

using namespace std;

long long a[10][10];
long long n, ans = 0, c[20];
int dem = 0;

void reset()
{
    memset(a, 0, sizeof(a));
    ans = 0;
}

void check()
{
    for (long long i = 1; i <= n; i++)
        for (long long j = i+1;j <= n; j++)
            if (i-c[i] == j - c[j] || i+c[i] == j + c[j])
                return;
    long long  t = 0;
    for (long long i = 1; i <= n; i++)
        t += a[i][c[i]];
    ans = max(ans, t);
}

int main()
{
    //freopen("inp.txt", "r", stdin);
    long long t;
    ios_base::sync_with_stdio(false);
    cin >> t;
    n = 8;
    while (t--)
    {
        reset();
        for (long long i = 1; i <= n; i++)
            for (long long j = 1; j <= n; j++)
                cin >> a[i][j];
        for (long long i = 1; i <= n; i++)
            c[i] = i;
        check();
        while(next_permutation(c+1, c+n+1))
            check();
        cout << ans << endl;
    }
    return 0;
}
