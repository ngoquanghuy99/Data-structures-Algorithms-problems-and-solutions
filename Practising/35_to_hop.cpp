#include<bits/stdc++.h>
#define i64 long long
using namespace std;
int fast_pow(i64 base, i64 n, i64 M){
    if(n==0)
       return 1;
    if(n==1)
    return base;
    i64 halfn=fast_pow(base,n/2,M);
    if(n%2==0)
        return ( halfn * halfn ) % M;
    else
        return ( ( ( halfn * halfn ) % M ) * base ) % M;
}
int findMMI_fermat(int n,int M){
    return fast_pow(n,M-2,M);
}
int main(){
    i64 fact[100001];
    fact[0]=1;
    int i=1;
    int MOD=1000000007;
    while(i<=100000){
        fact[i]=(fact[i-1]*i)%MOD;
        i++;
    }
    int t; cin >> t;
    while(t--){
        int n,r;
        cin >> n >> r;
       	i64 numerator,denominator,mmi_denominator,ans;
        //I declared these variable as long long so that there is no need to use explicit typecasting
        numerator=fact[n];
        denominator=(fact[r]*fact[n-r])%MOD;
        mmi_denominator=findMMI_fermat(denominator,MOD);
        ans=(numerator*mmi_denominator)%MOD;
        cout << ans << endl;
    }
    return 0;
}
