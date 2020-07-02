#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
using namespace std;

#define long long long
const int N=1000006, BASE=1000000007;
int m, n;
char a[N], b[N];
long A[N], B[N], M[N];

void hash_build(char a[], int n, long H[]) {
    for (int i=1; i<=n; i++)
    H[i] = (H[i-1] * M[1] + a[i]) % BASE;
}

long hash_range(long H[], int L, int R) {
    return (H[R] - H[L-1]*M[R-L+1] + 1LL*BASE*BASE) % BASE;
}

main() {
    M[0]=1; M[1]=2309;
    for (int i=2; i<N; i++)
    M[i] = M[i-1] * M[1] % BASE;
    
    scanf("%s", a+1); m=strlen(a+1);
    scanf("%s", b+1); n=strlen(b+1);
    hash_build(a, m, A);
    hash_build(b, n, B);
    for (int i=1; i<=m-n+1; i++) {
        if (hash_range(A, i, i+n-1) == B[n])
        printf("%d ", i);
    }
    printf("\n");
}

