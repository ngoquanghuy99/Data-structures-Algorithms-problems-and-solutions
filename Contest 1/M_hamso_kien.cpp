#include<iostream>
using namespace std;
long long cal(long long x, long long y){
	if (x == 0 && y == 0) return 0;
	if (x % 3 == 0 && y % 2 == 0) return cal(x/3, y/2);
	if (x % 3 == 1 && y % 2 == 0) return cal(x/3, y/2) + 1;
	if (x % 3 == 2 && y % 2 == 0) return cal(x/3, y/2);
	if (x % 3 == 0 && y % 2 == 1) return cal(x/3, y/2) + 1;
	if (x % 3 == 1 && y % 2 == 1) return cal(x/3, y/2) + 2;
	if (x % 3 == 2 && y % 2 == 1) return cal(x/3, y/2) + 1;
}
int main(){
	long long time, x, y;
	cin>>time;
	while(time--){
		cin>>x>>y;
		cout<<cal(x,y)<<endl;
	}
}
