/************************************************\

	you know that i can't stop thinkin bout you
	you're the source of everything i do

\************************************************/
#include <bits/stdc++.h>
using namespace std;
int a[105];
int l[105][25005];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int c, n; cin >> c >> n;
	for(int i = 1; i <= n; i++) cin >> a[i];
	for(int i = 1; i <= n; i++){
		for(int j = 0; j <= c; j++){
			l[i][j] = l[i-1][j];
			if(a[i] <= j){
				l[i][j] = max(l[i][j], l[i-1][j-a[i]]+a[i]);
			}
		}
	}
	cout << l[n][c];
}

