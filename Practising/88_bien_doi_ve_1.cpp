
#include<bits/stdc++.h>
#define i64 long long
#define ii pair<int,int>
#define fi first
#define se second
using namespace std;
i64 minStep(i64 n){
	set<int> visited;
	visited.insert(n);
	queue<ii> q;
	q.push(ii(n,0));
	while(!q.empty()){
		ii t= q.front();q.pop();
		if(t.fi==1)
			return t.se;
		if(t.fi-1==1)
			return t.se+1;
		if(visited.find(t.fi-1)==visited.end())
			q.push(ii(t.fi-1,t.se+1));
		for(int i=2;i*i<=t.fi;i++)
			if(t.fi%i==0){
				if(visited.find(t.fi/i)==visited.end())
					q.push(ii(t.fi/i,t.se+1));
			}
	}
}
int main(){
	int t;
	cin>>t;
	while(t--){
		i64 n;
		cin>>n; 
		cout<<minStep(n)<<endl;
	}
	return 0;
}

//#include<bits/stdc++.h>
//#define i64 long long
//#define ii pair<int,int>
//#define fi first
//#define se second
//using namespace std;
//i64 minStep(i64 n){
//	set<int> vis;
//	vis.insert(n);
//	queue<ii> Q;
//	Q.push({n,0});
//	while(!Q.empty()){
//		ii u=Q.front(); Q.pop();
//		if(u.fi==1)
//			return u.se;
//		if(u.fi-1==1)
//			return u.se+1;
//		if(vis.find(u.fi-1)==vis.end())
//			Q.push({u.fi-1,u.se+1});
//		for(int i=2;i*i<=u.fi;i++)
//			if(u.fi%i==0){
//				if(vis.find(u.fi/i)==vis.end())
//					Q.push({u.fi/i,u.se+1});
//			}
//	}
//}
//int main(){
//	int t;
//	cin>>t;
//	while(t--){
//		i64 n;
//		cin>>n; 
//		cout<<minStep(n)<<endl;
//	}
//	return 0;
//}


