#include<iostream>
using namespace std;
long long mod = 1e9 + 7;
long long powK(long long N, long long K){
	if(K==0) return 1;
	long long x = powK(N, K/2);
	return (K & 1) ? ((x*x)%mod)*N%mod : x*x%mod; 
}
int main(){
	ios_base::sync_with_stdio(false);
	int T = 0, N, K;
	cin>>T;
	while(T--){
		cin>>N>>K;
		cout<<powK(N, K)<<endl;
	}
}
