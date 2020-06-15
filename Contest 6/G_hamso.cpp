#include<bits/stdc++.h>

using namespace std;

const int maxn = 1e5 + 5;

int a[maxn], n, b[maxn], c[maxn];

long long solve(int a[]){
	long long ans = 0, curr = 0;
	for(int i = 0;i<n-1;i++){
		curr+=a[i];
		if(curr < 0)
			curr = 0;
		else if(ans < curr)
			ans = curr;
	}
	return ans;
}

void presolve(){
	int t;
	cin>>t;
	while(t--){
		cin>>n;
		int i,j;
		for(i = 0;i<n;i++)
			cin>>a[i];
		for(i = 0;i<n-1;i++)
			b[i] = abs(a[i] - a[i+1]) * ((i%2 == 0)?1:-1),
			c[i] = -b[i];
		cout<<max(solve(b),solve(c))<<endl;
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie();
	presolve();
	return 0;
}

