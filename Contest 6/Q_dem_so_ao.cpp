#include <bits/stdc++.h>
using namespace std;
string s[101];
int chuaxet[101][101];
int n,m;

void dfs(int u, int v){
	chuaxet[u][v]=0;
	for (int k=u-1;k<=u+1;++k){
		for (int l=v-1;l<=v+1;++l){
			if (s[k][l] == 'W' && chuaxet[k][l])
				dfs(k,l);
		}
	}
}

main(){
	cin >> n >> m;
	int dem=0;
	for (int i=0;i<n;++i)
		cin >> s[i];
	for (int i=0;i<n;++i){
		for (int j=0;j<m;++j)
			chuaxet[i][j]=1;
	}
	for (int i=0;i<n;++i){
		for (int j=0;j<m;++j){
			if (s[i][j]=='W' && chuaxet[i][j]){
				dfs(i,j);
				dem++;
			}
		}
	}
	cout << dem;
}
/*
 W . . . . . . . . W W .
 . W W W . . . . . W W W
 . . . . W W . . . W W .
 . . . . . . . . . W W .
 . . . . . . . . . W . .
 . . W . . . . . . W . .
 . W . W . . . . . W W . 
 W . W . W . . . . . W .
 . W . W . . . . . . W .
 . . W . . . . . . . W .
*/

