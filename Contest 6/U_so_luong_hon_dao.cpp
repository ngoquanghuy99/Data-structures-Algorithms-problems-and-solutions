#include <iostream>
#include <string>
#include <cstring>
int t, n, m;
using namespace std;
int a[1001][1001];
int iss(int a[][1001], int r, int c, bool visited[][1001]){
	// return if row, col are in range and the value is 1 && not visited
	return ((r >= 1 && r <= n) && (c >= 1 && c <= m) && a[r][c] && !visited[r][c]);
}
// DFS with only 8 adjacent vertices
void DFS(int a[][1001], int r, int c, bool visited[][1001]){
	static int rowN[] = {-1, -1, -1, 0, 0, 1, 1, 1};
	static int colN[] = {-1, 0, 1, -1, 1, -1, 0, 1};
	// mark this cell as visited
	visited[r][c] = true;
	// recursionn for all connected neighbors
	for(int k = 1; k <= 8; k++)
		if(iss(a, r + rowN[k], c + colN[k], visited))
			DFS(a, r + rowN[k], c + colN[k], visited);
}
int counting(int a[][1001]){
	// create bool array to mark visited cells
	bool visited[1001][1001];
	memset(visited, false, sizeof(visited));
	int dem = 0;
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++){
			if(a[i][j] && !visited[i][j]){
				dem++;
				DFS(a,i,j,visited);
			}
		}
	return dem;
}
int main(){
	cin >> t;
	while (t--){
		cin >> n >> m;
		for(int i = 1; i <= n; i++)
			for(int j = 1; j <= m; j++)
				cin >> a[i][j];
		cout << counting(a) << endl;
	}
	return 0;
}
