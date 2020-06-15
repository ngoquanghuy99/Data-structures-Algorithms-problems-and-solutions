#include <bits/stdc++.h>

using namespace std;

int a[10], k, n;
int c[10][10];
vector <vector <int> > ans;

void check()
{
    int t = 0;
    for (int i = 1; i <= n; i++)
        t += c[i][a[i]];
    if (t == k)
    {
        vector <int> res;
        for (int i = 1; i <= n; i++)
            res.push_back(a[i]);
        ans.push_back(res);
    }
    return ;
}


int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> c[i][j];
    for (int i = 1; i <= n; i++)
        a[i] = i;
    check();
    while (next_permutation(a+1, a+n+1))
        check();
    cout << ans.size() << endl;
    for (int i = 0; i < ans.size(); i++)
    {
        vector <int> v = ans[i];
        for (int j = 0; j <v.size(); j++)
            cout << v[j] << " ";
        cout << endl;
    }
    return 0;
}
