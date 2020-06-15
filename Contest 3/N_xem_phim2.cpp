/*
Author: Ngo Quang Huy
Problem: N - xem phim 2
Solution: Goi L[i][j] tong khoi luong bo lon nhat ma John co the mang di
xem phim khi co i con bo va suc chua cua xe la j
- neu a[i] <= j thi L[i,j] = max(L[i-1][j], L[i-1][j-a[i]] + a[i])
- neu a[i] > j thi L[i][j] = L[i-1][j]
*/
#include<iostream>

using namespace std;

int l[101][25005];
int a[101];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int c, n;
	cin >> c >> n;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	for(int i = 1; i <= n; i++){
		for(int j = 0; j <= c; j++){
			l[i][j] = l[i-1][j];
			if(a[i] <= j){
				l[i][j] = max(l[i][j], l[i-1][j-a[i]]+a[i]);
			}
		}
	}
	cout << l[n][c];
	return 0;
}

