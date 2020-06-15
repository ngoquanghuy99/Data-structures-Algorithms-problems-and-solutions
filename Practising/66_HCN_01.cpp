#include<bits/stdc++.h>
int n, m, h[1001][1001] , L[1001], R[1001] , maxx= 0;

using namespace std;

int main(){
	int t;
	cin>>t;
	while(t--){
		int x;
		stack<int> s;
		cin>>n>>m;
		
		for(int i=1;i<=m;i++)
			h[0][i]=0;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++){
				cin>>x;
				h[i][j]= (x) ? h[i-1][j] +1 : 0 ; 
			}
	
		for(int i=1;i<=n;i++){
			s.push(0);
			for(int j=1;j<=m;j++){
				while(s.size()>1 && h[i][s.top()] >= h[i][j]){
					R[s.top()]=j-1;
					s.pop();
				}
				L[j]= s.top()+1;
				s.push(j);
			}
			while(!s.empty()){
				R[s.top()]= m;
				s.pop();
			}
			for(int j=1;j<=m;j++)
				if(h[i][j]!=0)
					maxx=max(maxx,(R[j]-L[j]+1)*h[i][j]);
		}
		cout<<maxx<<endl;
	}
	return 0;
}

