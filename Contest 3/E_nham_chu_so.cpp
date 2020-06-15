#include<iostream>
#include<math.h>
using namespace std;
long doiso(long n, long a,long b )
{
	long i,dem=0,tam,kq=0,j;
	tam=n;
	while (n>0)
	{
		dem++;
		n/=10;
	}
	for (i=1;i<=dem,tam>0;i++)
	{
		long k=pow(10,dem-i);
		j=tam/k;
		if(j==a) j=b;
		kq+=j*k;
		tam%=k;
	}
	return kq;
}
int main()
{
	long a,b,m=5,n=6;
	cin>>a; cin>>b;
	cout<<doiso(a,n,m)+doiso(b,n,m)<<" "<<doiso(a,m,n)+doiso(b,m,n);
	return 0;
}

