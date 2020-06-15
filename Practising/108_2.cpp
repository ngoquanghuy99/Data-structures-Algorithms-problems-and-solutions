#include <vector>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

const int N = 100005;


void visit(int u, int p, int CriticalEdge, int Low[], int Num[], int Time, vector<vector<int> > a, bool CriticalNode[]) {
    int NumChild = 0;
    Low[u] = Num[u] = ++Time;
    for (int i=0; int v=a[u][i]; i++)
    if (v!=p) {
        if (Num[v]!=0)
            Low[u] = min(Low[u], Num[v]);
        else {
            visit(v, u, CriticalEdge, Low, Num, Time, a, CriticalNode);
            NumChild++;
            Low[u] = min(Low[u], Low[v]);
            
            if (Low[v] >= Num[v]) 
                CriticalEdge++;
            
            if (u==p) {
                if (NumChild >= 2) 
                CriticalNode[u] = true;
            } else {
                if (Low[v] >= Num[u]) 
                CriticalNode[u] = true;
            }
        }
    }
}
void display(vector<int> art){
	int siz = art.size();
	if(siz == 0){
		cout << 0 << endl;
		return;
	}
	cout << siz << endl;
	for(int i = 0; i < art.size(); i++) cout << art[i] << " ";
	cout << endl;
}
main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t = 0; cin >> t;
	while (t--){
		vector<vector<int> > a(1005);
		int n, m; bool CriticalNode[1005];
		memset(CriticalNode, false, sizeof CriticalNode);
		int CriticalEdge = 0;
		int Num[1005] = {0}, Low[1005] = {0}; int Time = 0;
	    scanf("%d%d", &n, &m);
	    for (int i=1; i<=m; i++) {
	        int x, y;
	        scanf("%d%d", &x, &y);
	        a[x].push_back(y);
	        a[y].push_back(x);
	    }
	    for (int i=1; i<=n; i++)
	        a[i].push_back(0);
	    for (int i=1; i<=n; i++)
	        if (!Num[i]) visit(i, i, CriticalEdge, Low, Num, Time, a, CriticalNode);
	    vector<int> art;
	 //   art.clear();
	    int Count = 0;
	    for (int i=1; i<=n; i++)
	        if (CriticalNode[i]) art.push_back(i);
	 	display(art);
	}
}
