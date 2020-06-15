#include <bits/stdc++.h>
using namespace std;
int m, n;
int a[1009][1009];
int b[1009][1009];

int minA(){
	memset(b, 0, sizeof(b));
    b[1][1] = a[1][1];
    for(int i=2;i<=n;i++) 
		b[i][1] = b[i-1][1] + a[i][1];
    for(int j=2;j<=m;j++) 
		b[1][j] = b[1][j-1] + a[1][j];
    for(int i=2;i<=n;i++) 
		for(int j=2;j<=m;j++){
	        int tmp = min(b[i-1][j-1], b[i][j-1]);
	        tmp = min(tmp, b[i-1][j]);
	        b[i][j] = tmp+a[i][j];
    	}
    return b[n][m];
}
main(){
    long long t;
    cin >> t;
    while(t--){
        cin >> n >> m;
        for(int i=1;i<=n;i++) 
			for(int j=1;j<=m;j++) 
				cin >> a[i][j];
        cout << minA() << endl;
    }
    return 0;
}
