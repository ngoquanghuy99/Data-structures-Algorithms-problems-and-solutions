#include<iostream>
#include<queue>
using namespace std;
int main(){
	int time, a;
	cin>>time;
	while(time--){
		queue<long long> q;
		cin>>a;
		q.push(9);
		while(1){
			long long temp = q.front();q.pop();
			if(temp % a == 0){
				cout<<temp<<endl;
				break;
			}
			q.push(temp*10);
			q.push(temp*10 + 9);
		}
	}
}
