#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
 
struct matrix{
    long long c[2][2];
    matrix(){
        c[0][0]=0;
        c[0][1]=1;
        c[1][0]=1;
        c[1][1]=1;
    }
};
 
matrix operator * (matrix a, matrix b){
    matrix res;
    for (int i=0; i<=1; i++)
        for (int j=0; j<=1; j++){
            res.c[i][j] = 0;
            for (int k=0; k<=1; k++)
                res.c[i][j] = (res.c[i][j]+a.c[i][k]*b.c[k][j])%mod;
        }
    return res;
}
 
matrix powermod (matrix a, long long n){
    if (n==1)
        return a;
    if (n%2!=0)
        return powermod(a,n-1)*a;
    matrix tmp = powermod(a,n/2);
    return tmp*tmp;
}
 
int main(){
    long long t = 0, n;
    cin>>t;
    while(t--){
    	cin>>n;
    	matrix A;
    	A = powermod(A,n);
    	cout << A.c[0][1] <<endl;
	}   
    return 0;
}
