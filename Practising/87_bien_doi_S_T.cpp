#include<bits/stdc++.h>
#define ii pair<int, int>
#define fi first
#define se second
using namespace std;
int minStep(int s, int t){
	set<int> vis;
	vis.insert(s);
	ii a;
	a.fi=s;
	a.se=0;
	queue<ii> Q;
	Q.push(a);
	while(!Q.empty()){
		ii u = Q.front();Q.pop();
		if(u.fi==t)
			return u.se;
		if(u.fi-1==t || u.fi*2 == t)
			return u.se+1;
		if(vis.find(u.fi-1)==vis.end()){
			Q.push({u.fi-1,u.se+1});
			vis.insert(u.fi-1);
		}
		if(vis.find(u.fi*2)==vis.end() && u.fi < t){ // lon hon thi ko them 2*
			Q.push({u.fi*2,u.se+1});
			vis.insert(u.fi*2);
		}
			
	}
}
int main(){
	int t;
	cin>>t;
	while(t--){
		int S, T;
		cin>>S>>T;
		cout<<minStep(S,T)<<endl;
	}
	return 0;
}

