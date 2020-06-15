#include <bits/stdc++.h>

using namespace std;

int t;
long long l, r, n;

long long logcnt(long long x){
    int res = 0;
    while ((1LL << res) <= x)
        res ++;
    return 1LL<<res;
}

long long calc(long long x, long long y){
    if (y == 0)
        return 0;
    if (x == 1)
        return 1;
    int val = x%2;
    long long p = logcnt(x)-1;
    if (y <= p/2)
        return calc(x/2, y);
    long long res = calc(x/2, p/2);
    if (p == y)
        return res*2+val;
    if (y == (p+1)/2)
        return val+res;
    if (y > (p+1)/2)
        return res+calc(x/2, y-(p+1)/2)+val;
}

int main(){
  
    ios_base::sync_with_stdio(false);
    cin >> t;
    while (t--){
        cin >> n>> l >> r;
        int res1 = calc(n, r);
        int res2 = calc(n, l-1);
        cout << calc(n, r) - calc(n, l - 1) << endl;
    }
    return 0;
}
