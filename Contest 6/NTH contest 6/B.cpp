#pragma GCC optimize("Ofast")

#include<bits/stdc++.h>

using namespace std;

#define forn(i,n) for(i=0;i<n;++i)


const int maxn = 1e5 + 5;

int n, a[maxn], y, q;


void trunghieu()
{
    cin>>n;
    int i,j;
    forn(i,n)
    	cin>>a[i];
    random_shuffle(a,a+n);
    sort(a,a+n);
    cin>>q;
    while(q--)
    {
    	cin>>y;
    	auto id = upper_bound(a,a+n,y) - a;
    	cout<<id<<endl;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie();
    trunghieu();
    return 0;
}