#include<bits/stdc++.h>
using namespace std;
bool mrk[1000][1000];
int a[1000][1000];
int u[] = {-1,-1,-1,0,1,0,1,1};
int v[] = {-1, 1,0,-1,-1,1,0,1};
void bfs(int i,int j,int m, int n){
    mrk[i][j] = true;
    queue< pair<int,int> > q;
    q.push(make_pair(i,j));
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for(int k = 0 ; k < 8 ; k++){
            if(!mrk[x + u[k]][y + v[k]] && a[x + u[k]][y + v[k]] == 1 && x + u[k] >= 0 && x + u[k] <= m - 1 && y + v[k] >= 0 && y + v[k] <= n - 1 ){
                mrk[x + u[k]][y + v[k]] = 1;
                q.push(make_pair(x + u[k],y + v[k]));
            }
        }
    }
}
int main(){
	int t = 0;
	cin >> t;
	while (t--){
	    int m,n;
	    cin >> m >> n;
	    int i,j;
	    for(i = 0 ; i < m ; i++){
	        for(j = 0 ; j  < n ; j++){
	            cin >> a[i][j];
	            mrk[i][j] =false;
	        }
	    }
	    int connectedcomponents = 0;
	    for(i = 0 ; i < m ; i++){
	        for(j = 0 ; j < n ; j++){
	            if(!mrk[i][j] && a[i][j] == 1){
	            bfs(i,j,m,n);
	            connectedcomponents++;
	            }
	        }
	    }
	    cout<<connectedcomponents<<endl;
	}
    return 0;
}
