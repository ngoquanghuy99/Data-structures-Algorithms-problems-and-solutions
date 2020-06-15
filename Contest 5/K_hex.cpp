#include<iostream>
#include<queue>
#include<cmath>
using namespace std;
class HEX{
	public:
	int a[10];
	HEX left(){
		HEX rs;
		rs.a[0] = a[3];
		rs.a[1] = a[0];
		rs.a[2] = a[2];
		rs.a[3] = a[7];
		rs.a[4] = a[4];
		rs.a[5] = a[1];
		rs.a[6] = a[6];
		rs.a[7] = a[8];
		rs.a[8] = a[5];
		rs.a[9] = a[9];
		return rs;
	}
	HEX right(){
		HEX rs;
		rs.a[0] = a[0];
		rs.a[1] = a[4];
		rs.a[2] = a[1];
		rs.a[3] = a[3];
		rs.a[4] = a[8];
		rs.a[5] = a[5];
		rs.a[6] = a[2];
		rs.a[7] = a[7];
		rs.a[8] = a[9];
		rs.a[9] = a[6];
		return rs;
	}
	bool check(){
		if(a[0] != 1 || a[1] != 2 || a[2] != 3 || a[3] != 8 || a[4] != 0 || a[5] != 0 
		|| a[6] != 4 || a[7] != 7 || a[8] != 6 || a[9] != 5) return 0;
		return 1;
	}
};

void step(HEX u){
	if(u.check()){
		cout<<"0"<<endl;
		return;
	}
		queue< HEX> q;
		q.push(u);
		int count = 0;
		int hat = 0, done = 0;
		int time = q.size();
		while(time){
			count++;
			while(time--){
				u = q.front();
				q.pop();
			
				HEX temp1, temp2;
				temp1 = u.left();
				temp2 = u.right();
				q.push(temp1);
				q.push(temp2);
				if(temp1.check() || temp2.check()){\
					cout<<count<<endl;
					return;
				}
			}
			hat++;
			time = q.size();
		}
	

}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	HEX u;
	for(int i = 0; i < 10; i++) cin>>u.a[i];
	step(u);
}

