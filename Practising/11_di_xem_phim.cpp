// xem phim 1
// y tuong: giong bai cai tui tuy nhien chi co 1 tham so la can nang w[i], kiem tra t/m khong thi cap nhat tong can nang

#include <iostream>
using namespace std;

int w[30], x[30], fopt, sum, c, n;

bool check_weight(){
	sum = 0;
	for(int i = 1; i <= n; i++) sum += w[i]*x[i];
	return (sum <= c);
}
void Try(int i){
	for(int j = 0; j <= 1; j++){
		x[i] = j;
		if(i == n){
			if(check_weight()){
				fopt = sum > fopt ? sum : fopt;
			}
		}
		else Try(i+1);
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> c >> n;
	for(int i = 1; i <= n; i++) cin >> w[i];
	Try(1);
	cout << fopt << endl;
}
