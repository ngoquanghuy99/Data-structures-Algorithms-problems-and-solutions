#include <bits/stdc++.h>

using namespace std;

long long calc(long long x, long long y)
{
    if (x == 0 && y == 0)
        return 0;
    return calc(x/3, y/2) + ((x%3)%2)+y%2;
}

int main()
{
    int t;
    ios_base::sync_with_stdio(false);
    cin >> t;
    while (t--)
    {
        long long x, y;
        cin >> x >>y;
        cout << calc(x, y) << endl;
    }
    return 0;
}
