#include<iostream>
using namespace std;
const long long mod = 1e9 + 7;
void matrix_multi(long long F[2][2], long long M[2][2]){
	long long x = F[0][0]*M[0][0] + F[0][1]*M[1][0];
	long long y = F[0][0]*M[0][1] + F[0][1]*M[1][1];
	long long z = F[1][0]*M[0][0] + F[1][1]*M[1][0];
	long long t = F[1][0]*M[0][1] + F[1][1]*M[1][1];
	
	F[0][0] = x;
	F[0][1] = y;
	F[1][0] = z;
	F[1][1] = t;
}
void power(long long F[2][2], long long n){
	if(n==0 || n==1) return;
	long long M[2][2] = {{1,1}, {1,0}};
	power(F,n/2);
	matrix_multi(F,F);
	if(n%2 != 0) 
		matrix_multi(F,M);
}
long long fib(long long n){
	long long F[2][2] = {{1,1}, {1,0}};
	if(n==0) return 0;
	power(F, n-1);
	return F[0][0]%mod;
}
int main(){
	long long t = 0, n;
	cin>>t;
	while(t--){
		cin>>n;
		cout<<fib(n)<<endl;
	}
}
