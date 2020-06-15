#include <iostream>
#define i64 long long
#define FOR(i,a,b) for(int i=a; i<=b; i++)
using namespace std;
i64 c, n, w[17], fopt, x[17], sum;
bool check_weight(){
	sum = 0;
	FOR(i,1,n) sum += x[i]*w[i];
	return (sum <= c);
}
void Try(int i){
	FOR(j,0,1){
		x[i] = j;
		if(i==n){
			if(check_weight()==true){
				fopt = sum > fopt ? sum : fopt;
			}
		}
		else Try(i+1);
	}
	
}
int main() {
	// your code goes here
	cin >> c >> n;
	FOR(i,1,n) cin >> w[i];
	Try(1); 
	cout << fopt;
	return 0;
}
