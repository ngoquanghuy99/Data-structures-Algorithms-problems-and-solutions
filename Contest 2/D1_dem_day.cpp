#include<iostream>
#include<cmath>
const int mod = 123456789;
using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
	int t = 0;
	cin>>t;
	long long n;
	while(t--){
		cin>>n;
		if(n==1) cout<<1<<endl;
		else{
			--n;
			long long ans = 1;
			long long x = 2;
			while(n){
				if(n & 1) ans = (1ll*ans*x)%mod;
				x = (x*x*1ll)%mod;
				n >>= 1;
			}
			cout<<ans<<endl;
		}
	}
	return 0;
}
