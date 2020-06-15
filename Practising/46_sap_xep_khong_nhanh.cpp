#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	long long n = 0; cin >> n; long long a[n+1]; for(int i = 0; i < n; i++) cin >> a[i];
	stable_sort(a, a+n); for(int i = 0; i < n; i++) cout << a[i] << " ";
}
