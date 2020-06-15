#include <iostream>
#include <stdio.h>
using namespace std;
long long Mod =  1e15+7;
typedef struct {
    long long X[5][5];
}matrix;
matrix A ;
void start(){
    for(int i = 0 ; i < 4 ;i ++)
        for(int j = 0 ; j < 4 ; j++)
            A.X[i][j] = 0;
    A.X[0][1] = A.X[1][2] = 1;
    A.X[2][0] = A.X[2][1] = A.X[2][2] = 1;
    A.X[3][3] = A.X[3][2] = A.X[3][1] = A.X[3][0] = 1;
}
long long mulll(long long a,long long b){
    if(b == 0) return 0ll;
    if(b == 1) return a;
    long long c = mulll(a,b >> 1);
    c = 2*c % Mod;
    if(b & 1 ) return (c+a) % Mod;
    return c;
}

matrix mul(matrix a, matrix b){
    matrix c;
    for(int i = 0 ; i < 4 ; i++)
        for(int j = 0 ; j < 4 ; j++) c.X[i][j] = 0;
    for(int i = 0 ; i < 4 ; i++)
        for(int j = 0 ; j < 4 ; j++)
            for(int k = 0 ; k < 4 ; k++)
                c.X[i][j] += mulll(a.X[i][k] , b.X[k][j]), c.X[i][j] %= Mod;
    return c;
}
matrix Pow(matrix a, long long n){
    if(n == 1) return a;
    matrix c = Pow(a,n >> 1);
    c = mul(c,c);
    if( n & 1) return mul(a,c);
    return c;
}

int main(){
    int t;
    scanf("%d",&t);
    start();
    while(t--){
        long long n;
        scanf("%lld",&n);
        matrix ans = Pow(A,n);
        cout << ans.X[3][1] <<endl;
    }

}

