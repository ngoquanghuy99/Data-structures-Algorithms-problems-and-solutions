/*
Problem Q: Dem so ao
Author: Ngo Quang Huy
Using DFS recursively
*/
#include <iostream>
using namespace std;
bool unused[10005];
bool init(){
	for(int i = 1; i <= 10005; i++)
		unused[i] = true;
}
char a[105][105];
int vertex[105][105];
int n, m; // n, m : ROW, COL
void input(){
	int stt = 0;
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			cin >> a[i][j];
			stt++;
			vertex[i][j] = stt;
		}
	}
}
int colnum[] = {-1, 0, 0, -1, -1, 1, 1, 1};
int rownum[] = {1, 1, 0, -1, -1, -1, 0, 1};

void DFS_recur(int r, int c){
	for(int i = 0; i < 8; i++){
		int X = c + colnum[i];
		int Y = r + rownum[i];
		if((X >= 1 && X <= m) && (Y >= 1 && Y <= n) && unused[vertex[Y][X]] && a[Y][X] == 'W'){
			unused[vertex[Y][X]] = false;
			DFS_recur(Y,X);
		} 	
	}
}

int main(){
	input();
	init();
	int dem = 0;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			if(a[i][j] == 'W' && unused[vertex[i][j]]){
				dem ++;
				unused[vertex[i][j]] = false;
				DFS_recur(i,j);
			}
		}
	}
	cout << dem << endl;
	return 0;
}
