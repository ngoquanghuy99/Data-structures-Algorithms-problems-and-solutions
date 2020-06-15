#include <stdio.h>
 
const int oo = 1000111000;
int a[239][239];
int n, m;
 
void minimize(int &a, int b){ if (a>b) a=b; }
 
main(){
    int i,j,k, p,q,w;
    scanf("%d%d", &n, &m);
    for (i=1; i<=n; i++)
    for (j=1; j<=n; j++)
    a[i][j] = oo;
    for (i=1; i<=n; i++)
    a[i][i] = 0;
    
    for (i=1; i<=m; i++)
    {
        scanf("%d%d%d", &p, &q, &w);
        a[p][q] = a[q][p] = w;
    }
    
    for (k=1; k<=n; k++)
    for (i=1; i<=n; i++)
    for (j=1; j<=n; j++)
    minimize(a[i][j], a[i][k] + a[k][j]);
    
    printf("%d\n", a[1][n]);
}
