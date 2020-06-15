#include <bits/stdc++.h>
#define mod 1000000007 
using namespace std;
typedef long long ll;
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll t;
    cin>>t;
    while(t--)
    {
        ll m,n,i,j,k;
        cin>>m>>n;
        ll a[m+1][m+1];
        ll res[m+1][m+1];
        
        for(i=1;i<=m;i++){
            for(j=1;j<=m;j++){
                cin>>a[i][j];
                if(i==j)
                    res[i][j] = 1;
                else
                    res[i][j] = 0;
            }
        }
        while(n>0){
            if(n&1){
                ll tres[m+1][m+1];
                for(i=1;i<=m;i++){
                    for(j=1;j<=m;j++){
                        tres[i][j] = 0;
                        for(k=1;k<=m;k++){
                            tres[i][j] = (tres[i][j] + (res[i][k]*a[k][j])%mod)%mod;
                        }
                    }
                }
                for(i=1;i<=m;i++){
                    for(j=1;j<=m;j++){
                        res[i][j] = tres[i][j];
                    }
                }
            }
            
            ll tres[m+1][m+1];
            for(i=1;i<=m;i++){
                for(j=1;j<=m;j++){
                    tres[i][j] = 0;
                    for(k=1;k<=m;k++){
                        tres[i][j] = (tres[i][j] + (a[i][k]*a[k][j])%mod)%mod;
                    }
                }
            }
            for(i=1;i<=m;i++){
                for(j=1;j<=m;j++){
                    a[i][j] = tres[i][j];
                }
            }
            
            n /= 2;
        }
        
        for(i=1;i<=m;i++){
            for(j=1;j<=m;j++){
                cout<<res[i][j]<<" ";
            }cout<<"\n";
        }
    }
    return 0;
}
