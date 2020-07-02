#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
using namespace std;

#define N 500005
int n, z[N];
char a[N];

void make_z(char a[], int n, int F[]) {
    int L=-1, R=-1; F[0]=n;
    for (int i=1; i<n; i++) {
        if (i>R) {
            L=i; R=i-1;
            while (R<n-1 && a[R+1]==a[R-L+1]) R++;
            F[i]=R-L+1;
        } else {
            if (F[i-L]<R-i+1) F[i]=F[i-L];
            else {
                L=i;
                while (R<n-1 && a[R+1]==a[R-L+1]) R++;
                F[i]=R-L+1;
            }
        }
    }
}

main(){
    gets(a); n=strlen(a);
    make_z(a, n, z);
    for (int i=0; i<n; i++)
    printf("%d ", z[i]);
    printf("\n");
}
