#include <bits/stdc++.h>

using namespace std;

string s;
long long k;

int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> s >> k;
    int n = s.length();
    int p = log2(k/n);
    long long m = n;
    for (int i = 1; i <= p+1; i++)
        m = 2*m;
    while (m > n)
    {
        if (k > m/2)
            {
                k = k-m/2-1;
                if (k == 0)
                    k = m/2;
            }
        m /= 2;
    }
    cout << s[k-1];
    return 0;
}
