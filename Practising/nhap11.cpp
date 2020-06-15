#include <iostream>
using namespace std;
int c, n, w[110], x[110], fopt, sum;

bool check(){
	sum = 0;
	for(int i = 1; i <= n; i++) sum += w[i]*x[i];
	return (sum <= c);
}

void Try(int i){
	for(int j = 0; j <=1; j++){
		x[i] = j;
		if(i==n){
			if(check()) fopt = sum > fopt ? sum : fopt;
		}
		else Try(i+1);
	}
}
int main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> c >> n; for(int i = 1; i <= n; i++) cin >> w[i];
	Try(1);
	cout << fopt << endl;
}
