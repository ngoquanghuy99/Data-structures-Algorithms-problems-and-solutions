#include<iostream>
using namespace std;
int money, n, a[31], check[31], dem = 10000, sum = 0, temp = 0;
void Try(int i){
	for(int j = 0; j <= 1; j++){
		check[i] = j;
		sum += a[i]*check[i];
		temp += check[i];
		if(i == n - 1){
			if(sum == money){
				if(temp < dem) dem = temp;
				if(dem == 1) return;
			}
		}else if(temp < dem) Try(i + 1);
		sum -= a[i]*check[i];
		temp -= check[i];
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n>>money;
	for(int i = 0; i < n ; i++) cin>>a[i];
	Try(0);
	cout<<dem<<endl;
}
