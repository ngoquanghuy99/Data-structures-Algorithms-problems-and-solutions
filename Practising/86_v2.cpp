#include <bits/stdc++.h>
using namespace std;
int n;
long long a=0;
string ans;
void bfs(){
    pair<string,int> x;
    list<pair<string,int> > q;
    q.push_back({"1",1});
    while(!q.empty()){
        x=q.front();
        a=x.second;
        if(a%n==0){
            ans=x.first;
            return;
        }
        x.second%=n;
        q.pop_front();
        q.push_back({x.first+"0",x.second*10});
        q.push_back({x.first+"1",x.second*10+1});
    }
}
int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        cin>>n;
        bfs();
        cout<<ans<<endl;
    }
	return 0;
}
