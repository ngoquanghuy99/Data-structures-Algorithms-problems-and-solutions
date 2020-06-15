#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
const int MXSIZE = 1e6+6;
 
 
int parent [MXSIZE];
int child  [MXSIZE];
int low    [MXSIZE];
int tym    [MXSIZE];
bool seen  [MXSIZE];
bool is_cut[MXSIZE];
 
vector <vector <int> > adj (MXSIZE); 
 
void dfs(int s){
  static int c=0;
  seen[s]=true;   
  low[s]=tym[s]=c++; 
  for(int i=0;i<adj[s].size();i++){
     int curr = adj[s][i];
     if(curr==parent[s])
      continue;         // do nothing if curr is its parent
  
    if(!seen[curr]){
 
      child[s]++; // one more independent child of s
      parent[curr]=s; 
      dfs(curr);
      low[s] = min(low[s] , low[curr]); 
      if(low[curr] >= tym[s])
        is_cut[s]=true;
 
    }
    else{
      low[s]= min(low[s],tym[curr]);
    }
 
 
  }
 
}
 
int main()
{	if(seen[1]) cout << "yes";
else cout << "no";
//  ios_base::sync_with_stdio(false);cin.tie(0);    
//      
//      int n,m;
//      cin>>n>>m; 
//      for(int i=1;i<=m;i++){
//          int a,b;
//          cin>>a>>b;
//          adj[a].push_back(b);
//          adj[b].push_back(a);
//      }
//       
//      parent[1]=-1;
//      dfs(1);
//      is_cut[1]= child[1]>1 ? true : false; 
// 
// 	  vector <int> art;
//      for(int i=1;i<=n;i++){
//        if(is_cut[i])
//          art.push_back(i);
//      }
//      for(int i = 0; i < art.size(); i++) cout << art[i] << " ";
//    return 0;
}
