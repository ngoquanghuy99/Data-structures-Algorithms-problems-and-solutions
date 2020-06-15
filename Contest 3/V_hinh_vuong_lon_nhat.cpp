#include<bits/stdc++.h>
#define loop(i,a,b) for(int i=(int)a;i<(int)b;++i)
using namespace std;

void solve(std::istream &in, std::ostream &out){
    int n,m; in>>n>>m; int a[n+5][m+5], dp[n+5][m+5];
    loop(i,0,n){
        loop(j,0,m) in>>a[i][j];
    }
    memset(dp,0,sizeof(dp));
    loop(i,0,n) dp[i][0]=a[i][0];
    loop(i,0,m) dp[0][i]=a[0][i];
    loop(i,1,n){
        loop(j,1,m){
            if(a[i][j]==1){
                dp[i][j]=min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1]))+1;
            }
            else dp[i][j]=0;
        }
    }
    int ans=INT_MIN;
    loop(i,0,n){
        loop(j,0,m){
            if(ans<dp[i][j]) ans=dp[i][j];
        }
    }
    out<<ans<<endl;
//    loop(i,0,ans){
//        loop(j,0,ans){
//            out<<1<<" ";
//        }
//        cout<<"\n";
//    }
}

int main(){
	int t = 0; cin >> t;
	while(t--)
    	solve(std::cin, std::cout);
    return 0;
}
