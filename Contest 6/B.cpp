#include<bits/stdc++.h>
using namespace std;
int n,q,x[100001],y[100001];
int main()
{
 
cin>>n; for(int i=0;i<n;i++) cin>>x[i];
sort(x,x+n);
cin>>q; for(int i=0;i<q;i++) cin>>y[i];
 
for(int i=0;i<q;i++)
	if(y[i]<x[0])
		cout<<"0"<<endl;
	else
		cout<<upper_bound(x,x+n,y[i])-x<<endl;
 
return 0;
}
 
