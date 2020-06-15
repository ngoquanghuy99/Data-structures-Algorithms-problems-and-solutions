#include<stdio.h>
int opt[2000][100];
int a[2000];
int n,k,i,j,s;
int f(int x)
{
    if (x>=0) return (x);
    return (x+k);
}
int min(int a,int b)
{
    if (a<b) return (a); else return (b);
}
int main(void)
{
    scanf("%d",&n);
    scanf("%d",&k);
    s=0;
    for (i=1;i<=n;i=i+1)
        {
         scanf("%d",&a[i]);
         a[i]=a[i]%k;
         s=(s+a[i])%k;
        }
    opt[0][0]=0;
    for (i=1;i<k;i=i+1) opt[0][i]=32000;
    for (i=1;i<=n;i=i+1)
        for (j=0;j<k;j=j+1)
            opt[i][j]=min(opt[i-1][j],opt[i-1][f(j-a[i])]+1);
    printf("%d",n-opt[n][s%k]);
    return 0;       
}
