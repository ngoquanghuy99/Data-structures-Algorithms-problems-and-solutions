#include<iostream>
using namespace std;
int n, w[26], fopt, x[26], c;
bool check_weight(){
	int sum = 0;
	for(int i=1; i<=n; i++)
		sum += w[i]*x[i];
	return (sum <= c);
}
int value(){
	int sum = 0;
	for(int i=1; i<=n; i++)
		sum += w[i]*x[i];
	return sum;
}
void Try(int i){
	for(int j=0; j<=1; j++){
		x[i] = j;
		if(i==n){
			if(check_weight()==true){
				int val = value();
				fopt = val > fopt ? val : fopt;
			}
		}
		else Try(i+1);
	}
}
int main(){
	cin >> c >> n;
	for(int i=1; i<=n; i++) cin >> w[i];
	Try(1);
	cout << fopt;
}
