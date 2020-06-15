#include <bits/stdc++.h>

using namespace std;

long long a, b, c;
long long f2, f3, f4, l, r;
long long const mod = 1e9+7;

long long fast_pow(long long x, long long y){
    if (y == 0)
        return 1;
    if (y == 1)
        return x;
    long long res = fast_pow(x, y/2);
    res = res*res%mod;
    if (y%2)
        return res*x%mod;
    return res;
}

long long calc(long long x, long long lf, long long rt){
    if (x == 1)
        return rt-lf+1;
    return ((fast_pow(x, rt+1) - fast_pow(x, lf)+mod)%mod*fast_pow(x-1, mod-2)%mod);
}

void output(){
    long long res = 0;
    res = (calc(a, l, r)+calc(b, l, r)+calc(c, l, r))%mod;
    cout <<res << endl;
}

bool square(long long u){
    if (u < 0)
        return false;
    long long v = sqrt(u);
    if (v*v != u)
        return false;
    return true;
}

bool check(long long u){
    long long x = f2-u*u;
    long long y = f3-u*u*u;
    long long z = f4-u*u*u*u;
    if (x <= 0 || y <= 0 || z <= 0)
        return false;
    if ((x*x-z)%2 || !square((x*x-z)/2))
        return false;
    long long k = z*2 - x*x;
    if (!square(k))
        return false;
    k = sqrt(k);
    long long b2 = (x + k)/2, c2 = (x - k)/2;
    if (!square(b2) || !square(c2))
        return false;
    b = sqrt(b2);
    c = sqrt(c2);
    if (u*u*u + b*b*b + c*c*c != f3 || b == c || a == c || a == b || b <= 0 || c <= 0)
        return false;
    return true;
}




int main(){
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--){
        cin >> f2 >> f3 >> f4 >> l >> r;
        for (a = 1; a <= min(f2, 15000LL); a++)
            if (check(a)){
            output();
            break;
        }
    }
    return 0;
}
