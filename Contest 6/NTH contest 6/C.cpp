#include<bits/stdc++.h>

using namespace std;

const int maxn = 1e5 + 5;

int n, a[maxn], c, d;

void trunghieu()
{
	int t;
	cin>>t;
	while(t--)
	{
		cin>>n>>c>>d;
		int i,j;
		for(i = 0;i<n;i++)
			cin>>a[i];
		sort(a,a+n, greater<int>());
		double ans = 0, sumA = 0, sumB = 0;
		if(c > d)
			swap(c,d);
		for(i = 0;i<n;i++)
		{
			if(i < c)
				sumA+=a[i];
			else if(i < c + d)
				sumB+=a[i];
			else break;
		}
		ans = (sumA * 1.0)/c + (sumB * 1.0)/d;
		cout<<setprecision(6)<<fixed<<ans<<endl;
	}
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie();
	//freopen("input.txt","r",stdin);
	trunghieu();
	return 0;
}