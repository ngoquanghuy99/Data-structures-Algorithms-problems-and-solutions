#include <iostream>
#include <vector>
#include <algorithm>
#define FOR(i,a,b) for(int i = a; i <= b; i++)
using namespace std;

const int Max  = 1001;
int n, A[Max][Max];
vector < vector <int> > adj(Max);

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n;
	int m = 0;
	FOR(i,1,n) FOR(j,1,n){
		cin >> A[i][j];
		if(A[i][j] == 1 && i > j){
			adj[i].push_back(j);
			adj[j].push_back(i);
		}
	}
	FOR(i,1,n){
		FOR(j,0,adj[i].size()-1){
			cout << adj[i][j] << " ";
		}
		cout << endl;
	}
	
	
}
