#include <iostream>
using namespace std;
int n, a[110], xuoi[110], nguoc[110], x[110];
int dem = 0;
void Try(int i){
	for(int j = 1; j <= n; j++){
		if(a[j] && xuoi[i-j+n] && nguoc[i+j-1]){
			a[j] = xuoi[i-j+n] = nguoc[i+j-1] = false;
			x[i] = j;
			if(i==n) dem++;
			else Try(i+1);
			a[j] = xuoi[i-j+n] = nguoc[i+j-1] = true;
		}
	}
}
int main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n;
	for(int i = 1; i <= n; i++) a[i] = true;
	for(int i = 1; i <= 2*n-1; i++){
		xuoi[i] = true;
		nguoc[i] = true;
	}
	Try(1); cout << dem;
}
