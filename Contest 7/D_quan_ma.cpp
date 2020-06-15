	#include<vector>
	#include <queue>
    #include<cstring>
    #include<iostream>
    #include<algorithm>
    using namespace std;
    #define rl(T) scanf("%lld",&T)
    #define ri(T) scanf("%d",&T)
    #define rs(T) scanf("%s",T)
    #define rc(T) scanf("%c",&T)
    #define loop(i,a,n) for(long long i=a;i<n;i++)
    #define loopn(i,a,n) for(long long i=1;i<=n;i++)
    #define ll long long
    int x[10]={0,-1,-1,-2,-2,2,2,1,1};
    int y[10]={0,-2,2,-1,1,-1,1,-2,2};
    using namespace std;
    int bfs(int a1,int b1,int a2,int b2){
         int moves[9][9],vis[9][9],m,n;
         pair<int,int>p1;
         queue< pair<int,int> >q;
         p1.first=a1;
         p1.second=b1;
         q.push(p1);
         memset(moves,0,sizeof moves);
         memset(vis,0,sizeof vis);
         vis[a1][b1]=0;
         while(!q.empty()){
             p1=q.front();
             q.pop();
             if(p1.first==a2 && p1.second==b2)
             return moves[a2][b2];
             for(int i=1;i<=8;i++){
                 m=p1.first+x[i],n=p1.second+y[i];
                 if(m>8 || m<1 || n>8 || n<1)
                 continue;
                 else{
                     vis[m][n]=1;
                     moves[m][n]=moves[p1.first][p1.second]+1;
                     q.push(make_pair(m,n));
                 }
             }
         }
    }
    int main(){
       char a1,a2;
       ll b1,b2,t;
       cin >> t;
       while(t--){
          cin>>a1>>b1>>a2>>b2;
          cout<<bfs(a1-'a'+1,b1,a2-'a'+1,b2)<<endl;
       } 
    } 
